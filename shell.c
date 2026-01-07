#include "shell.h"

/**
 * main - Simple shell with argument handling
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **argv = NULL;
	char *token;
	int i;
        int status;
	pid_t child_pid;

	while (1)
	{
/* display prompt if in interactive mode */
	  if (isatty(STDIN_FILENO))
              printf("#cisfun$ ");

	      nread = getline(&line, &len, stdin);
	  if (nread == -1) /* handle EOF (Ctrl+D) */
	    {
		free(line);
                if (argv)
                    free_argv(argv);
		exit(EXIT_SUCCESS);
	    }

/* rm newline character */
	  if (line[nread - 1] == '\n')
	     line[nread - 1] = '\0';

/* tokenize input into arguments */
	  i = 0;
            token = strtok(line, " ");
            while (token != NULL)
            {
              argv = realloc(argv, sizeof(char *) * (i + 2));
                if (!argv)
                 {
                   perror("realloc");
                   exit(EXIT_FAILURE);
                   }
              argv[i] = strdup(token); /*duplucate token*/
              i++;
              token = strtok(NULL, " ");

                }
           if (argv)
           argv[i] = NULL; /* null terminate array */


/* fofr skip empty input */
           if (!argv || !argv[0]
               continue;

 /* check for built-in commands */

           if (handle_builtin(argv))
             {
               argv = NULL;
               continue;
             }

 /* execute external command */

             {
	        child_pid = fork();
		if (child_pid == 0) /* child process */
	     {
	        if (execve(argv[0], argv, environ) == -1)
	     {
		perror("hsh");
		exit(EXIT_FAILURE);
		}
	     }
	        else if (child_pid > 0)/* parent process */
		     {
		       waitpid(child_pid, &status, 0);
                     }
                     else
                     {
		       perror("fork");

                     }

                 free_args(argv);
                 argv = NULL;

                 }

               free(line);
               if (argv)
                   free_args(argv);

               return (0);
}
