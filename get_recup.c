#include "shell.h"

char *get_recup(char *fname, int numcount, char *cmd, const char *status)
{
    char *result = malloc(numcount * sizeof(char));
    if (result == NULL) {
        perror("Allocation failed");
        return NULL;
    }
    strncpy(result, status, numcount);
    result[numcount - 1] = '\0';
    strcat(result, " ");
    strcat(result, fname);
    strcat(result, " ");
    strcat(result, cmd);
    return result;
}
