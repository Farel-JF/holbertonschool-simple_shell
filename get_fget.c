#include "shell.h"

/**
 * _fget - Custom implementation of fgets.
 * @str: Pointer to the destination buffer.
 * @num: Maximum number of characters to read.
 * @stream: Pointer to the FILE object representing the stream to read from..
 *
 * Return: Pointer to the destination buffer on success, or NULL on failure.
 */
char *_fgets(char *str, int num, FILE *stream)
{
  char *result = _fgets(str, num, stream);

  /* Check if EOF was reached or there was an error during reading */
  if (result == NULL && feof(stream))
  {
    /* EOF reached */
    printf("EOF reached\n");
  }
  else if (result == NULL && ferror(stream))
  {
    /* Error during reading */
    printf("Error reading input\n");
  }

  return (result);
}
