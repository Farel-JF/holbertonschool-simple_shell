#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello world, how are you?";
    char *token;

    // Get the first token
    token = strtok(str, " ");

    // Iterate through other tokens
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}
