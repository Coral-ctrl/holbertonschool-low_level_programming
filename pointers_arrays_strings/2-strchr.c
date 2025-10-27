#include "main.h"
/**
 * _strchr - locates a character in a string
 * @s: string to check
 * @c: character to locate
 *
 * Return: pointer to occurrence to c, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}

	if (*s == c)
		return (s);

	return (0);
}
