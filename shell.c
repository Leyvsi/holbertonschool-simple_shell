#include "shell.h"

/**
 * main - main loop of a simple shell
 * @ac: argument count (unused)
 * @av: argument vector (used for argv[0] in errors if needed later)
 *
 * Return: status of the last executed command
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;
	int status = 0;
	unsigned int lnum = 0;

	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;
		lnum++;
		args = split_line(line);
		if (!args || !args[0])
		{
			free_args(args);
			continue;
		}

		if (handle_builtin(args))
		{
			free_args(args);
			continue;
		}
		status = exec_cmd(args, av[0], lnum);
		free_args(args);
	}
	free(line);
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	return (status);
}
