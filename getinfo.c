#include "shell.h"

/**
 * clrinf - function
 * @a: a
 */
void clrinf(infot *a)
{
	a->arg = NULL;
	a->argv = NULL;
	a->pth = NULL;
	a->argc = 0;
}

/**
 * infset - function
 * @a: a
 * @b: b
 */
void infset(infot *a, char **b)
{
	int c = 0;

	a->namefile = b[0];
	if (a->arg)
	{
		a->argv = strtw(a->arg, " \t");
		if (!a->argv)
		{

			a->argv = malloc(sizeof(char *) * 2);
			if (a->argv)
			{
				a->argv[0] = duplstr(a->arg);
				a->argv[1] = NULL;
			}
		}
		for (c = 0; a->argv && a->argv[c]; c++)
			;
		a->argc = c;

		alsrplc(a);
		vrsrplc(a);
	}
}

/**
 * inffr - function
 * @a: a
 * @b: b
 */
void inffr(infot *a, int b)
{
	ffre(a->argv);
	a->argv = NULL;
	a->pth = NULL;
	if (b)
	{
		if (!a->buffercmd)
			free(a->arg);
		if (a->envir)
			lstfr(&(a->envir));
		if (a->hsty)
			lstfr(&(a->hsty));
		if (a->als)
			lstfr(&(a->als));
		ffre(a->envrn);
			a->envrn = NULL;
		bfr((void **)a->buffercmd);
		if (a->rdfd > 2)
			close(a->rdfd);
		_putchar(BUF_FLUSH);
	}
}


