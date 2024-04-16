#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Variable pour stocker l'ID du processus
    pid_t pid;

    // Création d'un nouveau processus
    pid = fork();

    // Vérification si le fork a réussi
    if (pid < 0) {
        // En cas d'échec du fork
        fprintf(stderr, "Le fork a échoué\n");
        return 1;
    } else if (pid == 0) {
        // Code exécuté par le processus fils
        printf("Je suis le processus fils (PID: %d)\n", getpid());
    } else {
        // Code exécuté par le processus parent
        printf("Je suis le processus parent (PID: %d)\n", getppid());

        // Attendre que le processus fils se termine
        wait(NULL);

        printf("Le processus fils s'est terminé\n");
    }

    return 0;
}
