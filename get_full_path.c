#include "shell.h"

/**
 * direct_check - check direct path status (exists, exec, directory)
 * @p: path to test
 *
 * Return: 0 if executable, 126 if permission/dir, 127 if not found
 */
static int direct_check(char *p)
{
	struct stat st;

	if (stat(p, &st) == 0 && S_ISDIR(st.st_mode))
		return (126);
	if (access(p, F_OK) != 0)
		return (127);
	if (access(p, X_OK) != 0)
		return (126);
	return (0);
}

/**
 * join_path - build "dir/cmd" string
 * @dir: directory
 * @cmd: command name
 *
 * Return: newly allocated string or NULL
 */
static char *join_path(char *dir, char *cmd)
{
	char *full;
	size_t n = strlen(dir) + strlen(cmd) + 2;

	full = malloc(n);
	if (!full)
		return (NULL);
	sprintf(full, "%s/%s", dir, cmd);
	return (full);
}

/**
 * resolve_path - resolve a command using PATH
 * @cmd: command name
 * @out: output resolved path (malloc'ed)
 *
 * Return: 0 if ok, 126 if found but not executable, 127 if not found
 */
int resolve_path(char *cmd, char **out)
{
	char *path, *copy, *dir, *full;
	int rc;

	*out = NULL;

	if (strchr(cmd, '/'))
		return ((*out = strdup(cmd)) ? direct_check(cmd) : 127);

	path = getenv("PATH");
	if (!path || !*path)
		return (127);

	copy = strdup(path);
	if (!copy)
		return (127);

	dir = strtok(copy, ":");
	while (dir)
	{
		if (*dir == '\0')
			dir = ".";
		full = join_path(dir, cmd);
		if (!full)
			break;
		rc = direct_check(full);
		if (rc == 0 || rc == 126)
			return (free(copy), *out = full, rc);
		free(full);
		dir = strtok(NULL, ":");
	}
	free(copy);
	return (127);
}
