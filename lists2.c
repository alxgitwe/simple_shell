#include "shell.h"

/**
 * addnd - function
 * @a: struct
 * @b: char
 * @c: int
 *
 * Return: return
 */
listst *addnd(listst **a, const char *b, int c)
{
	listst *d;

	if (!a)
		return (NULL);
	d = malloc(sizeof(listst));
	if (!d)
		return (NULL);
	fillmemoset((void *)d, 0, sizeof(listst));
	d->a = c;
	if (b)
	{
		d->s = strdupl(b);
		if (!d->s)
		{
			free(d);
			return (NULL);
		}
	}
	d->next = *a;
	*a = d;
	return (d);
}

/**
 * frlst - function
 * @a: struct
 *
 * Return: return
 */
void frlst(listst **a)
{
	listst *b, *c, *d;

	if (!a || !*a)
		return;
	d = *a;
	b = d;
	while (b)
	{
		c = b->next;
		free(b->s);
		free(b);
		b = c;
	}
	*a = NULL;
}

/**
 * dlindeno - function
 * @a: struct
 * @b: int
 *
 * Return: return
 */
int dlindeno(listst **a, unsigned int b)
{
	unsigned int e = 0;
	listst *c, *d;

	if (!a || !*a)
		return (0);

	if (!b)
	{
		c = *a;
		*a = (*a)->next;
		free(c->s);
		free(c);
		return (1);
	}
	c = *a;
	while (c)
	{
		if (e == b)
		{
			d->next = c->next;
			free(c->s);
			free(c);
			return (1);
		}
		e++;
		d = c;
		c = c->next;
	}
	return (0);
}

/**
 * prlis - function
 * @a: struct
 *
 * Return: return
 */
size_t prlis(const listst *a)
{
	size_t b = 0;

	while (a)
	{
		_puts(a->s ? a->s : "(nil)");
		_puts("\n");
		a = a->next;
		b++;
	}
	return (b);
}

/**
 * addnend - function
 * @a: struct
 * @b: char
 * @c: int
 *
 * Return: return
 */
listst *addnend(listst **a, const char *b, int c)
{
	listst *d, *e;

	if (!a)
		return (NULL);

	e = *a;
	d = malloc(sizeof(listst));
	if (!d)
		return (NULL);
	fillmemoset((void *)d, 0, sizeof(listst));
	d->a = c
	if (b)
	{
		d->s = strdupl(b);
		if (!d->s)
		{
			free(d);
			return (NULL);
		}
	}
	if (e)
	{
		while (e->next)
			e = e->next;
		e->next = d;
	}
	else
		*a = d;
	return (d);
}

