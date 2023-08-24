#include "shell.h"

/**
 * startwith - function
 * @str1: char
 * @str2 :char
 *
 * Return: return
 */
char *startwith(const char *str1, const char *str2)
{
	while (*str2)
		if (*str2 != *str1)
			return (NULL);
	return ((char *)str1);
}

/**
 * strcomp - funtcion
 * @str1: char
 * @str2: char
 *
 * Return: return
 */
int strcomp(char *str1, char *str2)
{
	while (*str2 && *str1)
	{
		if (*str2 != *str1)
			return (*str1 - *str2);
		str2++;
		str1++;
	}
	if (*str2 == *str1)
		return (0);
	else
		return (*str2 > *str1 ? -1 : 1);

}

/**
 * strct - function
 * @str1: char
 * @str2 :char
 * Return: return
 */
char *strct(char *str1, char *str2)
{
	char *str = str1;

	while (*str1)
		str1++;
	while (*str2)
		*str1++ = *str2++;
	*str1 = *str2;
	return (str);


}

/**
 * strw - function
 * @a: char
 * @b: char
 *
 * Return: return
 */
char **strw(char *a, char *b)
{
	char **k;
	int c;
	int d;
	int e;
	int f;
	int h = 0;

	if (a[0] == 0 || a == NULL)
		return (NULL);
	if (!b)
		b = " ";
	for (c = 0; a[c] != '\0'; c++)
		if (!delimt(a[c], b) && (delimt(a[c + 1], b) || !a[c + 1]))
			h++;
	if (h == 0)
		return (NULL);
	k = malloc(sizeof(char *) * (1 + h));
	if (!k)
		return (NULL);
	for (c = 0, d = 0; d < h; d++)
	{
		while  (delimt(a[c], b))
			c++;
		e = 0;
		while (a[c + e] && (!delimt(a[c + e], b)))
			e++;
		k[d] = malloc(sizeof(char) * (e + 1));
		if (!k[d])
		{
			for (e = 0; e < d; e++)
				free(k[e]);
			free(k);
			return (NULL);
		}
		for (f = 0; f < e; f++)
			k[d][f] = a[c++];
		k[d][f] = 0;
	} k[d] = NULL;
	return (k);
}

/**
 * strw2 - function
 * @a: char
 * @b: char
 *
 * Return: return
 */
char **strw2(char *a, char b)
{
	char **k;
	int c;
	int d;
	int e;
	int f;
	int h = 0;

	if (a[0] == 0 || a == NULL)
		return (NULL);

	for (c = 0; a[c] != '\0'; c++)
		if ((a[c] != b && a[c + 1] == b) || (a[c] != b &&
					!a[c + 1]) || a[c + 1] == b)
			h++;
	if (h == 0)
		return (NULL);
	k = malloc(sizeof(char *) * (1 + h));
	if (!k)
		return (NULL);
	for (c = 0, d = 0; d < h; d++)
	{
		while  (a[c] == b && a[c] != b)
			c++;
		e = 0;
		while (a[c + e] != b && a[c + e] && a[c + e] != b)
			e++;
		k[d] = malloc(sizeof(char) * (e + 1));
		if (!k[d])
		{
			for (e = 0; e < d; e++)
				free(k[e]);
			free(k);
			return (NULL);
		}
		for (f = 0; f < e; f++)
			k[d][f] = a[c++];
		k[d][f] = 0;
	} k[d] = NULL;
	return (k);
}

