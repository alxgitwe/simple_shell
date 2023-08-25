#include "shell.h"

/**
 * gthistfl - function
 * @a: a
 * Return: return
 */

char *gthistfl(infot *a)
{
	char *b, *c;

	c = gtenvir(a, "HOME=");
	if (!c)
		return (NULL);
	b = malloc(sizeof(char) * (lnstr(c) + lnstr(HIST_FILE) + 2));
	if (!b)
		return (NULL);
	b[0] = 0;
	cpystr(b, c);
	catstr(b, "/");
	catstr(b, HIST_FILE);
	return (b);
}

/**
 * hstwrt - function
 * @a: a
 * Return: return
 */
int hstwrt(infot *a)
{
	ssize_t b;
	char *c = gthistfl(a);
	listst *d = NULL;

	if (!c)
		return (-1);

	b = open(c, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(c);
	if (b == -1)
		return (-1);
	for (d = a->hsty; d; d = d->next)
	{
		_putsfd(d->s, b);
		fdput('\n', b);
	}
	fdput(BUF_FLUSH, b);
	close(b);
	return (1);
}

/**
 * hstrd - function
 * @a: a
 * Return: return
 */
int hstrd(infot *a)
{
	int b, c = 0, d = 0;
	ssize_t e, f, g = 0;
	struct stat st;
	char *h = NULL, *k = gthistfl(a);

	if (!k)
		return (0);

	e = open(k, O_RDONLY);
	free(k);
	if (e == -1)
		return (0);
	if (!fstat(e, &st))
		g = st.st_size;
	if (g < 2)
		return (0);
	h = malloc(sizeof(char) * (g + 1));
	if (!h)
		return (0);
	f = read(e, h, g);
	h[g] = 0;
	if (f <= 0)
		return (free(h), 0);
	close(e);
	for (b = 0; b < g; b++)
		if (h[b] == '\n')
		{
			h[b] = 0;
			bldhistlst(a, h + c, d++);
			c = b + 1;
		}
	if (c != b)
		bldhistlst(a, h + c, d++);
	free(h);
	a->hstcnt = d;
	while (a->hstcnt-- >= HIST_MAX)
		indxnddl(&(a->hsty), 0);
	hstrnbr(a);
	return (a->hstcnt);
}

/**
 * bldhistlst - function
 * @a: a
 * @b: b
 * @c: c
 * Return: return
 */
int bldhistlst(infot *a, char *b, int c)
{
	listst *d = NULL;

	if (a->hsty)
		d = a->hsty;
	ndaddend(&d, b, c);

	if (!a->hsty)
		a->hsty = d;
	return (0);
}

/**
 * hstrnbr - function
 * @a: a
 * Return: return
 */
int hstrnbr(infot *a)
{
	listst *b = a->hsty;
	int c = 0;

	while (b)
	{
		b->n = c++;
		b = b->next;
	}
	return (a->hstcnt = c);
}


