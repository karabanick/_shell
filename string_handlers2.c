#include "main.h"

/**
 * _strlen - to calculate the length of a string
 * @s: input string
 * Return: str length
 */
int _strlen(char *s)
{
	int len = 0;

	if (s == NULL)
	return (0);

	while (*s++)
		len++;

	return (len);
}

/**
 * _strcmp - comparing two strings
 * @s1: first string
 * @s2: another string
 * Return: diffrence
 */

int _strcmp(char *s1, char *s2)
{
	int j = 0;

	while (s1[j] != '\0' && s2[j] != '\0')
	{
		if (s1[j] != s2[j])
			return (s1[j] - s2[j]);
		j++;
	}
	return (0);
}

/**
 * starts_with - checking if a string is a prefix of another string
 * @haystack: string to be searched
 * @needle: substring to search for
 * Return: pointer to start of haystack
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
		{
			return (NULL);
		}
	return ((char *)haystack);
}

/**
 * _strcat - concatenating two string
 * @dest: first string
 * @src: another string
 * Return: pointer to new string
 */

char *_strcat(char *dest, char *src)
{
	int x, y;

	while (dest[x] != '\0')
		x++;
	while (src[y] != '\0')
		dest[x] = src[y];
	x++;
	y++;
	dest[x] = '\0';
	return (dest);
}
