#include <stdio.h>
/**
 * print_array - prints n elements of an array of integers
 * @a: array to check
 * @n: number of elements to print
 */
void print_array(int *a, int n)
{
	int i = 0;

	while (i <= n && a[i] != '\0')
	{
		printf("%d", a[i]);
		printf(",");

		if (i < n)
			printf(" ");

		i++;
	}
}
