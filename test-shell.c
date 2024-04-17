#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 100

void execute_command(char *command) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
    } else if (pid == 0) { // Processus enfant
        // Exécuter la commande
        if (execlp(command, command, NULL) == -1) {
            // Vérifier si le fichier existe ou si c'est une erreur de permission
            if (errno == ENOENT) {
                printf("No such file or directory: %s\n", command);
            } else {
                perror("execlp");
            }
            exit(EXIT_FAILURE);
        }
    } else { // Processus parent
        // Attendre que le processus enfant termine
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    printf("Bienvenue dans le Shell Simple!\n");

    while (1) {
        printf("#cisfun$ ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            printf("\nFermeture du shell...\n");
            break;
        }
        // Supprimer le caractère de nouvelle ligne s'il est présent
        command[strcspn(command, "\n")] = '\0';

        // Quitter le shell si "exit" est saisi
        if (strcmp(command, "exit") == 0) {
            printf("Fermeture du shell...\n");
            break;
        }

        // Exécuter la commande
        execute_command(command);
    }

    return 0;
}
