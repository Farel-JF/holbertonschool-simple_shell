#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_PATH_LENGTH 1024 // Taille maximale du chemin
#define MAX_COMMAND_WITH_PATH_LENGTH (MAX_PATH_LENGTH + MAX_COMMAND_LENGTH + 2)

void execute_command(char *command) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Processus enfant
        if (execlp(command, command, NULL) == -1) {
            perror("execlp");
            exit(EXIT_FAILURE);
        }
    } else {
        // Processus parent
        int status;
        waitpid(pid, &status, 0);
    }
}

int main(int argc, char *argv[]) {
    char command[MAX_COMMAND_LENGTH];
    char command_with_path[MAX_COMMAND_WITH_PATH_LENGTH];
    char *token;
    int arg_count = 0;
    char *path;

    path = getenv("PATH");

    if (path == NULL) {
        fprintf(stderr, "Error : PATH environment variable not set\n");
        return (EXIT_FAILURE);
    }

    while (1) {
        printf("cisfun$ ");

        if (fgets(command, sizeof(command), stdin) == NULL) {
            if (feof(stdin)) {
                printf("^C\n");
                break;
            } else {
                perror("fgets");
                exit(EXIT_FAILURE);
            }
        }

        // Supprimer le caractère de nouvelle ligne
        command[strcspn(command, "\n")] = '\0';

        token = strtok(command, " ");
        arg_count = 0;

        while (token != NULL) {
            arg_count++;
            token = strtok(NULL, " ");
        }

        if (arg_count == 0) {
            // Commande vide
            continue;
        }

        // Exécuter la commande directement
        execute_command(command);

        // Vérifier si la commande existe dans le PATH
        char *path_token = strtok(path, ":");
        while (path_token != NULL) {
            snprintf(command_with_path, sizeof(command_with_path), "%s/%s", path_token, command);
            // Vérifier si la sortie de snprintf est tronquée
            if (strlen(command_with_path) >= sizeof(command_with_path)) {
                fprintf(stderr, "Error: Command path too long\n");
                break;
            }
            if (access(command_with_path, X_OK) != -1) {
                execute_command(command_with_path);
                break;
            }
            path_token = strtok(NULL, ":");
        }

        if (path_token == NULL) {
            fprintf(stderr, "Error: Command not found\n");
        }
    }
    return 0;
}

/*gcc - Wall - Werror - pedantic path_shell.c - o path_shell*/
