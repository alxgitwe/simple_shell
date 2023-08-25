#include "shell.h"

/**
 *errputs - function
 * @a: a
 * Return: return
 */
void errputs(char *a)
{
	int b = 0;

	if (!a)
		return;
	while (a[b] != '\0')
	{
		errputchar(a[b]);
		b++;
	}
}

/**
 * errputchar - function
 * @a: a
 * Return: return
 */
int errputchar(char a)
{
	static int b;
	static char c[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(2, c, b);
		b = 0;
	}
	if (a != BUF_FLUSH)
		c[b++] = a;
	return (1);
}

/**
 * fdput - function
 * @a: a
 * @b: b
 * Return: return
 */
int fdput(char a, int b)
{
	static int c;
	static char d[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || c >= WRITE_BUF_SIZE)
	{
		write(b, d, c);
		c = 0;
	}
	if (a != BUF_FLUSH)
		d[c++] = a;
	return (1);
}

/**
 *_putsfd - function
 * @a: a
 * @b: b
 * Return: return
 */
int _putsfd(char *a, int b)
{
	int c = 0;

	if (!a)
		return (0);
	while (*a)
	{
		c += fdput(*a++, b);
	}
	return (c);
}


