#include <stdio.h>
/**
 * main - prints single digit numbers of base 10
 *
 * Return: 0 on success
 */

int main(void)
{
	int c;

	for (c = 0; c < 10; c++)
		printf("%d", c);
	putchar("\n");
	return (0);
}
