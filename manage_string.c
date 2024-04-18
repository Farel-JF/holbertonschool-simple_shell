#include "shell.h"

void manage_string(const char *input)
{
  printf("Length of input string: %lu\n", strlen(input));
  printf("Input string: %s\n", input);
}
#include "shell.h"

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

int main()
{
  char command_line[100];

  printf("Enter a command line: ");
  fgets(command_line, sizeof(command_line), stdin);

  command_line[strcspn(command_line, "\n")] = '\0';

  manage_all_argv_argc(command_line);

  return 0;
}
