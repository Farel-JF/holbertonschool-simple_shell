#ifndef _SHELL_H
#define _SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

#define MAX_COMMAND_LENGTH 100
#define MAX_PATH_LENGTH 1024
#define MAX_COMMAND_WITH_PATH_LENGTH (MAX_PATH_LENGTH + MAX_COMMAND_LENGTH + 2)
#define MAX_ARGS 10
#define MAX_INPUT_LENGTH 1024

typedef int pid_t;

void execute_command(char *command);
void get_exit(char *command);
char *_getenv(const char *name, char **env);
char *get_which(char *command, char **env);
int get_execlp(const char *file, const char *arg, ...);
int handle_eof();
void run_ls_l();
char *get_recup(char *fname, int numcount, char *cmd, const char *status);

#endif
