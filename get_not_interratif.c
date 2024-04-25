#include "shell.h"

#define MAX_LEN 1024 /* Maximum length of the command*/

char *get_non_interactive(int ac, char *av[])
{
  if (argc < 2)
  {
    fprintf(stderr, "Usage: %s <command>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  /*Allocate memory to store the command*/
  char *commande = (char *)malloc(MAX_LEN * sizeof(char));
  if (commande == NULL)
  {
    fprintf(stderr, "Memory allocation error\n");
    exit(EXIT_FAILURE);
  }

  // Concatenate command line arguments into a single string*/

  commande[0] = '\0';
  for (int i = 1; i < argc; i++)
  {
    strcat(commande, argv[i]);
    strcat(commande, " ");
  }

  // Remove the last space character*/
  if (strlen(commande) > 0)
  {
    commande[strlen(commande) - 1] = '\0';
  }

  return commande;
}
/*
int main(int argc, char *argv[]) {
    char* non_interactive_command = get_non_interactive(argc, argv);
    printf("Non-interactive command: %s\n", non_interactive_command);
    free(non_interactive_command); // Free allocated memory
    return 0;
}*/
