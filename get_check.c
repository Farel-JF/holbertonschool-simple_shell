#include "shell.h"

/**
 * check_env - Check if a specified environment variable exists.
 * @variable: The environment variable to check.
 *
 * This function checks if the specified environment variable exists
 * in the current environment variables list. It returns true if found,
 * false otherwise.
 *
 * Return: 1 if the variable exists, 0 otherwise.
 */
int check_env(const char *variable)
{
	/*Récupérer la liste des variables d'environnement*/
	char **env;
	/*Parcourir la liste des variables d'environnement*/
	for (env = environ; *env != NULL; env++)
	{
	/*Chercher la variable spécifiée*/
	if (strncmp(*env, variable, strlen(variable)) == 0)
        {
		/*Si la variable est trouvée, retourner vrai (true)*/
	return (true);
	}
	}
	/*Si la variable n'est pas trouvée, retourner faux (false)*/
	return (false);
}
