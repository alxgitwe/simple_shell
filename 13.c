#include "shell.h"

/**
 * mhsty - function
 * @a: a
 *  Return: return
 */
int mhsty(infot *a)
{
	lstprt(a->hsty);
	return (0);
}

/**
 * unset_alias - function
 * @a: a
 * @b: b
 * Return: return
 */
int unset_alias(infot *a, char *b)
{
	char *d, e;
	int f;

	d = str_chr(b, '=');
	if (!d)
		return (1);
	e = *d;
	*d = 0;
	f = indxnddl(&(a->als),
		indxndgt(a->als, ndstrtw(a->als, b, -1)));
	*d = e;
	return (f);
}

/**
 * set_alias - function
 * @a: a
 * @b: b
 * Return: return
 */
int set_alias(infot *a, char *b)
{
	char *c;

	c = str_chr(b, '=');
	if (!c)
		return (1);
	if (!*++c)
		return (unset_alias(a, b));

	unset_alias(a, b);
	return (ndaddend(&(a->als), b, 0) == NULL);
}

/**
 * print_alias - function
 * @a: a
 * Return: return
 */
int print_alias(listst *a)
{
	char *b = NULL, *c = NULL;

	if (a)
	{
		b = str_chr(a->s, '=');
		for (c = a->s; c <= b; c++)
			_putchar(*c);
		_putchar('\'');
		_puts(b + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * alsmy - function
 * @a: a
 *  Return: return
 */
int alsmy(infot *a)
{
	int b = 0;
	char *c = NULL;
	listst *d = NULL;

	if (a->argc == 1)
	{
		d = a->als;
		while (d)
		{
			print_alias(d);
			d = d->next;
		}
		return (0);
	}
	for (b = 1; a->argv[b]; b++)
	{
		c = str_chr(a->argv[b], '=');
		if (c)
			set_alias(a, a->argv[b]);
		else
			print_alias(ndstrtw(a->als, a->argv[b], '='));
	}

	return (0);
}


