#include "shell.h"

/**
 * mext - function
 * @a: a
 * Return: return
 */
int mext(infot *a)
{
	int b;

	if (a->argv[1])
	{
		b = erratoii(a->argv[1]);
		if (b == -1)
		{
			a->sttus = 2;
			errprnt(a, "Illegal number: ");
			errputs(a->argv[1]);
			errputchar('\n');
			return (1);
		}
		a->nmerr = erratoii(a->argv[1]);
		return (-2);
	}
	a->nmerr = -1;
	return (-2);
}

/**
 * mchd - function
 * @a: a
 *  Return: return
 */
int mchd(infot *a)
{
	char *b, *c, d[1024];
	int e;

	b = getcwd(d, 1024);
	if (!b)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!a->argv[1])
	{
		c = gtenvir(a, "HOME=");
		if (!c)
			e = /* */
				chdir((c = gtenvir(a, "PWD=")) ? c : "/");
		else
			e = chdir(c);
	}
	else if (comparstr(a->argv[1], "-") == 0)
	{
		if (!gtenvir(a, "OLDPWD="))
		{
			_puts(b);
			_putchar('\n');
			return (1);
		}
		_puts(gtenvir(a, "OLDPWD=")), _putchar('\n');
		e = /*  */
			chdir((c = gtenvir(a, "OLDPWD=")) ? c : "/");
	}
	else
		e = chdir(a->argv[1]);
	if (e == -1)
	{
		errprnt(a, "can't cd to ");
		errputs(a->argv[1]), errputchar('\n');
	}
	else
	{
		stenvrn(a, "OLDPWD", gtenvir(a, "PWD="));
		stenvrn(a, "PWD", getcwd(d, 1024));
	}
	return (0);
}

/**
 * mhlp - function
 * @a: a
 *  Return: return
 */
int mhlp(infot *a)
{
	char **b;

	b = a->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*b);
	return (0);
}


