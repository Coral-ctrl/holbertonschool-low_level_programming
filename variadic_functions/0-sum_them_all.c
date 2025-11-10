#include <stdarg.h>
/**
 * sum_them_all - returns the sum of all its parameters
 * @n: parameter to sum
 *
 * Return: sum of all parameters
 */
int sum_them_all(const unsigned int n, ...)
{
	int sum = 0;
	unsigned int i;

	va_list list;

	va_start(list, n);

	if (n == 0)
		return (0);

	for (i = 0; i < n; i++)
		sum += va_arg(list, int);

	va_end(list);

	return (sum);
}
