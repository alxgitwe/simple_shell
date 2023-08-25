#include "shell.h"

/**
 * chnis - function
 * @a: a
 * @b: b
 * @c: c
 * Return: return
 */
int chnis(infot *a, char *b, size_t *c)
{
	size_t d = *c;

	if (b[d] == '|' && b[d + 1] == '|')
	{
		b[d] = 0;
		d++;
		a->typebuffercmd = CMD_OR;
	}
	else if (b[d] == '&' && b[d + 1] == '&')
	{
		b[d] = 0;
		d++;
		a->typebuffercmd = CMD_AND;
	}
	else if (b[d] == ';') 
	{
		b[d] = 0;
		a->typebuffercmd = CMD_CHAIN;
	}
	else
		return (0);
	*c = d;
	return (1);
}

/**
 * chnchk - function
 * @a: a
 * @b: b
 * @c: c
 * @d: d
 * @e: e
 * Return: return
 */
void chnchk(infot *a, char *b, size_t *c, size_t d, size_t e)
{
	size_t f = *c;

	if (a->typebuffercmd == CMD_AND)
	{
		if (a->sttus)
		{
			b[d] = 0;
			f = e;
		}
	}
	if (a->typebuffercmd == CMD_OR)
	{
		if (!a->sttus)
		{
			b[d] = 0;
			f = e;
		}
	}

	*c = f;
}

/**
 * alsrplc - function
 * @a: a
 * Return: return
 */
int alsrplc(infot *a)
{
	int b;
	listst *c;
	char *d;

	for (b = 0; b < 10; b++)
	{
		c = ndstrtw(a->als, a->argv[0], '=');
		if (!c)
			return (0);
		free(a->argv[0]);
		d = str_chr(c->s, '=');
		if (!d)
			return (0);
		d = duplstr(d + 1);
		if (!d)
			return (0);
		a->argv[0] = d;
	}
	return (1);
}

/**
 * vrsrplc - function
 * @a: a
 * Return: return
 */
int vrsrplc(infot *a)
{
	int b = 0;
	listst *c;

	for (b = 0; a->argv[b]; b++)
	{
		if (a->argv[b][0] != '$' || !a->argv[b][1])
			continue;

		if (!comparstr(a->argv[b], "$?"))
		{
			rplcstrn(&(a->argv[b]),
				duplstr(nbrconv(a->sttus, 10, 0)));
			continue;
		}
		if (!comparstr(a->argv[b], "$$"))
		{
			rplcstrn(&(a->argv[b]),
				duplstr(nbrconv(getpid(), 10, 0)));
			continue;
		}
		c = ndstrtw(a->envir, &a->argv[b][1], '=');
		if (c)
		{
			rplcstrn(&(a->argv[b]),
				duplstr(str_chr(c->s, '=') + 1));
			continue;
		}
		rplcstrn(&a->argv[b], duplstr(""));

	}
	return (0);
}

/**
 * rplcstrn - function
 * @a: a
 * @b: b
 * Return: return
 */
int rplcstrn(char **a, char *b)
{
	free(*a);
	*a = b;
	return (1);
}


