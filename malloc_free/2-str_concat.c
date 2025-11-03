#include <stdlib.h>
/**
 * str_concat - concatenates two strings
 * @s1: first string to concatenate
 * @s2: second string to concatenate
 *
 * Return: a pointer to the concatenated string, NULL if fails
 */
char *str_concat(char *s1, char *s2)
{
	char *con;
	unsigned int i, j, len1 = 0, len2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;

	while (s2[len2] != '\0')
		len2++;

	con = malloc(sizeof(char) * (len1 + len2 + 1));
	if (con == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
	{
		con[i] = s1[i];
	}

	for (j = 0; j < len2; j++)
	{
		con[i + j] = s2[j];
	}

	con[i + j] = '\0';

	return (con);
}
