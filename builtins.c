#include "shell.h"

/**
 * handle_builtin - handle simple built-in commands
 * @args: parsed arguments
 *
 * Return: 1 if a built-in was executed, 0 otherwise
 */
int handle_builtin(char **args)
{
	if (!args || !args[0])
		return (0);

	if (strcmp(args[0], "exit") == 0)
		exit(0);

	return (0);
}
