#include "shell.h"

/**
 * exec_cmd - resolve path, fork, execve, and return status
 * @args: command arguments
 * @prog: argv[0] for error messages
 * @line: line number for error messages
 *
 * Return: exit status of the command (0, 126, 127, ...)
 */
int exec_cmd(char **args, char *prog, unsigned int line)
{
	pid_t pid;
	int status, rc;
	char *path = NULL;

	rc = resolve_path(args[0], &path);
	if (rc == 127)
		return (print_error(prog, line, args[0], "not found"), 127);
	if (rc == 126)
		return (print_error(prog, line, args[0], "Permission denied"), 126);

	free(args[0]);
	args[0] = path;

	pid = fork();
	if (pid == -1)
		return (perror("fork"), 1);

	if (pid == 0)
	{
		execve(args[0], args, environ);
		print_error(prog, line, args[0], "not found");
		_exit(127);
	}

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
