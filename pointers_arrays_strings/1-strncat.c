/**
 * _strncat - concatenates two strings
 * @dest: result string
 * @src: source string
 * @n: number of bytes to concatenate
 *
 * Return: concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	return (dest);
}
