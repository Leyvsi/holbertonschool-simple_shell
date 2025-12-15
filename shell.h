#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include
#include

/* Function Prototypes */
void simple_shell_loop(char *shell_name, char **envp);
void execute_command(char *command, char *shell_name, char **envp);

#endif /* SIMPLE_SHELL_H */
