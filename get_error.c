#include "shell.h"

/**
 * _ferror - Check for error indicator on a stream
 * @stream: The stream to check
 *
 * This function checks if the error indicator is set on the specified stream.
 *
 * Return: 1 if the error indicator is set, 0 otherwise.
 */
int _ferror(FILE *stream)
{
  /*Check if the stream is NULL*/
  if (stream == NULL)
  {
    /* If the stream is NULL, return an error*/
    errno = EINVAL; /*Invalid argument*/
    return (1);
  }
  /* Check if the stream's file descriptor is invalid*/
  if (fileno(stream) == -1)
  {
    /* If the file descriptor is invalid, return an error*/
    errno = EBADF; /* Bad file descriptor*/
    return (1);
  }
  /*/ Check if errno is set*/
  if (errno != 0)
  {
    /*/If errno is set, return an error*/
    return (1);
  }
  /* If none of the above conditions are met, return 0 (no error)*/
  return (0);
}
