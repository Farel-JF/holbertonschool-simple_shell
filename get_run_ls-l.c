#include "shell.h"

/**
 * run_ls_l - Execute the 'ls -l' command.
 *
 * This function forks a new process and executes the 'ls -l' command
 * using execve. It waits for the execution to finish before returning.
 * If an error occurs during forking or execution, it prints an error
 * message and exits with failure.
 */
void run_ls_l(void)
{
	const char *const avs[] = {"/bin/ls", "-l", NULL};
	char *const envp[] = {NULL};
	int status;

	pid_t pid = get_fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve("/bin/ls", (char *const *)avs, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
