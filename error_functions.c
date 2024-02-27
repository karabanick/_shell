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
	int (*_dputchar)(char) = _putchar;
	int x, count = 0;
	unsigned int val;
	unsigned int curr;

	if (fd == STDERR_FILENO)
		_dputchar = _eputchar;
	if (input < 0)
	{
		val = -input;
		_dputchar('-');
		count++;
	}
	else
		val = input;
	curr = val;

	for (x = 1000000000; x > x /= 10)
	{
		if (val / x)
		{
			_dputchar('0' + curr / x);
			count++;
		}
		curr %= x;
	}
	_dputchar('0' + curr);
	count++;

	return (count);
}

/**
 * convert_num - function that converts a number in itoa
 * @numb: input number
 * @base: base
 * @flag: flags under consideration
 * Return: string
 */

char *convert_num(long int numb, int base, int flag)
{
	static char *arr;
	static char _buffer[50];
	char sign;
	unsigned long x = num;
	char *p;

	if (!(flag & CONVERT_UNSIGNED) && numb < 0)
	{
		x = -numb;
		sign = '-';
	}
	arr = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &_buffer[49];
	*p = '\0';

	do {
		*--p = arr[x % base];
		x /= base;
	} while (x != 0);

	if (sign)
		*--p = sign;

	return (p);
}

/**
 * rm_comments - function to remove / replace comments
 * @buff: input
 * Return: 0 (success)
 */

void rm_comments(char *buff)
{
	int x;

	for (x = 0; buff[x] != '\0'; x++)
		if (buff[x] == '#' && (!x || buff[x - 1] == ' '))
		{
			buff[x] = '\0';
			break;
		}
}
