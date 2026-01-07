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
	char *argv[1024];
	char *token;
	int i;
        int status;
	pid_t child_pid;

	while (1)
	{
		/* display prompt if in interactive mode */
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		nread = getline(&line, &len, stdin);
		if (nread == -1) /* handle EOF (Ctrl+D) */
		{
			free(line);
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
			argv[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		argv[i] = NULL; /* null terminate the array */

		/* execute command if input is not empty */
		if (argv[0] != NULL)
		{
			child_pid = fork();
			if (child_pid == 0) /* child process */
			{
				if (execve(argv[0], argv, environ) == -1)
				{
					perror("hsh");
					exit(EXIT_FAILURE);
				}
			}
			else /* parent process */
			{
				waitpid(child_pid, &status, 0);
			}
		}
	}
	free(line);
	return (0);
}
