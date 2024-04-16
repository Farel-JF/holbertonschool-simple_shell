#include <stdio.h>
#include <unistd.h>

int main() {
    // Définition des arguments à passer au programme à exécuter
    char *args[] = {"ls", "-l", NULL};

    // Exécution de la commande "ls -l" en utilisant execve
    // Le premier argument est le chemin vers le programme à exécuter
    // Le deuxième argument est un tableau d'arguments passés au programme
    // Le troisième argument est un tableau d'environnement, que nous laisserons NULL pour utiliser l'environnement actuel
    execve("/bin/ls", args, NULL);

    // Si execve retourne, cela signifie qu'il y a eu une erreur
    perror("execve");
    return 1;
}
