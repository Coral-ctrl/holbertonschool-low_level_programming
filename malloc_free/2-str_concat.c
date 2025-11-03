#include <stdlib.h>
/**
 * _strdup - concatenates two strings
 * @s1: first string to concatenate
 * @s2: second string to concatenate
 *
 * Return: a pointer to the concatenated string, NULL if fails
 */
char *str_concat(char *s1, char *s2)
{
	char *con;
	unsigned int i = 0, j = 0, len1 = 0, len2 = 0;

	if (s1 == NULL || s2 == NULL)
		return (NULL);

	while (s1[len1] != '\0')
		len1++;

	while (s2[len2] != '\0')
		len2++;

	con = malloc(sizeof(char) * (len1 + len2 + 2));
	if (con == NULL)
		return (NULL);

	while (i < len1)
	{
		con[j] = s1[i];
		i++;
		j++;
	}

	for (i = 0; i < len2; i++)
	{
		con[j] = s2[i];
		j++;
	}

	con[j] = '\0';

	return (con);
}
