#include <stdio.h>
#include <stdlib.h>

extern char **environ;

char *_getenv(const char *name) {
    char **env = environ;

    // Iterate through the environ array
    while (*env != NULL) {
        char *current_var = *env;
        // Compare the variable name with the desired name
        if (strncmp(current_var, name, strlen(name)) == 0 && current_var[strlen(name)] == '=') {
            // Return the value part of the variable
            return current_var + strlen(name) + 1;
        }
        env++;
    }

    // Variable not found
    return NULL;
}

int main(void) {
    char *path = _getenv("PATH");
    if (path != NULL) {
        printf("PATH = %s\n", path);
    } else {
        printf("PATH environment variable not found.\n");
    }

    return 0;
}