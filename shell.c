#include "shell.h"

/**
 * main - Simple shell with argument handling
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **argv = NULL;
	char *token;
	int i;
	pid_t child_pid;
	int status;
	char *cmd_path;

	while (1)
	{
		/* display prompt if in interactive mode */
		if (isatty(STDIN_FILENO))
			printf("($) ");

		nread = getline(&line, &len, stdin);
		if (nread == -1) /* handle EOF (Ctrl+D) */
		{
			free(line);
			if (argv)
				free_args(argv);
			exit(EXIT_SUCCESS);
		}

		/* rm newline character */
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		/* tokenize input into arguments */
		i = 0;
		token = strtok(line, " ");
		while (token != NULL)
		{
			argv = realloc(argv, sizeof(char *) * (i + 2));
			if (!argv)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
			argv[i] = strdup(token); /*duplicate token*/
			i++;
			token = strtok(NULL, " ");
		}
		if (argv)
			argv[i] = NULL; /* null terminate array */

		/* for skip empty input */
		if (!argv || !argv[0])
			continue;

		/* check for built-in commands */
		if (handle_builtin(argv))
		{
			argv = NULL;
			continue;
		}

		cmd_path = get_full_path(argv[0]);
		if (cmd_path == NULL)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
			free_args(argv);
			argv = NULL;
			continue;
		}

		/* execute external command - ONLY FORK IF COMMAND EXISTS */
		child_pid = fork();
		if (child_pid == 0) /* child process */
		{
			if (execve(cmd_path, argv, environ) == -1)
			{
				perror("hsh");
				free(cmd_path);
				free_args(argv);
				exit(EXIT_FAILURE);
			}
		}
		else if (child_pid > 0) /* parent process */
		{
			waitpid(child_pid, &status, 0);
		}
		else
		{
			perror("fork");
		}

		free(cmd_path);
		free_args(argv);
		argv = NULL;
	}

	free(line);
	if (argv)
		free_args(argv);

	return (0);
}
