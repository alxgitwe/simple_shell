include "shell.h"

/**
 * fillmemoset - function
 * @a: char
 * @b: char
 * @c: int
 *
 * Return: return
 */
char *fillmemoset(char *a, char b, unsigned int c)
{
	unsigned int d;

	for (d = 0; d < c; d++)
		a[d] = b;
	return (a);
}

/**
 * freep - function
 * @a: pointer
 *
 * Return: return
 */
int freep(void **a)
{
	if (a && *a)
	{
		free(*a);
		*a = NULL;
		return (1);
	}
	return (0);
}

/**
 * reallocat - function
 * @a: pointer
 * @b: int
 * @c: int
 *
 * Return: return
 */
void reallocat(void *a, unsigned int b, unsigned int c)
{
	char *d;

	if  (!a)
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

/**
 * freestring -  function
 * @a: char
 *
 * Return: return
 */
void freestring(char **a)
{
	char **b = a;

	if (!a)
		return;
	while (*a)
		free(*a++);
	free(b);
}
