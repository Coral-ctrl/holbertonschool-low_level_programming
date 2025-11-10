#include "function_pointers.h"
#include <stddef.h>
/**
 * int_index - searches for an integer
 * @array: array of integers
 * @size: size of array
 * @cmp: pointer to function to be used to compare values
 *
 * Return: index of the first elem for which the cmp function doesn't return 0
 *         or -1 if no match is found or size <= 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL)
		return (-1);

	if (size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}

	return (-1);
}
