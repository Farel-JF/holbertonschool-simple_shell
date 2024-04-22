#include "shell.h"

int main(int ac, char **av, char **env)
{
    int nb_cmd = 1, status = 0;

    if (!isatty(STDIN_FILENO)) /* vérifier le mode interactif ou non */
    {
        FILE *file = fopen(av[0], "r");
        if (file == NULL) {
            fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
            return EXIT_FAILURE;
        }
        get_not_interatif(file);
        fclose(file);
        return (status);
    }

    while (1)
    {
        get_interatif(av[0], env, &status);
        nb_cmd++;
    }
    (void)ac;
    return (status);
}
