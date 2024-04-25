#include "shell.h"

/**
 * _strcspn - Calculates the length of the initial segment of str
 * @str: The string to search.
 * @reject: The characters to exclude.
 *
 * Return: The length
 */
size_t _strcspn(const char *str, const char *reject)
{
	const char *p;
	const char *r;
	size_t count = 0;

	for (p = str; *p != '\0'; p++)
	{
		for (r = reject; *r != '\0'; r++)
		{
			if (*p == *r)
			{
				return (count);
			}
		}
		count++;
	}
	return (count);
}
