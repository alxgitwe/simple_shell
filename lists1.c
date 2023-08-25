#include "shell.h"

/**
 * lenlst - function
 * @a: a
 * Return: return
 */
size_t lenlst(const listst *a)
{
	size_t i = 0;

	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

/**
 * strlstto - function
 * @a: a
 * Return: return
 */
char **strlstto(listst *a)
{
	listst *b = a;
	size_t c = lenlst(a), d;
	char **e;
	char *f;

	if (!a || !c)
		return (NULL);
	e = malloc(sizeof(char *) * (c + 1));
	if (!e)
		return (NULL);
	for (c = 0; b; b = b->next, c++)
	{
		f = malloc(lnstr(b->s) + 1);
		if (!f)
		{
			for (d = 0; d < c; d++)
				free(e[d]);
			free(e);
			return (NULL);
		}

		f = cpystr(f, b->s);
		e[c] = f;
	}
	e[c] = NULL;
	return (e);
}


/**
 * lstprt - function
 * @a: a
 * Return: return
 */
size_t lstprt(const listst *a)
{
	size_t b = 0;

	while (a)
	{
		_puts(nbrconv(a->n, 10, 0));
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
 * ndstrtw - function
 * @a: a
 * @b: b
 * @c: c
 * Return: return
 */
listst *ndstrtw(listst *a, char *b, char c)
{
	char *d = NULL;

	while (a)
	{
		d = strtwth(a->s, b);
		if (d && ((c == -1) || (*d == c)))
			return (a);
		a = a->next;
	}
	return (NULL);
}

/**
 * indxndgt - function
 * @a: a
 * @b: b
 * Return: return
 */
ssize_t indxndgt(listst *a, listst *b)
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


