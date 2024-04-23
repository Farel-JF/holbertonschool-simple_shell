#include "shell.h"

int handle_eof()
{
    if (feof(stdin))
	{
        exit(EXIT_SUCCESS);
    }
    return (0);
}
