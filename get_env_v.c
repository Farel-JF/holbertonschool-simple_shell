int main(void) {
    char *path = _getenv("PATH");
    if (path != NULL) {
        printf("PATH = %s\n", path);
    } else {
        printf("PATH environment variable not found.\n");
    }

    return 0;
}