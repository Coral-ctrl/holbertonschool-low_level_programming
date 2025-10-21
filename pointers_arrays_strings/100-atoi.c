/**
 * _atoi - convert a string to an integer
 * @s: string to convert
 *
 * Return: integer value of the string
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int found_digit = 0;
	int result = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			found_digit = 1;
			while (s[i] >= '0' && s[i] <= '9')
			{
				result = (s[i] - '0') + result * 10;
				i++;
			}
			break;
		}
		i++;
	}

	if (found_digit == 0)
		return (0);
	else
		return (result * sign);
}
