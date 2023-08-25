#include "shell.h"

/**
 * menvr - function
 * @a: a
 * Return: return
 */
int menvr(infot *a)
{
	strprtlst(a->envir);
	return (0);
}

/**
 * gtenvir - function
 * @a: a
 * @b: b
 * Return: return
 */
char *gtenvir(infot *a, const char *b)
{
	listst *c = a->envir;
	char *d;

	while (c)
	{
		d = strtwth(c->s, b);
		if (d && *d)
			return (d);
		c = c->next;
	}
	return (NULL);
}

/**
 * mstenvir - function
 * @a: a
 *  Return: return
 */
int mstenvir(infot *a)
{
	if (a->argc != 3)
	{
		errputs("Incorrect number of arguements\n");
		return (1);
	}
	if (stenvrn(a, a->argv[1], a->argv[2]))
		return (0);
	return (1);
}

/**
 * mustenvir - function
 * @a: a
 *  Return: return
 */
int mustenvir(infot *a)
{
	int b;

	if (a->argc == 1)
	{
		errputs("Too few arguements.\n");
		return (1);
	}
	for (b = 1; b <= a->argc; b++)
		ustenvrn(a, a->argv[b]);

	return (0);
}

/**
 * ppenvirlst - function
 * @a: a
 * Return: return
 */
int ppenvirlst(infot *a)
{
	listst *b = NULL;
	size_t c;

	for (c = 0; environ[c]; c++)
		ndaddend(&b, environ[c], 0);
	a->envir = b;
	return (0);
}


