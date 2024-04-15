#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int main(int ac, char **av)
{
    (void)ac;

    int i;
    char *line = NULL;
    size_t len = 0;
    ssize_t read

  while (1) 
  {
        printf("$ ");
        fflush(stdout); 

        read = getline(&line, &len, stdin);

        if (read == -1) {
           
            if (feof(stdin)) {
                
                printf("\nExiting...\n");
                break;
            } else {
                
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

       
        printf("%s", line);
    }

    for (i = 0; av[i] != NULL; i++)
    {
        printf("%s\n", av[i]);
    }

    free(line);
    return (0);
}


