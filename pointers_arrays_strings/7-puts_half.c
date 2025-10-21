#include "main.h"
/**
 * puts_half - prints half of a string
 * @str: string to print
 */
void puts_half(char *str)
{
	int i = 0, j;

	while (str[i] != '\0')
		i++;

	j = (i + 1) / 2;

	while (str[j] != '\0')
	{
		_putchar(str[j]);
		j++;
	}
	_putchar('\n');
}
