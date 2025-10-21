/**
 * _strncpy - copies a string
 * @dest: destination string
 * @src: the string to be copied
 * @n: the number of characters to be copied from source
 *
 * Return: result string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (src[i] != '\0' && i < n)
	{
		dest[j] = src[i];
		i++;
	}

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
