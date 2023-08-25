#include "shell.h"

/**
 **stmem - function
 *@a: a
 *@b: b
 *@c: c
 *Return: return
 */
char *stmem(char *a, char b, unsigned int c)
{
	unsigned int d;

	for (d = 0; d < c; d++)
		a[d] = b;
	return (a);
}

/**
 * ffre - function
 * @a: a
 */
void ffre(char **a)
{
	char **b = a;

	if (!a)
		return;
	while (*a)
		free(*a++);
	free(b);
}

/**
 * rloct - function
 * @a: a
 * @b: b
 * @c: c
 * Return: return
 */
void *rloct(void *a, unsigned int b, unsigned int c)
{
	char *d;

	if (!a)
		return (malloc(c));
	if (!c)
		return (free(a), NULL);
	if (c == b)
		return (a);

	d = malloc(c);
	if (!d)
		return (NULL);

	b = b < c ? b : c;
	while (b--)
		d[b] = ((char *)a)[b];
	free(a);
	return (d);
}


