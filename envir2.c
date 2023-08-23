#include "shell.h"

/**
 * envirget - function
 * @a: struct
 * @b: char
 * Return: return
 */
char *envirget(infot *a, const char *b)
{
	char *c;
	listst *d = a->envr;

	while (d)
	{
		c = startwith(d->s, b);
		if (c && *c)
			return (c);
		d = d->next;
	}
	return (NULL);
}


/**
 * menvirust - function
 * @a: struct
 *
 * Return: return
 */
int menvirust(infot *a)
{
	int b;

	if (a->argcmt == 1)
	{
		erpts("Too few arguements.\n");
		return (1);
	}
	for (b = 1; b <= a->argcmt; b++)
		envust(a, a->argv[b]);

	return (0);
}

/**
 * lipolenv - function
 * @a: struct
 *
 * Return: return
 */
int lipolenv(infot *a)
{
	size_t c;
	listst *b = NULL;

	for (c = 0; environ[c]; c++)
		addnend(&b, environ[c], 0);
	a->envr = b;
	return (0);
}


/**
 * menvirst - function
 * @a: struct
 *
 * Return: return
 */
int menvirst(infot *a)
{
	if (a->argcmt != 3)
	{
		erpts("Incorrect number of arguements\n");
		return (1);
	}
	if (envst(a, a->argv[1], a->argv[2]))
		return (0);
	return (1);
}



/**
 * menvir - function
 * @a: struct
 *
 * Return: return
 */
int menvir(infot *a)
{
	prlis(a->envr);
	return (0);
}

