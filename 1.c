#include "shell.h"

/**
 * itractv - function
 * @a: a
 * Return: return
 */
int itractv(infot *a)
{
	return (isatty(STDIN_FILENO) && a->rdfd <= 2);
}

/**
 * isdlm - function
 * @a: a
 * @b: b
 * Return: return
 */
int isdlm(char a, char *b)
{
	while (*b)
		if (*b++ == a)
			return (1);
	return (0);
}

/**
 *isaplph - function
 *@a: a
 *Return: return
 */

int isaplph(int a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *atoii - function
 *@a: a
 *Return: return
 */

int atoii(char *a)
{
	int b, c = 1, d = 0, e;
	unsigned int f = 0;

	for (b = 0;  a[b] != '\0' && d != 2; b++)
	{
		if (a[b] == '-')
			c *= -1;

		if (a[b] >= '0' && a[b] <= '9')
		{
			d = 1;
			f *= 10;
			f += (a[b] - '0');
		}
		else if (d == 1)
			d = 2;
	}

	if (c == -1)
		e = -f;
	else
		e = f;

	return (e);
}



