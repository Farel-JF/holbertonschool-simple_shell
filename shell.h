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
#include <errno.h>

extern char **environ;

#define MAX_COMMAND_LENGTH 100
#define MAX_PATH_LENGTH 1024
#define MAX_COMMAND_WITH_PATH_LENGTH (MAX_PATH_LENGTH + MAX_COMMAND_LENGTH + 2)
#define MAX_ARGS 10
#define MAX_INPUT_LENGTH 1024

typedef int pid_t;

int execute_command(char *command, char *env[]);
void get_exit(char *command);
char *_getenv(const char *name, char **env);
char *get_which(char *command, char **env);
int _execlp(const char *file, const char *arg, char *env[], ...);
int handle_eof(void);
void run_ls_l(void);
char *get_recup(char *fname, int numcount, char *cmd, const char *status);
int _execvp(const char *file, char *as[], char *env[]);
int check_env(const char *variable);
int _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
char *_fgets(char *str, int num, FILE *stream);
int _ferror(FILE *stream);
int _snprintf(char *str, size_t size, const char *format, ...);
size_t _strcspn(const char *str, const char *reject);

#endif
