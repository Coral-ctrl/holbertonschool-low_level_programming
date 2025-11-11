#include <stdio.h>
#include <stdarg.h>
/**
 * print_all - prints anything
 * @format: types of arguments passed to the function
 *
 * Return: anything to be printed
 */
void print_all(const char * const format, ...)
{
	unsigned int i = 0;
	va_list args;
	char *str, *sep = "";

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == 'c' || format[i] == 'i' ||
		    format[i] == 'f' || format[i] == 's')
		{
			printf("%s", sep);

			switch (format[i])
			{
			case ('c'):
				printf("%c", va_arg(args, int));
				break;
			case ('i'):
				printf("%d", va_arg(args, int));
				break;
			case ('f'):
				printf("%f", va_arg(args, double));
				break;
			case ('s'):
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s", str);
				break;
			}

			sep = ", ";
		}
		i++;
	}

	printf("\n");
	va_end(args);
}
