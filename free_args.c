#include "shell.h"

/**
 * free_args - frees argument array
 * @args: arguments
 */
void free_args(char **args)
{
	int i = 0;

	if (!args)
		return;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
