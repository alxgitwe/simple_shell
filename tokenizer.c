#include "shell.h"

/**
 * **strtw - function
 * @a: a
 * @b: b
 * Return: return
 */

char **strtw(char *a, char *b)
{
	int c, d, e, f, g = 0;
	char **h;

	if (a == NULL || a[0] == 0)
		return (NULL);
	if (!b)
		b = " ";
	for (c = 0; a[c] != '\0'; c++)
		if (!isdlm(a[c], b) && (isdlm(a[c + 1], b) || !a[c + 1]))
			g++;

	if (g == 0)
		return (NULL);
	h = malloc((1 + g) * sizeof(char *));
	if (!h)
		return (NULL);
	for (c = 0, d = 0; d < g; d++)
	{
		while (isdlm(a[c], b))
			c++;
		e = 0;
		while (!isdlm(a[c + e], b) && a[c + e])
			e++;
		h[d] = malloc((e + 1) * sizeof(char));
		if (!h[d])
		{
			for (e = 0; e < d; e++)
				free(h[e]);
			free(h);
			return (NULL);
		}
		for (f = 0; f < e; f++)
			h[d][f] = a[c++];
		h[d][f] = 0;
	}
	h[d] = NULL;
	return (h);
}

/**
 * **strtow2 - function
 * @a: a
 * @b: b
 * Return: return
 */
char **strtow2(char *a, char b)
{
	int c, d, e, f, g = 0;
	char **h;

	if (a == NULL || a[0] == 0)
		return (NULL);
	for (c = 0; a[c] != '\0'; c++)
		if ((a[c] != b && a[c + 1] == b) ||
		    (a[c] != b && !a[c + 1]) || a[c + 1] == b)
			g++;
	if (g == 0)
		return (NULL);
	h = malloc((1 + g) * sizeof(char *));
	if (!h)
		return (NULL);
	for (c = 0, d = 0; d < g; d++)
	{
		while (a[c] == b && a[c] != b)
			c++;
		e = 0;
		while (a[c + e] != b && a[c + e] && a[c + e] != b)
			e++;
		h[d] = malloc((e + 1) * sizeof(char));
		if (!h[d])
		{
			for (e = 0; e < d; e++)
				free(h[e]);
			free(h);
			return (NULL);
		}
		for (f = 0; f < e; f++)
			h[d][f] = a[c++];
		h[d][f] = 0;
	}
	h[d] = NULL;
	return (h);
}


