#include "shell.h"

/**
 * get_path - Get PATH environment variable
 *
 * Return: PATH string or NULL
 */
static char *get_path(void)
{
	int i = 0;

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
		i++;
	}
	return (NULL);
}

/**
 * get_full_path - Find command in PATH
 * @command: Command to find
 *
 * Return: Full path to command or NULL if not found
 */
char *get_full_path(char *command)
{
	char *path, *path_copy, *dir, *full_path;
	struct stat st;

	/* If command has '/', check if it exists as-is */
	if (strchr(command, '/'))
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		return (NULL);
	}

	/* Get PATH */
	path = get_path();
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	/* Search in PATH directories */
	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", dir, command);

		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
