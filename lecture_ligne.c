#include <stdio.h>
#include <stdlib.h>

int main() {
    char *ligne = NULL;     // Pointeur vers la ligne lue
    size_t taille = 0;      // Taille initiale du tampon
    ssize_t longueur;       // Longueur de la ligne lue

    printf("Veuillez entrer une ligne de texte :\n");

    // Utilisation de getline pour lire une ligne depuis l'entrée standard
    longueur = getline(&ligne, &taille, stdin);

    if (longueur != -1) {
        printf("Vous avez entré : %s", ligne);
    } else {
        printf("Erreur lors de la lecture de la ligne.");
    }

    // Libération de la mémoire allouée pour stocker la ligne
    free(ligne);

    return 0;
}
