#include "shell.h"

/**
 * cpystr - copies a string
 * @a: a
 * @b: b
 * Return: return
 */
char *cpystr(char *a, char *b)
{
	int c = 0;

	if (a == b || b == 0)
		return (a);
	while (b[c])
	{
		a[c] = b[c];
		c++;
	}
	a[c] = 0;
	return (a);
}

/**
 * duplstr - duplicates a string
 * @a: a
 * Return: return
 */
char *duplstr(const char *a)
{
	int b = 0;
	char *c;

	if (a == NULL)
		return (NULL);
	while (*a++)
		b++;
	c = malloc(sizeof(char) * (b + 1));
	if (!c)
		return (NULL);
	for (b++; b--;)
		c[b] = *--a;
	return (c);
}

/**
 *_puts - prints an input string
 *@a: a
 * Return: return
 */
void _puts(char *a)
{
	int b = 0;

	if (!a)
		return;
	while (a[b] != '\0')
	{
		_putchar(a[b]);
		b++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @a: a
 * Return: return
 */
int _putchar(char a)
{
	static int b;
	static char c[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(1, c, b);
		b = 0;
	}
	if (a != BUF_FLUSH)
		c[b++] = a;
	return (1);
}


