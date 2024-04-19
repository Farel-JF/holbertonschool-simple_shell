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

extern char **environ;

#define MAX_COMMAND_LENGTH 100
#define MAX_PATH_LENGTH 1024
#define MAX_COMMAND_WITH_PATH_LENGTH (MAX_PATH_LENGTH + MAX_COMMAND_LENGTH + 2)
#define MAX_ARGS 10

typedef int pid_t;

void execute_command(char *command);
char *find_command_in_path(const char *command, const char *path);
void exit_shell(const char *command);
int manage_command(char *command);
void manage_string(const char *input);
int manage_env(void);
void run_ls_l();
void choose_command(char *command);
int get_exceclp(const char *file, const char *arg0, ...);
char *_getenv(const char *name, char **env);
char *get_which(char *command, char **env);

#endif
