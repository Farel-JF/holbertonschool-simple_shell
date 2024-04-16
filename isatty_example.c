#include <stdio.h>
#include <unistd.h>

int main() {
    if (isatty(STDIN_FILENO)) {
        printf("stdin est un terminal interactif.\n");
    } else {
        printf("stdin n'est pas un terminal interactif.\n");
    }
    
    if (isatty(STDOUT_FILENO)) {
        printf("stdout est un terminal interactif.\n");
    } else {
        printf("stdout n'est pas un terminal interactif.\n");
    }

    return 0;
}
