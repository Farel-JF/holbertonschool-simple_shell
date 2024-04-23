#include "shell.h"

int main(int ac, char *av[], char **env)
{
    int nb_cmd = 1, status = 0;
    char input[MAX_INPUT_LENGTH];

    /* Vérifier le mode interactif ou non */
    if (!isatty(STDIN_FILENO))
    {
        FILE *file = fopen(av[0], "r");
        if (file == NULL)
        {
            fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
            return (EXIT_FAILURE);
        }

        /* Lire les commandes à partir du fichier et les exécuter */
        while (fgets(input, MAX_INPUT_LENGTH, file) != NULL)
        {
            /*Remove trailing newline character*/
            input[strcspn(input, "\n")] = '\0';
            /*Execute the command*/
            execute_command(input);
            nb_cmd++;
        }

        fclose(file);
        return (status);
    }

    /* Mode interactif */
    while (1)
     {
        /* Afficher le prompt et lire l'entrée utilisateur */
        printf("cisfun$ ");
        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
        {
            if (feof(stdin))
            {
                break;
            }
             else
            {
                fprintf(stderr, "Erreur lors de la lecture de l'entrée.\n");
                return (EXIT_FAILURE);
            }
        }

        /* Enlever le caractère de nouvelle ligne en fin de ligne */
        input[strcspn(input, "\n")] = '\0';

        get_exit(input);
        /* Exécuter la commande entrée par l'utilisateur */
        execute_command(input);
        nb_cmd++;
    }

    (void)ac;
    (void)env;
    return (status);
}

