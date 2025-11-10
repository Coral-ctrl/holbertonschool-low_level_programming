#include "function_pointers.h"
#include <stddef.h>
/**
 * array_iterator - exec a function given as a param on each element of array
 * @array: array of integers
 * @size: size of array
 * @action: pointer to function to be executed
 *
 * Return: nothing
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
