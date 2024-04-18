#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_CMD_LENGTH 256

// Function to tokenize input command
void tokenize_command(char *command, char *args[]) {
    char *token = strtok(command, " ");
    int i = 0;
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL; // Null-terminate the argument list
}

// Function to check if a command exists in a given directory
int command_exists(char *command, char *path) {
    char cmd_path[MAX_PATH_LENGTH];
    snprintf(cmd_path, MAX_PATH_LENGTH, "%s/%s", path, command);
    return access(cmd_path, F_OK) != -1;
}

// Function to search for command in PATH and execute it
void execute_command(char *args[], char *path[]) {
    int i = 0;
    while (path[i] != NULL) {
        if (command_exists(args[0], path[i])) {
            execv(path[i], args);
            // execv only returns if an error occurs
            perror("execv");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    printf("Command not found: %s\n", args[0]);
}

int main() {
    char *path[] = {"directory1", "directory2", NULL}; // Example PATH directories
    char command[MAX_CMD_LENGTH];
    char *args[MAX_CMD_LENGTH];
    
    while (1) {
        printf("$ ");
        fgets(command, MAX_CMD_LENGTH, stdin);
        // Remove trailing newline character
        command[strcspn(command, "\n")] = '\0';
        
        tokenize_command(command, args);
        
        if (args[0] == NULL) continue; // Empty command, prompt again
        
        if (strcmp(args[0], "exit") == 0) {
            // Handle exit command
            break;
        }
        
        execute_command(args, path);
    }
    
    return 0;
}

