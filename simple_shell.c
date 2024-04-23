#include "shell.h"

/**
 * main - Entry point of the shell program.
 * @ac: The number of arguments passed to the program.
 * @av: An array containing the arguments passed to the program.
 * @env: The environment variables.
 *
 * This function serves as the entry point of the shell program. It handles
 * the interactive mode where it displays a prompt, reads user input, and
 * executes commands entered by the user. It also handles error checking
 * and exiting the shell when requested by the user.
 *
 * Return: The exit status of the shell program.
 */

int main(int ac, char *av[], char **env)
{
	int nb_cmd = 1, status = 0;
	char input[MAX_INPUT_LENGTH];
	(void)av;

	/* Mode interactif */
	while (1)
	{
		if (isatty(STDIN_FILENO))
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

