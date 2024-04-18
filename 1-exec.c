#include <stdio.h>
#include <unistd.h>

extern char **environ; /*Accès aux variables d'environnement*/

int main() {
    char *args[] = {"/bin/ls", "-l", NULL};
    execve("/bin/ls", args, environ); /*Passage de l'environnement*/
    printf("Cette ligne ne sera pas exécutée car execve remplace le processus actuel.\n");
    return 0;
}
