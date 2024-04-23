#include "shell.h"

char *get_recup(char *fname, int numcount, char *cmd, const char *status)
{
    char *result = malloc(numcount + strlen(status) + strlen(fname)
    + strlen (cmd) + 3);
    if (result == NULL) {
        perror("Allocation failed");
        return NULL;
    }
    strcpy(result, status);
    strcat(result, " ");
    strcat(result, fname);
    strcat(result, " ");
    strcat(result, cmd);
    return result;
}
