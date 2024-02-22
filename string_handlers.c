#include "main"

/**
 * _strcpy - copying a string
 * @dest: Input string
 * @src: another string
 * Return: pointer to new string
 */

char *_strcpy(char *dest, char *src)
{
	int x = 0;

	while (src[x] != '\0')
		dest[x] = src[x];
		x++;
	dest[x] = '\0';

	return (dest);
}

/**
 * _strdup - duplicating a string
 * @str: string to duplicate
 * Return: pointer to new string
 */

char *_strdup(const char *str)
{
	int x;
	int len = 0;
	char *ptr;

	if (str == NULL)
		return (NULL);
	while (str[len] != '\0')
		len++;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (x = 0; x <= len; x++)
		ptr[x] = str[x];
	return (ptr);
}

/**
 * _puts - printing a string
 * @str: input string
 * Return: nothing
 */

void _puts(char *str)
{
	while (*str != '\0')
		_putchar(*str);
		str++;
}

/**
 * _putchar - printing a character to stdout
 * @c: character to print
 * Return: 1 (success) -1 (error)
 */

int _putchar(char c)
{
	static int x;
	static char buff[WRBUFF_SIZE];

	if (c == BUFF_FLUSH || x >= WRBUFF_SIZE)
		write(1, buff, x);
	if (c != BUFF_FLUSH)
		buff[x++] = c;
	return (1);
}
