#include "shell.h"

/**
 * erratoii - function
 * @a: a
 * Return: return
 */
int erratoii(char *a)
{
	int b = 0;
	unsigned long int c = 0;

	if (*a == '+')
		a++;
	for (b = 0;  a[b] != '\0'; b++)
	{
		if (a[b] >= '0' && a[b] <= '9')
		{
			c *= 10;
			c += (a[b] - '0');
			if (c > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (c);
}

/**
 * errprnt - function
 * @a: a
 * @b: b
 * Return: return
 */
void errprnt(infot *a, char *b)
{
	errputs(a->namefile);
	errputs(": ");
	print_d(a->lncnt, STDERR_FILENO);
	errputs(": ");
	errputs(a->argv[0]);
	errputs(": ");
	errputs(b);
}

/**
 * print_d - function
 * @a: a
 * @c: c
 * Return: return
 */
int print_d(int a, int c)
{
	int (*d)(char) = _putchar;
	int e, f = 0;
	unsigned int g, h;

	if (c == STDERR_FILENO)
		d = errputchar;
	if (a < 0)
	{
		g = -a;
		d('-');
		f++;
	}
	else
		g = a;
	h = g;
	for (e = 1000000000; e > 1; e /= 10)
	{
		if (g / e)
		{
			d('0' + h / e);
			f++;
		}
		h %= e;
	}
	d('0' + h);
	f++;

	return (f);
}

/**
 * nbrconv - function
 * @a: a
 * @b: b
 * @c: c
 * Return: return
 */
char *nbrconv(long int a, int b, int c)
{
	static char *d;
	static char e[50];
	char f = 0;
	char *g;
	unsigned long h = a;

	if (!(c & CONVERT_UNSIGNED) && a < 0)
	{
		h = -a;
		f = '-';

	}
	d = c & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	g = &e[49];
	*g = '\0';

	do	{
		*--g = d[h % b];
		h /= b;
	} while (h != 0);

	if (f)
		*--g = f;
	return (g);
}

/**
 * rmvcmnt - function
 * @a: a
 * Return: return
 */
void rmvcmnt(char *a)
{
	int b;

	for (b = 0; a[b] != '\0'; b++)
		if (a[b] == '#' && (!b || a[b - 1] == ' '))
		{
			a[b] = '\0';
			break;
		}
}


