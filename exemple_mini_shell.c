#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];
    char *token;

    while (1) {
        /* Affichage du prompt*/
        printf("MiniShell> ");
        fflush(stdout);

        /*Lecture de la commande*/
        fgets(command, sizeof(command), stdin);

        /*Suppression du caractère de nouvelle ligne à la fin de la commande*/
        if ((strlen(command) > 0) && (command[strlen(command) - 1] == '\n')) {
            command[strlen(command) - 1] = '\0';
        }

        /*Découpage de la commande en tokens*/
        token = strtok(command, " ");
        int i = 0;
        while (token != NULL && i < MAX_ARGS - 1) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        /*Création d'un processus enfant*/
        pid_t pid = fork();

        if (pid < 0) {
            /*Échec de création du processus enfant*/
            perror("Erreur de fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            /*Code exécuté par le processus enfant*/
            /*Exécution de la commande*/
            execvp(args[0], args);

            /*En cas d'échec de l'exécution de la commande*/
            perror("Erreur d'exécution");
            exit(EXIT_FAILURE);
        } else {
            /*Code exécuté par le processus parent*/
            int status;
            /*Attente de la fin du processus enfant*/
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
