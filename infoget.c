#include "shell.h"



/**
 * infoclr - function
 * @a: struct
 * Return: return
 */
void infoclr(infot *a)
{
	a->argmt = NULL;
	a->argv = NULL;
	a->pth = NULL;
	a->argcmt = 0;
}






/**
 * infofree - function
 * @a: struct
 * @b: int
 * Return: return
 */
void infofree(infot *a, int b)
{
	freestring(a->argv);
	a->argv = NULL;
	a->pth = NULL;
	if (b)
	{
		if (!a->cmbuffer)
			free(a->argmt);
		if (a->envr)
			frlst(&(a->envr));
		if (a->hty)
			frlst(&(a->hty));
		if (a->als)
			frlst(&(a->als));
		freestring(a->envrn);
			a->envrn = NULL;
		freep((void **)a->cmbuffer);
		if (a->rdfd > 2)
			close(a->rdfd);
		_putchar(BUF_FLUSH);
	}
}



/**
 * infost - function
 * @a: struct
 * @av: char
 * Return: return
 */
void infost(infot *a, char **av)
{
	int b = 0;

	a->fnme = av[0];
	if (a->argmt)
	{
		a->argv = strw(a->argmt, " \t");
		if (!a->argv)
		{
			a->argv = malloc(sizeof(char *) * 2);
			if (a->argv)
			{
				a->argv[0] = strdupl(a->argmt);
				a->argv[1] = NULL;
			}
		}
		for (b = 0; a->argv && a->argv[b]; b++)
			;
		a->argcmt = b;
		aliasrplc(a);
		varsrplc(a);
	}
}
