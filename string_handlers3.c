#include "main.h"

/**
 * _strncat - concatenates two strings
 * @dest: first string
 * @src: second string
 * @n: bytes from src
 * Return: pointer to new string
 */

char *_strncat(char *dest, char *src, int n)
{
	int x;
	int y;

	while (dest[x] != '\0')
	{
		x++;
	}

	while (src[y] != '\0' && y < n)
	{
		dest[x] = src[y];
		x++;
		y++;
	}
	dest[x] = '\0';
	return (dest);
}

/**
 * _strncpy - copying a string
 * @dest: first string
 * @src: second string
 * @n: bytes to be copied
 * Return: pointer to dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int x;

	for (x = 0; x < n && src[x] != '\0'; x++)
	{
		dest[x] = src[x];
	}
	while (x < n)
	{
		dest[x] = '\0';
		x++;
	}
	return (dest);
}

/**
 * _strchr - locating a character in a string
 * @s: input string
 * @c: character to search for
 * Return: pointer to character, otherwise NULL
 */

char *_strchr(char *s, char c)
{
	int x = 0;

	while (s[x] >= '\0')
	{
		if (s[x] == c)
		{
			return ((char *)&s[x]);
		}
		x++;
	}
	return (NULL);
}
