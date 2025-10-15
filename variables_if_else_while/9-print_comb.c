#include <stdio.h>
/**
 * main - prints combinations of single-digit numbers
 *
 * Return: 0 on success
 */

int main(void)
{
	int c;

	for (c = 0; c < 10; c++)
	{
		putchar(c + '0');
		if (c < 9)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
