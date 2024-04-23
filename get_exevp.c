#include "shell.h"

int get_execvp(const char *file, char *const argv[])
{
    /*Obtenir le contenu de la variable d'environnement PATH*/
    char *path = getenv("PATH");
    if (path == NULL)
    {
        fprintf(stderr, "Variable d'environnement PATH non trouvée.\n");
        return -1;
    }

    /*Copie du chemin d'accès dans un tampon pour éviter la modification de la chaîne d'origin*/
    char path_copy[strlen(path) + 1];
    strcpy(path_copy, path);

    /*Boucle |  travers chaque chemin dans PAT*/
    char *token = strtok(path_copy, ":");
    while (token != NULL)
    {
        /*Construire le chemin complet de l'exécutabl*/
        char full_path[strlen(token) + strlen(file) + 2]; /*+2 pour / et \0*/
        sprintf(full_path, "%s/%s", token, file);

        /*Essayer d'exécuter l'exécutable avec exe*/
        execv(full_path, argv);

        /*Si execv réussit, cette ligne ne sera jamais atteinte*/
        /*Si execv échoue, essayez le prochain chemin dans PATH*/
        token = strtok(NULL, ":");
    }
    /*Si aucun exécutable correspondant n'est trouvé dans aucun des chemins de PAT*/
    fprintf(stderr, "Impossible de trouver l'exécutable '%s' dans le PATH.\n", file);
    return -1;
}
