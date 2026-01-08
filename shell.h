#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/*decla. of the global environment variable*/

extern char **environ;

/* Function Prototypes */
void simple_shell_loop(char *shell_name, char **envp);
void execute_command(char *command, char *shell_name, char **envp);

char **split_line(char *line);
char *get_full_path(char *command);

int check_builtins(char **args, char *line);
void handle_env(void);

int handle_builtin(char **args);
void free_args(char **args);

#endif /* SIMPLE_SHELL_H */
