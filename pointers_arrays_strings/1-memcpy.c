/**
 * _memcpy - copies memory area
 * @dest: target memory area
 * @src: source memory area
 * @n: number of bytes to copy
 *
 * Return: pointer to the memory area dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
