#include "shell.h"

/**
 * prterror - function
 * @a: struct
 * @b: char
 *
 * Return: return
 */
void prterror(infot *a, char *b)
{
	erputs(a->fnme);
	erputs(": ");
	prtdi(a->lncount, STDERR_FILENO);
	erputs(": ");
	erputs(a->argv[0]);
	erputs(": ");
	erputs(b);
}

/**
 * prtdi - function
 * @a: int
 * @b: int
 *
 * Return: return
 */
int prtdi(int a, int b)
{
	unsigned int c;
	unsigned int d;
	int (*ptchr)(char) = _putchar;
	int i;
	int j = 0;

	if (b == STDERR_FILENO)
		ptchr = eptchr;
	if (a < 0)
	{
		c = -a;
		ptchr('-');
		j++;
	}
	else
		c = a;
	d = c;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (c / i)
		{
			ptchr('0' + d / i);
			j++;
		}
		d %= i;
	}
	ptchr('0' + d);
	j++;

	return (j);
}

/**
 * rmcmt - function
 * @a: char
 *
 * Return: return
 */
void rmcmt(char *a)
{
	int b;

	for (b = 0; a[b] != '\0'; b++)
		if ((!b || a[b - 1] == ' ') && a[b] == '#')
		{
			a[b] = '\0';
			break;
		}
}

/**
 * cvrtnmbr - function
 * @a: int
 * @b: int
 * @c: int
 *
 * Return: return
 */
char *cvrtnmbr(long int a, int b, int c)
{
	unsigned long g = a;
	char *f;
	char e = 0;
	static char buff[50];
	static char *d;


	if (a < 0 && !(c & CONVERT_UNSIGNED))
	{
		g = -a;
		e = '-';
	}

	d = c & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	f = &buff[49];
	*f = '\0';
	do	{
		*--f = d[g % b];
		g /= b;
	} while (g != 0);
	if (e)
		*--f = e;
	return (f);
}
