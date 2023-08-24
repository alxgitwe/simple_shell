#include "shell.h"

/**
 * lenlst - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t lenlst(const listst *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * strlstto - function
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **strlstto(listst *head)
{
	listst *node = head;
	size_t i = lenlst(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(lnstr(node->s) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = cpystr(str, node->s);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * lstprt - prints all elements of a listst linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t lstprt(const listst *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(nbrconv(h->n, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->s ? h->s : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * ndstrtw - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
listst *ndstrtw(listst *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = strtwth(node->s, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * indxndgt - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t indxndgt(listst *head, listst *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

