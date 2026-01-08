#include "shell.h"

/**
 * print_error - print a basic formatted error message to stderr
 * @prog: program name (argv[0])
 * @line: line number
 * @cmd: command name
 * @msg: error message
 *
 * Return: void
 */
void print_error(char *prog, unsigned int line, char *cmd, char *msg)
{
	char buf[32];
	int n;

	write(STDERR_FILENO, prog, strlen(prog));
	write(STDERR_FILENO, ": ", 2);
	n = sprintf(buf, "%u", line);
	write(STDERR_FILENO, buf, n);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, strlen(cmd));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, msg, strlen(msg));
	write(STDERR_FILENO, "\n", 1);
}
