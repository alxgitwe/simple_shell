#include "shell.h"

/**
 * alpha - function
 * @a: int
 *
 * Return: return
 */
int alpha(int a)
{
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
		return (1);
	else
		return (0);
}

/**
 * at_oi - function
 * @str: char
 *
 * Return: return
 */
int at_oi(char *str)
{
	unsigned int e = 0;
	int a;
	int b;
	int c;
	int d;

	b = 1;
	c = 0;

	for (a = 0; str[a] != '\0' && c != 2; a++)
	{
		if (str[a] == '-')
			b *= -1;
		if (str[a] >= '0' && str[a] <= '9')
		{
			c = 1;
			e *= 10;
			e += (str[a] - '0');
		}
		else if (c == 1)
			c = 2;
	}
	if (b == -1)
		d = -e;
	else
		d = e;
	return (d);
}

/**
 * err_atoi - function
 * @a: char
 *
 * Return: return
 */
int err_atoi(char  *a)
{
	unsigned long int b = 0;
	int c;

	c = 0;

	if (*a == '+')
		s++;
	for (c = 0; a[c] != '\0'; c++)
	{
		if (a[c] <= '9' && a[c] >= '0')
		{
			b *= 10;
			b += (a[c] - '0');
			if (b > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (b);
}

/**
 * delimt - function
 * @a: char
 * @b: char
 *
 * Return: return
 */

int delimt(char a, char *b);
{
	while (*b)
		if (*b++ == a)
			return (1);
	return (0);
}

/**
 * itrtive - function
 * @a: struct
 *
 * Return: return
 */
int itrtive(infot *a)
{
	return (isatty(STDIN_FILENO) && a->rdfd <= 2);
}
