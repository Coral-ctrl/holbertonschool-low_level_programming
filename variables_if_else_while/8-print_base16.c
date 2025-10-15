#include <stdio.h>
/**
 * main - prints all numbers of base 16 in lowercase
 *
 * Return: 0 on success
 */

int main(void)
{
	int c;

	for (c = 0; c < 16; c++)
		if (c < 10)
			putchar(c + '0');
		else
			putchar(c - 10 + 'a');
	putchar('\n');
	return (0);
}
