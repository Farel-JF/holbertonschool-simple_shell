#include "shell.h"

/**
 * my_snprintf - Formatted output to a string.
 * @str: Pointer to the buffer where the resulting C-string is stored.
 * @size: Maximum number of bytes to be used in the buffer.
 * @format: C string that contains a format string.
 *
 * Return: The number of characters written if successful,
 *         a negative value if an error occurred.
 */
int _snprintf(char *str, size_t size, const char *format, ...)
{
  va_list args;
  int ret;

  va_start(args, format);
  ret = vsnprintf(str, size, format, args);
  va_end(args);

  return (ret);
}
