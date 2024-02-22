#include "main.h"

/**
 * interactive - returns true in interactive mode
 * @status: struct pointer
 * Return: 1 if interactive, 0 if otherwise
 */

int interactive(status_t *status)
{
	return (isatty(STDIN_FILENO) && status->readfd <= 2);
}

/**
 * _delim - checks if a character is a delimiter
 * @c: input character
 * @delim: delimiter
 * Return: 1 if true, 0 if false
 */

int _delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabet
 * @c: character to check
 * Return: 1 for alphabet, 0 if otherwise
 */

int _isalpha(int c)
{
	if ((c >= 65 && c <= 97) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}

/**
 * _atoi - converting a string to an int
 * @s: input string
 * Return: result
 */

int _atoi(char *s)
{
	int sign = 1;
	int result = 0;
	int i = 0;

	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
		{
			sign * = -1;
		}
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * sign);
}
