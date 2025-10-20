/**
 * _strlen - returns the length of a string
 * @s: length to return
 *
 * Return: length of s
 */
int _strlen(char *s)
{
	int l = 0;

	while (s[l] != '\0')
		l++;
	return (l);
}
