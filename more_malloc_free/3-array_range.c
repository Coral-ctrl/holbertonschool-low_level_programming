#include <stdlib.h>
/**
 * array_range - creates an array of integers
 * @min: smallest int in array
 * @max: biggest int in array
 *
 * Return: a pointer to the newly created array
 */
int *array_range(int min, int max)
{
	int *ptr;
	int i, j = min;


	if (min > max)
		return (NULL);

	ptr = malloc(sizeof(int) * (max - min + 1));
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < (max - min + 1); i++)
	{
		ptr[i] = j;
		j++;
	}


	return (ptr);
}
