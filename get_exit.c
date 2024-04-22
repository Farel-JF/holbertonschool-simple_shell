#include "shell.h"

int get_exit(char *n)
{
  unsigned int nb = 0;

  if (!n)
    return (-2);

  for (; *n; n++)
  {
    if (*n < '0' || *n > '9')
      return (-1);

    nb = nb * 10 + (*n - '0');

    if (nb > 2147483648)
      return (-1);
  }

  while (nb > 255)
    nb -= 256;

  return (nb);
}
