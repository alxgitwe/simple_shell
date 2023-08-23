#include "shell.h"

/**
 * strcher - funtcion
 * @a: char
 * @b: char
 *
 * Return: return
 */

char *strcher(char *a, char b)
{
	do {
		if (*a == b)
			return (a);
	} while (*a++ != '\0');

	return (NULL);
}

/**
 * strcopyn - funtcion
 * @i: char
 * @j: char
 * @d: int
 *
 * Return: return
 */

char *strcopyn(char *i, char *j, int d)
{
	char *string = i;
	int a;
	int b;

	a = 0;
	while (a < d - 1 && j[a] != '\0')
	{
		i[a] = j[a];
		a++;
	}
	if (a < d)
	{
		b = a;
		while  (b < d)
		{
			i[b] = '\0';
			b++;
		}
	}
	return (string);
}



/**
 * strcatn - funtcion
 * @i: char
 * @j: char
 * @d: int
 *
 * Return: return
 */

char *strcatn(char *i, char *j, int d)
{
	char *string = i;
	int a;
	int b;

	b = 0;
	a = 0;

	while (i[a] != '\0')
	{
		a++;
	}
	while (b < d && j[b] != '\0')
	{
		i[a] = j[b];
		b++;
		a++;
	}
	if (b < d)
		i[a] = '\0';
	return (string);
}

