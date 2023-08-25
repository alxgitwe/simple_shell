#include "shell.h"

/**
 **strn_cpy - function
 *@a: a
 *@b: b
 *@c: c
 *Return: return
 */
char *strn_cpy(char *a, char *b, int c)
{
	int d, e;
	char *f = a;

	d = 0;
	while (b[d] != '\0' && d < c - 1)
	{
		a[d] = b[d];
		d++;
	}
	if (d < c)
	{
		e = d;
		while (e < c)
		{
			a[e] = '\0';
			e++;
		}
	}
	return (f);
}

/**
 **strn_cat - function
 *@a: a
 *@b: b
 *@c: c
 *Return: return
 */
char *strn_cat(char *a, char *b, int c)
{
	int d, e;
	char *f = a;

	d = 0;
	e = 0;
	while (a[d] != '\0')
		d++;
	while (b[e] != '\0' && e < c)
	{
		a[d] = b[e];
		d++;
		e++;
	}
	if (e < c)
		a[d] = '\0';
	return (f);
}

/**
 **str_chr - function
 *@a: a
 *@b: b
 *Return: return
 */
char *str_chr(char *a, char b)
{
	do {
		if (*a == b)
			return (a);
	} while (*a++ != '\0');

	return (NULL);
}


