#include "shell.h"
#include "shell.h"

/**
 * count_tokens - count words in a line using strtok on a copy
 * @s: input string
 *
 * Return: number of tokens
 */
static int count_tokens(char *s)
{
	int c = 0;
	char *tmp, *tok;

	tmp = strdup(s);
	if (!tmp)
		return (0);

	tok = strtok(tmp, " \t\r\n");
	while (tok)
	{
		c++;
		tok = strtok(NULL, " \t\r\n");
	}
	free(tmp);
	return (c);
}

/**
 * split_line - split a line into an array of strings
 * @line: input line
 *
 * Return: NULL-terminated array of strings, or NULL
 */
char **split_line(char *line)
{
	char **args;
	int n, i = 0;
	char *tok;

	n = count_tokens(line);
	if (n == 0)
		return (NULL);

	args = malloc(sizeof(char *) * (n + 1));
	if (!args)
		return (NULL);

	tok = strtok(line, " \t\r\n");
	while (tok)
	{
		args[i++] = strdup(tok);
		tok = strtok(NULL, " \t\r\n");
	}
	args[i] = NULL;
	return (args);
}

/**
 * free_args - free a NULL-terminated array of strings
 * @args: array to free
 *
 * Return: void
 */
void free_args(char **args)
{
	int i = 0;

	if (!args)
		return;

	while (args[i])
		free(args[i++]);
	free(args);
}
