#include "main.h"

/**
 * print_error - printing an error message
 * @status: pointer to a struct status
 * @estr: input string with error
 * Return: void
 */

void print_error(status_t *status, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	printd_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * _erratoi - converts a string to an integer
 * @s: input string
 * Return: 0 success, -1 error
 */

int _erratoi(char *s)
{
	int x = 0;
	unsigned long int res = 0;

	if (*s == '+')
		s++;
	for (x = 0; s[x] != '\0'; x++)
	{
		if (s[x] >= '0' && s[x] <= '9')
		{
			res *= 10;
			res += (s[x] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

/**
 * print_d - printing a decimal number
 * @input: function input
 * @fd: file desriptor
 * Return: chars printed
 */

int print_d(int input, int fd)
{

