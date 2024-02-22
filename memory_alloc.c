#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: memory area
 * @b: constant
 * @n:bytes
 * Return: pointer to s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int j = 0;

	while (j < n)
	{
		s[j] = b;
		j++;
	}
	return (s);
}

/**
 * ffree - freeing a string
 * @pp: pointer to strings
 * Return: nothing
 */

void ffree(char **pp)
{
	char **x = pp;

	if (pp == NULL)
		return;
	while (*pp)
		free(*pp++);
	free(x);
}

/**
 * _realloc - reallocating a block of memory
 * @ptr: pointer to old block of memory
 * @old_size: first memory
 * @new_size: second memory
 * Return: result
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	void *ptr2;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		ptr2 = malloc(new_size);

		if (ptr2 == NULL)
			return (NULL);
		return (ptr2);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	ptr2 = malloc(new_size);

	if (ptr2 == NULL)
		return (NULL);

	if (new_size > old_size)
		new_size = old_size;

	for (i = 0; i < new_size; i++)
		*((char *)ptr2 + i) = *((char *)ptr + i);

	free(ptr);
	return (ptr2);
}

/**
 * pfree - frees a pointer
 * @ptr: pointer to the  pointer
 * Return: 1 success, 0 error
 */

int pfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
