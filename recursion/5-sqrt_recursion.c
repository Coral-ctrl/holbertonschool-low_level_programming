/**
 * helper - recursively checks for natural square root
 * @n: number to find the square root of
 * @i: current number being tested
 *
 * Return: the natural square root, or -1 if none
 */
int helper(int n, int i)
{
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);
	return (helper(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to check
 *
 * Return: natural square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (helper(n, 0));
}
