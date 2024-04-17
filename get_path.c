#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

int main(int argc, char *argv[])
{
  char *path;
  char *token;

  if (argc < 2)
  {
    printf("Usage: %s filename ...\n", argv[0]);
    return 1;
  }

  path = getenv("PATH");
  if (path == NULL)
  {
    printf("PATH environment variable is not set.\n");
    return 1;
  }

  token = strtok(path, ":");

  while (token != NULL)
  {
    char filepath[MAX_PATH_LENGTH];
    snprintf(filepath, MAX_PATH_LENGTH, "%s/%s", token, argv[1]);

    if (access(filepath, F_OK) != -1)
    {
      printf("%s\n", filepath);
      return 0; // Stop searching after finding the first occurrence
    }

    token = strtok(NULL, ":");
  }

  printf("%s: command not found\n", argv[1]);
  return 1;
}
