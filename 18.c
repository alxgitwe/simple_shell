#include "shell.h"

/**
 * ndadd - function
 * @a: a
 * @b: b
 * @c: c
 * Return: return
 */
listst *ndadd(listst **a, const char *b, int c)
{
	listst *d;

	if (!a)
		return (NULL);
	d = malloc(sizeof(listst));
	if (!d)
		return (NULL);
	stmem((void *)d, 0, sizeof(listst));
	d->n = c;
	if (b)
	{
		d->s = duplstr(b);
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
 * ndaddend - function
 * @a: a
 * @b: b
 * @c: c
 * Return: return
 */
listst *ndaddend(listst **a, const char *b, int c)
{
	listst *d, *e;

	if (!a)
		return (NULL);

	e = *a;
	d = malloc(sizeof(listst));
	if (!d)
		return (NULL);
	stmem((void *)d, 0, sizeof(listst));
	d->n = c;
	if (b)
	{
		d->s = duplstr(b);
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

/**
 * strprtlst - function
 * @a: a
 * Return: return
 */
size_t strprtlst(const listst *a)
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
 * indxnddl - function
 * @a: a
 * @b: b
 * Return: return
 */
int indxnddl(listst **a, unsigned int b)
{
	listst *c, *d;
	unsigned int e = 0;

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
 * lstfr - function
 * @a: a
 * Return: return
 */
void lstfr(listst **a)
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


