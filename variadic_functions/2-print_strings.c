#include <stdio.h>
#include <stdarg.h>
/**
 * print_strings - prints strings
 * @separator: the string to be printed between strings
 * @n: the number of strings passed to the function
 *
 * Return: printed strings
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list args;
	char *str;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);

		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);

		if (separator != NULL && i < n - 1)
			printf("%s", separator);
	}

	printf("\n");
	va_end(args);
}
