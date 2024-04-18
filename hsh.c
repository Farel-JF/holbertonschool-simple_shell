#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Définir une taille de tampon pour stocker la commande
    char commande[1024];
    // Lire la commande depuis stdin
    if (fgets(commande, sizeof(commande), stdin) == NULL) {
        perror("Erreur lors de la lecture de la commande");
        return EXIT_FAILURE;
    }

    // Supprimer le caractère de nouvelle ligne à la fin de la commande
    commande[strcspn(commande, "\n")] = '\0';

    // Utiliser la fonction system() pour exécuter la commande
    int status = system(commande);
    if (status == -1) {
        perror("Erreur lors de l'exécution de la commande");
        return EXIT_FAILURE;
    } else if (status != 0) {
        fprintf(stderr, "%s: Erreur lors de l'exécution de la commande\n", argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

