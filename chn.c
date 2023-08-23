#include "shell.h"


/**
 * strplc - function
 * @a: char
 * @b: char
 * Return: return
 */
int strplc(char **a, char *b)
{
	free(*a);
	*a = b;
	return (1);
}

/**
 * ischn - function
 * @a: struct
 * @b: char
 * @c: struct
 * Return: return
 */
int ischn(infot *a, char *b, size_t *c)
{
	size_t j = *c;

	if (b[j] == '|' && b[j + 1] == '|')
	{
		b[j] = 0;
		j++;
		a->cmbuffertye = CMD_OR;
	}
	else if (b[j] == '&' && b[j + 1] == '&')
	{
		b[j] = 0;
		j++;
		a->cmbuffertye = CMD_AND;
	}
	else if (b[j] == ';')
	{
		b[j] = 0;
		a->cmbuffertye = CMD_CHAIN;
	}
	else
		return (0);
	*c = j;
	return (1);
}



/**
 * chkch - function
 * @a: struct
 * @b: char
 * @c: struct
 * @d: struct
 * @e: struct
 *
 * Return: return
 */
void chkch(infot *a, char *b, size_t *c, size_t d, size_t e)
{
	size_t j = *c;

	if (a->cmbuffertye == CMD_AND)
	{
		if (a->st)
		{
			b[d] = 0;
			j = e;
		}
	}
	if (a->cmbuffertye == CMD_OR)
	{
		if (!a->st)
		{
			b[d] = 0;
			j = e;
		}
	}

	*c = j;
}


/**
 * aliasrplc - function
 * @a: struct
 * Return: return
 */
int aliasrplc(infot *a)
{
	int b;
	listst *c;
	char *d;

	for (b = 0; b < 10; b++)
	{
		c = ndstrt(a->als, a->argv[0], '=');
		if (!c)
			return (0);
		free(a->argv[0]);
		d = strcher(c->s, '=');
		if (!d)
			return (0);
		d = strdupl(d + 1);
		if (!d)
			return (0);
		a->argv[0] = d;
	}
	return (1);
}


/**
 * varsrplc - function
 * @a: struct
 * Return: return
 */
int varsrplc(infot *a)
{
	int b = 0;
	listst *c;

	for (b = 0; a->argv[b]; b++)
	{
		if (a->argv[b][0] != '$' || !a->argv[b][1])
			continue;

		if (!strcomp(a->argv[b], "$?"))
		{
			strplc(&(a->argv[b]),
				strdupl(cvrtnmbr(a->st, 10, 0)));
			continue;
		}
		if (!strcomp(a->argv[b], "$$"))
		{
			strplc(&(a->argv[b]),
				strdupl(cvrtnmbr(getpid(), 10, 0)));
			continue;
		}
		c = ndstrt(a->envr, &a->argv[b][1], '=');
		if (c)
		{
			strplc(&(a->argv[b]),
				strdupl(strcher(c->s, '=') + 1));
			continue;
		}
		strplc(&a->argv[b], strdupl(""));

	}
	return (0);
}

