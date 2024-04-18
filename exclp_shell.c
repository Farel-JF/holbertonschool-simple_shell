#include "shell.h"

int get_exceclp(const char *file, const char *arg0, ...)
{
  va_list args;
  int result;

  va_start(args, arg0);
  result = get_exceclp(file, arg0, args);
  va_end(args);

  return (result);
}
