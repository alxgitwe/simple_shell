#include "shell.h"

/**
 * envirget - function
 * @a: a
 * Return: return
 */
char **envirget(infot *a)
{
	if (!a->envrn || a->chenv)
	{
		a->envrn = strlstto(a->envir);
		a->chenv = 0;
	}

	return (a->envrn);
}

/**
 * ustenvrn - function
 * @a: a
 * @b: b
 * Return: return
 */
int ustenvrn(infot *a, char *b)
{
	listst *c = a->envir;
	size_t d = 0;
	char *e;

	if (!c || !b)
		return (0);

	while (c)
	{
		e = strtwth(c->s, b);
		if (e && *e == '=')
		{
			a->chenv = indxnddl(&(a->envir), d);
			d = 0;
			c = a->envir;
			continue;
		}
		c = c->next;
		d++;
	}
	return (a->chenv);
}

/**
 * stenvrn - function
 * @a: a
 * @b: b
 * @c: c
 *  Return: return
 */
int stenvrn(infot *a, char *b, char *c)
{
	char *d = NULL;
	listst *e;
	char *f;

	if (!b || !c)
		return (0);

	d = malloc(lnstr(b) + lnstr(c) + 2);
	if (!d)
		return (1);
	cpystr(d, b);
	catstr(d, "=");
	catstr(d, c);
	e = a->envir;
	while (e)
	{
		f = strtwth(e->s, b);
		if (f && *f == '=')
		{
			free(e->s);
			e->s = d;
			a->chenv = 1;
			return (0);
		}
		e = e->next;
	}
	ndaddend(&(a->envir), d, 0);
	free(d);
	a->chenv = 1;
	return (0);
}


