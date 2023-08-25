#include "shell.h"

/**
 * lnstr - function
 * @a: a
 * Return: return
 */
int lnstr(char *a)
{
	int b = 0;

	if (!a)
		return (0);

	while (*a++)
		b++;
	return (b);
}

/**
 * comparstr - function
 * @a: a
 * @b: b
 * Return: return
 */
int comparstr(char *a, char *b)
{
	while (*a && *b)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
	}
	if (*a == *b)
		return (0);
	else
		return (*a < *b ? -1 : 1);
}

/**
 * strtwth - function
 * @a: a
 * @b: b
 * Return: return
 */
char *strtwth(const char *a, const char *b)
{
	while (*b)
		if (*b++ != *a++)
			return (NULL);
	return ((char *)a);
}

/**
 * catstr - function
 * @a: a
 * @b: b
 * Return: return
 */
char *catstr(char *a, char *b)
{
	char *c = a;

	while (*a)
		a++;
	while (*b)
		*a++ = *b++;
	*a = *b;
	return (c);
}


