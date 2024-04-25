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

int main(int ac, char *av[], char *env[])
{
	int nb_cmd = 1, status = 0;
	char input[MAX_INPUT_LENGTH];
	char check[] = "/bin/ls";
	(void)av;

	while (1)
	{
		if (isatty(STDIN_FILENO))
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
		input[strcspn(input, "\n")] = '\0';
		get_exit(input);
		status = execute_command(input, env);

		if (access(check, X_OK) != -1)
		{
			check_env(check);
		}
		else
		{
			printf("%s does not exist!\n", check);
		}
		nb_cmd++;
	}
	(void)ac;
	return (status);
}
