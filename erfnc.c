#include "shell.h"

/**
 * erpts - function
 * @a: char
 *
 * Return: return
 */
void erpts(char *a)
{
	int b = 0;

	if (!a)
		return;
	while (a[b] != '\0')
	{
		_eputchar(a[b]);
		b++;
	}
}

/**
 * ptfdsptr - function
 * @a: char
 * @b: int
 *
 * Return: return
 */
int ptfdsptr(char a, int b)
{
	static int c;
	static char buffer[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || c >= WRITE_BUF_SIZE)
	{
		write(b, buffer, c);
		c = 0;
	}
	if (a != BUF_FLUSH)
		buffer[c++] = a;
	return (1);
}

/**
 * putsdsptr - function
 * @a: char
 * @b: int
 *
 * Return: return
 */
int putsdsptr(char *a, int b)
{
	int c = 0;

	if (!a)
		return (0);
	while (*a)
	{
		c += ptfdsptr(*a++, b);
	}
	return (c);
}

/**
 * erptchr - function
 * @a: char
 *
 * Return: return
 */
int erptchr(char a)
{
	static int b;
	static char buffer[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(2, buffer, b);
		b = 0;
	}
	if (a != BUF_FLUSH)
		buffer[b++] = a;
	return (1);
}
