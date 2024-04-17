#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define LONGUEUR_COMMANDE_MAX 100

void executer_commande(char *commande) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
    } else if (pid == 0) { // Processus enfant
        // Exécuter la commande
        if (execlp(commande, commande, NULL) == -1) {
            perror("execlp");
            exit(EXIT_FAILURE);
        }
    } else { // Processus parent
        // Attendre que le processus enfant termine
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char commande[LONGUEUR_COMMANDE_MAX];

    printf("Bienvenue dans le Shell Simple!\n");

    while (1) {
        printf("$ ");
        if (fgets(commande, sizeof(commande), stdin) == NULL) {
            printf("\nFermeture du shell...\n");
            break;
        }
        // Supprimer le caractère de nouvelle ligne s'il est présent
        commande[strcspn(commande, "\n")] = '\0';

        // Exécuter la commande
        executer_commande(commande);
    }

    return 0;
}
