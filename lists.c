#include "shell.h"

/**
 * ndadd - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
listst *ndadd(listst **head, const char *str, int num)
{
	listst *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(listst));
	if (!new_head)
		return (NULL);
	stmem((void *)new_head, 0, sizeof(listst));
	new_head->n = num;
	if (str)
	{
		new_head->s = duplstr(str);
		if (!new_head->s)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * ndaddend - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
listst *ndaddend(listst **head, const char *str, int num)
{
	listst *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(listst));
	if (!new_node)
		return (NULL);
	stmem((void *)new_node, 0, sizeof(listst));
	new_node->n = num;
	if (str)
	{
		new_node->s = duplstr(str);
		if (!new_node->s)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * strprtlst - prints only the str element of a listst linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t strprtlst(const listst *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->s ? h->s : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * indxnddl - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int indxnddl(listst **head, unsigned int index)
{
	listst *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->s);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->s);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * lstfr - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void lstfr(listst **head_ptr)
{
	listst *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->s);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}

