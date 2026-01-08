#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/* parsing */
char **split_line(char *line);
void free_args(char **args);

/* builtins */
int handle_builtin(char **args);

/* path */
int resolve_path(char *cmd, char **out);

/* exec */
int exec_cmd(char **args, char *prog, unsigned int line);

/* errors */
void print_error(char *prog, unsigned int line, char *cmd, char *msg);

#endif
