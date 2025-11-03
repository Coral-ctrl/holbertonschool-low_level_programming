#include <stdlib.h>
/**
 * string_nconcat - concatenates two strings
 * @s1: first string to concatenate
 * @s2: second string to concatenate
 * @n: number of bytes in s2 to concatenate
 *
 * Return: a pointer to newly allocated space in memory
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *con;
	int i, j, len1 = 0, len2 = 0;


	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1])
		len1++;

	while (s2[len2])
		len2++;

	con = malloc(sizeof(char) * (len1 + n + 1));
	if (con == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
	{
		con[i] = s1[i];
	}

	if (n > (unsigned int)len2)
	{
		for (j = 0; j < len2; j++)
			con[i + j] = s2[j];
	}
	else
	{
		for (j = 0; j < (int)n; j++)
			con[i + j] = s2[j];
	}

	con[i + j] = '\0';

	return (con);
}
