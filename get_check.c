#include "shell.h"

int check_env(const char *variable) {
    /*Récupérer la liste des variables d'environnement*/
char **env;
    /*Parcourir la liste des variables d'environnement*/
    for (env = environ; *env != NULL; env++)
	{
        /*Chercher la variable spécifiée*/
        if (strncmp(*env, variable, strlen(variable)) == 0) {
            /*Si la variable est trouvée, retourner vrai (true)*/
            return (true);
        }
    }
    /*Si la variable n'est pas trouvée, retourner faux (false)*/
    return (false);
}
