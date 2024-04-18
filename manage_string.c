#include "shell.h"

void manage_string(const char *input)
{
  printf("Length of input string: %lu\n", strlen(input));
  printf("Input string: %s\n", input);
}

void manage_all_argv_argc(char *command_line)
{
  char *args[MAX_ARGS];
  int argc = 0;
  int i;

  char *token = strtok(command_line, " ");

  while (token != NULL && argc < MAX_ARGS)
  {
    args[argc++] = token;
    token = strtok(NULL, " ");
  }

  printf("Number of arguments: %d\n", argc);
  printf("Arguments:\n");
  for (i = 0; i < argc; i++)
  {
    printf("%d: %s\n", i, args[i]);
  }
}
