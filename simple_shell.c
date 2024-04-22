#include "shell.h"

int main(int ac, char *av[], char **env)
{
    FILE *file = fopen(av[0], "r");
    int nb_cmd = 1, status = 0;
    char input[MAX_INPUT_LENGTH];

    if (!isatty(STDIN_FILENO)) /* vérifier le mode interactif ou non */
    {
        file = fopen(av[0], "r");
        if (file == NULL) {
            fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
            return (EXIT_FAILURE);
        }
        fclose(file);
        return (status);
    }

     /* Buffer to store user input */
    while (1)
    {
        /*Display prompt and read user input*/
        printf("cisfun$ ");
        fgets(input, MAX_INPUT_LENGTH, stdin);

        /*Remove trailing newline character*/
        input[strcspn(input, "\n")] = '\0';

        /*Execute the command entered by the user*/
        execute_command(input); /*Corrected: Removed 'env' parameter*/
        nb_cmd++;
    }
    (void)ac;
    (void)env;
    return (status);
}
