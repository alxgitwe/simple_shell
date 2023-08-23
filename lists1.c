#include "shell.h"

/**
 * llnt - function
 * @a: struct
 *
 * Return: return
 */
size_t llnt(const listst *a)
{
	size_t b;

	b = 0;

	while (a)
	{
		a = a->next;
		b++;
	}
	return (b);
}

/**
 * gndindex - function
 * @a: struct
 * @b: struct
 *
 * Return: return
 */
ssize_t gndindex(listst *a, listst *b)
{
	size_t c = 0;

	while (a)
	{
		if (a == b)
			return (c);

		a = a->next;
		c++;
	}
	return (-1);
}

/**
 * ndstrt - function
 * @a: struct
 * @b: char
 * @c: char
 *
 * Return: return
 */
listst *ndstrt(listst *a, char *b, char c)
{
	char *d = NULL;

	while (a)
	{
		d = startwith(a->s, b);
		if (d && ((c == -1) || (*d == c)))
			return (a);
		a = a->next;
	}
	return (NULL);
}

/**
 * plst - function
 * @a: struct
 *
 * Return: return
 */
size_t plst(const listst *a)
{
	size_t b = 0;

	while (a)
	{
		_puts(cvrtnmbr(a->a, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(a->s ? a->s : "(nil)");
		_puts("\n");
		a = a->next;
		b++;
	}
	return (b);
}

/**
 * litstr - function
 * @a: struct
 *
 * Return: return
 */
char **litstr(listst *a)
{
	listst *b = a;
	size_t c = llnt(a), j;
	char **d;
	char *e;

	if (!a || !c)
		return (NULL);
	d = malloc(sizeof(char *) * (c + 1));
	if (!d)
		return (NULL);
	for (c = 0; b; b = b->next, c++)
	{
		e = malloc(strlen(b->s) + 1);
		if (!e)
		{
			for (j = 0; j < c; j++)
				free(d[j]);
			free(d);
			return (NULL);
		}

		e = strcopy(e, b->s);
		d[c] = e;
	}
	d[c] = NULL;
	return (d);
}
