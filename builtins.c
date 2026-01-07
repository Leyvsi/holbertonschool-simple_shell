#include "shell.h"

/**
 * handle_builtin - checks and executes built-in commands
 * @args: command arguments
 *
 * Return: 1 if built-in executed, 0 otherwise
 */
int handle_builtin(char **args)
{
	if (args[0] == NULL)
		return (1);

	if (strcmp(args[0], "exit") == 0)
	{
		free_args(args);
		exit(0);
	}

	return (0);
}
