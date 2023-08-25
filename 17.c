#include "shell.h"

/**
 * input_buf - function
 * @a: a
 * @b: b
 * @c: c
 * Return: return
 */
ssize_t input_buf(infot *a, char **b, size_t *c)
{
	ssize_t d = 0;
	size_t e = 0;

	if (!*c)
	{
		free(*b);
		*b = NULL;
		signal(SIGINT, hndlrsnt);
#if USE_GETLINE
		d = getline(b, &e, stdin);
#else
		d = linegt(a, b, &e);
#endif
		if (d > 0)
		{
			if ((*b)[d - 1] == '\n')
			{
				(*b)[d - 1] = '\0';
				d--;
			}
			a->flglncnt = 1;
			rmvcmnt(*b);
			bldhistlst(a, *b, a->hstcnt++);
			{
				*c = d;
				a->buffercmd = b;
			}
		}
	}
	return (d);
}

/**
 * gtinpt - function
 * @a: a
 * Return: return
 */
ssize_t gtinpt(infot *a)
{
	static char *b;
	static size_t c, d, e;
	ssize_t f = 0;
	char **g = &(a->arg), *p;

	_putchar(BUF_FLUSH);
	f = input_buf(a, &b, &e);
	if (f == -1)
		return (-1);
	if (e)
	{
		d = c;
		p = b + c;

		chnchk(a, b, &d, c, e);
		while (d < e)
		{
			if (chnis(a, b, &d))
				break;
			d++;
		}

		c = d + 1;
		if (c >= e)
		{
			c = e = 0;
			a->typebuffercmd = CMD_NORM;
		}

		*g = p;
		return (lnstr(p));
	}

	*g = b;
	return (f);
}

/**
 * read_buf - function
 * @a: a
 * @b: b
 * @c: c
 * Return: return
 */
ssize_t read_buf(infot *a, char *b, size_t *c)
{
	ssize_t d = 0;

	if (*c)
		return (0);
	d = read(a->rdfd, b, READ_BUF_SIZE);
	if (d >= 0)
		*c = d;
	return (d);
}

/**
 * linegt - function
 * @a: a
 * @b: b
 * @d: d
 * Return: return
 */
int linegt(infot *a, char **b, size_t *d)
{
	static char e[READ_BUF_SIZE];
	static size_t f, g;
	size_t h;
	ssize_t k = 0, m = 0;
	char *q = NULL, *r = NULL, *t;

	q = *b;
	if (q && d)
		m = *d;
	if (f == g)
		f = g = 0;

	k = read_buf(a, e, &g);
	if (k == -1 || (k == 0 && g == 0))
		return (-1);

	t = str_chr(e + f, '\n');
	h = t ? 1 + (unsigned int)(t - e) : g;
	r = rloct(q, m, m ? m + h : h + 1);
	if (!r)
		return (q ? free(q), -1 : -1);

	if (m)
		strn_cat(r, e + f, h - f);
	else
		strn_cpy(r, e + f, h - f + 1);

	m += h - f;
	f = h;
	q = r;

	if (d)
		*d = m;
	*b = q;
	return (m);
}

/**
 * hndlrsnt - function
 * @a: a
 * Return: return
 */
void hndlrsnt(__attribute__((unused))int a)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}


