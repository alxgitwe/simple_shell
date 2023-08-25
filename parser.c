#include "shell.h"

/**
 * cmdis - function
 * @a: a
 * @b: b
 * Return: return
 */
int cmdis(infot *a, char *b)
{
	struct stat st;

	(void)a;
	if (!b || stat(b, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * charsdupl - function
 * @a: a
 * @b: b
 * @c: c
 * Return: return
 */
char *charsdupl(char *a, int b, int c)
{
	static char buffer[1024];
	int d = 0, e = 0;

	for (e = 0, d = b; d < c; d++)
		if (a[d] != ':')
			buffer[e++] = a[d];
	buffer[e] = 0;
	return (buffer);
}

/**
 * pthfnd - function
 * @a: a
 * @b: b
 * @c: c
 * Return: return
 */
char *pthfnd(infot *a, char *b, char *c)
{
	int d = 0, e = 0;
	char *f;

	if (!b)
		return (NULL);
	if ((lnstr(c) > 2) && strtwth(c, "./"))
	{
		if (cmdis(a, c))
			return (c);
	}
	while (1)
	{
		if (!b[d] || b[d] == ':')
		{
			f = charsdupl(b, e, d);
			if (!*f)
				catstr(f, c);
			else
			{
				catstr(f, "/");
				catstr(f, c);
			}
			if (cmdis(a, f))
				return (f);
			if (!b[d])
				break;
			e = d;
		}
		d++;
	}
	return (NULL);
}


