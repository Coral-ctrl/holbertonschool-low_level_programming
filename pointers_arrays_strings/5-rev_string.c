/**
* rev_string - reverses a string
* @s: string to reverse
*/
void rev_string(char *s)
{
	int i = 0, j = 0;
	char n;

	while (s[i] != '\0')
		i++;
	i--;

	while (j < i)
	{
		n = s[i];
		s[i] = s[j];
		s[j] = n;
		i--;
		j++;
	}
}
