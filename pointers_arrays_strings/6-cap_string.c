/**
 * cap_string - capitalizes all words of a string
 * @str: string to check
 *
 * Return: capitalized string
 */
char *cap_string(char *str)
{
	int i = 0;
	int cap_next = 1;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z' && cap_next == 1)
		{
			str[i] -= 32;
			cap_next = 0;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
			cap_next = 0;
		else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			 str[i] == ',' || str[i] == ';' || str[i] == '.' ||
			 str[i] == '!' || str[i] == '?' || str[i] == '"' ||
			 str[i] == '(' || str[i] == ')' || str[i] == '{' ||
			 str[i] == '}')
			cap_next = 1;
		else
			cap_next = 0;
		i++;
	}

	return (str);
}
