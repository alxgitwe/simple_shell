#include "shell.h"

/**
 * envget - function
 * @a: struct
 *
 * Return: return
 */
char **envget(infot *a)
{
	if (!a->envrn || a->envcd)
	{
		a->envrn = litstr(a->envr);
		a->envcd = 0;
	}

	return (a->envrn);
}

/**
 * envst - function
 * @a: struct
 * @b: char
 * @c: char
 *
 * Return: return
 */
int envst(infot *a, char *b, char *c)
{

	listst *d;
	char *buffer = NULL;
	char *e;

	if (!b || !c)
		return (0);

	buffer = malloc(strlen(b) + strlen(c) + 2);
	if (!buffer)
		return (1);
	strcopy(buffer, b);
	strcat(buffer, "=");
	strcat(buffer, c);
	d = a->envr;
	while (d)
	{
		e = startwith(d->s, b);
		if (e && *e == '=')
		{
			free(d->s);
			d->s = buffer;
			a->envcd = 1;
			return (0);
		}
		d = d->next;
	}
	addnend(&(a->envr), buffer, 0);
	free(buffer);
	a->envcd = 1;
	return (0);
}





/**
 * envust - function
 * @a: struct
 * @b: char
 *
 * Return: return
 */
int envust(infot *a, char *b)
{

	size_t e = 0;
	listst *c = a->envr;
	char *d;

	if (!c || !b)
		return (0);

	while (c)
	{
		d = startwith(c->s, b);
		if (d && *d == '=')
		{
			a->envcd = dlindeno(&(a->envr), e);
			e = 0;
			c = a->envr;
			continue;
		}
		c = c->next;
		e++;
	}
	return (a->envcd);
}
