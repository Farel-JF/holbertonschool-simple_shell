#include "shell.h"

void execute_command(char *command)
{
  pid_t pid;
  int status;


    pid = fork();

    if (pid == 0)
    {
      if (strcmp(command, "ls -l") == 0)
      {
       run_ls_l();
      }
      if (strcmp(command, "exit") == 0)
      {
      status = get_exit(command);
      status = handle_eof();
      exit(status);
      }
    }
    else if (pid == -1)
    {
      perror("fork");
      exit(EXIT_FAILURE);
    }
    else if (execlp(command, command, NULL) == -1)
    {
        fprintf(stderr, "./shell: No such file or directory\n");
        exit(EXIT_FAILURE);
      }
    else
    {
           waitpid(pid, &status, 0);
            exit(EXIT_SUCCESS);
    }


}

