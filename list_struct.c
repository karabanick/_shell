#include "main.h"

/**
 * new_node - adds a new node at start of list
 * @head: start of list
 * @string: input string
 * @numb: node index
 * Return: list
 */

list_t *new_node(list_t **head, const char *string, int numb)
{
	list_t *new;

	if (!head)
		return (NULL);
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	_memset((void *)new, 0, sizeof(list_t));
	new->numb = numb;
	if (string)
	{
		new->string = _strdup(string);
		if (!new->string)
		{
			free(new);
			return (NULL);
		}
	}
	new->next = *head;
	*head = new;

	return (new);
}

/**
 * node_end - new node at end of list
 * @head: start of list
 * @string: input string
 * @numb: node index
 * Return: list
 */

list_t *node_end(list_t **head, const char *string, int numb)
{
	list_t *new;
	list_t *node;

	if (!head)
		return (NULL);

	node = *head;
	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	_memset((void *)new, 0, sizeof(list_t));
	new->numb = numb;

	if (string)
	{
		new->string = _strdup(string);
		if (!new->string)
		{
			free(new);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new;
	}
	else
		*head = new;

	return (new);
}

/**
 * print_list - prints the list struct elements
 * @p: pointer to node
 * Return: list
 */

size_t print_list(const list_t *p)
{
	size_t x = 0;

	while (p)
	{
		_puts(p->string ? p->string : "(nil)");
		_puts("\n");
		p = p->next;
		x++;
	}
	return (x);
}

/**
 * del_node - deleting a node
 * @head: address of first node
 * @index: node index
 * Return: 1 (success) 0 (fail)
 */

int del_node(list_t **head, unsigned int index)
{
	list_t *node1, node2;
	unsigned int x = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node1 = *head;
		*head = (*head)->next;
		free(node1->string);
		free(node1);
		return (1);
	}
	node1 = *head;

	while (node1)
	{
		if (x == index)
		{
			node2->next = node1->next;
			free(node1->string);
			free(node1);
			return (1);
		}
		x++;
		node2 = node1;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees an entire list
 * @ptr: pointer to node
 * Return: nothing
 */

void free_list(list_t **ptr)
{
	list_t *node1, *node2, *head;

	if (!ptr || !*ptr)
		return;

	head = *ptr;
	node1 = head;
	while (node1)
	{
		node2 = node1->next;
		free(node1->string);
		free(node1);
		node1 = node2;
	}
	ptr = NULL;
}
