#include "shell.h"

/**
 * clrinf - initializes listst struct
 * @info: struct address
 */
void clrinf(infot *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->pth = NULL;
	info->argc = 0;
}

/**
 * infset - initializes listst struct
 * @info: struct address
 * @av: argument vector
 */
void infset(infot *info, char **av)
{
	int i = 0;

	info->namefile = av[0];
	if (info->arg)
	{
		info->argv = strtw(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = duplstr(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		alsrplc(info);
		vrsrplc(info);
	}
}

/**
 * inffr - frees listst struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void inffr(infot *info, int all)
{
	ffre(info->argv);
	info->argv = NULL;
	info->pth = NULL;
	if (all)
	{
		if (!info->buffercmd)
			free(info->arg);
		if (info->envir)
			lstfr(&(info->envir));
		if (info->hsty)
			lstfr(&(info->hsty));
		if (info->als)
			lstfr(&(info->als));
		ffre(info->envrn);
			info->envrn = NULL;
		bfr((void **)info->buffercmd);
		if (info->rdfd > 2)
			close(info->rdfd);
		_putchar(BUF_FLUSH);
	}
}

