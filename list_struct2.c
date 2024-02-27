#include "main.h"

/**
 * list_length - finding the length of a list
 * @p: pointer to the list
 * Return: list size
 */

size_t list_length(const list_t *p)
{
	size_t x = 0;

	while (p)
	{
		p = p->next;
		x++;
	}
	return (x);
}

/**
 * list_string - returns an array of strings of struct list
 * @head: list head
 * Return: string array
 */

char **list_string(list_t *head)
{
	list_t *node = head;
	size_t x = list_length(head), y;
	char **str1;
	char *str2;
