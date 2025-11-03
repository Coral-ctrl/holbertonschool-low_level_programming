#include <stdlib.h>
/**
 * _calloc - allocates memory for an array
 * @nmemb: number of elements in the array
 * @size: number of bytes
 *
 * Return: a pointer to newly allocated space in memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *con;
	int i;


	if (nmemb == 0 || size == 0)
		return (NULL);

	con = malloc(size * nmemb);
	if (con == NULL)
		return (NULL);

	for (i = 0; i < (int)nmemb; i++)
	{
		con[i] = 0;
	}


	return (con);
}
