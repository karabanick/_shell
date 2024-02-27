#include "main.h"

/**
 * **strtow - spliting a string into words, ignoring delimiters
 * @str: input string
 * @d: string delimiter
 * Return: pointer to string array, NULL if error
 */

char **strtow(char *str, char *d)
{
	int w, x, y, z = 0;
	int word_count = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (d == NULL)
		d =  " ";
	for (w = 0; str[w] != '\0'; w++)
		if (!_delim(str[w], d) && (_delim(str[w + 1], d) || !str[w + 1]))
			word_count++;

	if (word_count == 0)
		return (NULL);
	s = malloc((1 + word_count) * sizeof(char *));
	if (s == NULL)
		return (NULL);
	for (w = 0, x = 0; x < word_count; x++)
	{
		while (_delim(str[w], d))
			w++;
		while (!_delim(str[w + y], d) && str[w + y])
			y++;
		s[x] = malloc((y + 1) * sizeof(char));
		if (s[x] == NULL)
		{
			for (y = 0; y < x; y++)
				free(s[y]);
			free(s);
			return (NULL);
		}
		for (z = 0; z < y; z++)
			s[x][z] = str[w++];
		s[x][z] = 0;
	}
	s[x] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: input string
 * @d: delimeter
 * Return: pointer to an array, NULL if error
 */

char **strtow2(char *str, char d)
{
	int w, x, y, z = 0;
	int word_count = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (w = 0; str[w] != '\0'; w++)
		if ((str[w] != d && str[w + 1] == d) ||
				str[w] != d && !str[w + 1] || str[w + 1] == d)
			word_count++;
	if (word_count == 0)
		return (NULL);
	s = malloc((1 + word_count) * sizeof(char *));
	if (s == NULL)
		return (NULL);
	for (w = 0; x = 0; x < word_count; x++)
	{
		while (str[w] == d && str[w] != d)
			w++;
		while (str[w + y] != d && str[w + y] && str[w + y] != d)
			y++;
		s[x] = malloc((y + 1) * sizeof(char));
		if (s[x] == NULL)
		{
			for (y = 0; y < x; y++)
				free(s[y]);
			free(s);
			return (NULL);
		}
		for (z = 0; z < y; z++)
			s[x][z] = str[w++];
		s[x][z] = 0;
	}
	s[x] = NULL;
	return (s);
}
