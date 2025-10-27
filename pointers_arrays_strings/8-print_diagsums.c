#include <stdio.h>
/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix of
 * integers
 * @a: array to check
 * @size: how many to sum up
 *
 * Return: sum
 */
void print_diagsums(int *a, int size)
{
	int i = 0, j = size - 1, sum_a = 0, sum_b = 0;

	while (i < size && j >= 0)
	{
		sum_a += *a[i][i];
		sum_b += *a[i][j];
		i++;
		j--;
	}
	printf("%d, %d", sum_a, sum_b);
}
