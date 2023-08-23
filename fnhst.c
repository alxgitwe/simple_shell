#include "shell.h"

/**
 * hstflgt - function
 * @a: struct
 *
 * Return: return
 */
char *hstflgt(infot *a)
{
	char *buffer, *b;

	b = envirget(a, "HOME=");
	if (!b)
		return (NULL);
	buffer = malloc(sizeof(char) * (strlen(b) + strlen(HIST_FILE) + 2));
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	strcopy(buffer, b);
	strcat(buffer, "/");
	strcat(buffer, HIST_FILE);
	return (buffer);
}

/**
 * hstlstb - function
 * @a: struct
 * @b: char
 * @c: int
 *
 * Return: return
 */
int hstlstb(infot *a, char *b, int c)
{
	listst *d = NULL;

	if (a->hty)
		d = a->hty;
	addnend(&d, b, c);

	if (!a->hty)
		a->hty = d;
	return (0);
}


/**
 * hstwt - function
 * @a: struct
 *
 * Return: return
 */
int hstwt(infot *a)
{
	ssize_t b;
	char *c = hstflgt(a);
	listst *d = NULL;

	if (!c)
		return (-1);

	b = open(c, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(c);
	if (b == -1)
		return (-1);
	for (d = a->hty; d; d = d->next)
	{
		putsdsptr(d->s, b);
		ptfdsptr('\n', b);
	}
	ptfdsptr(BUF_FLUSH, b);
	close(b);
	return (1);
}



/**
 * hstrnbr - function
 * @a: struct
 *
 * Return: return
 */
int hstrnbr(infot *a)
{
	listst *b = a->hty;
	int c = 0;

	while (b)
	{
		b->a = c++;
		b = b->next;
	}
	return (a->hstcnt = c);
}



/**
 * hstrd - function
 * @a: struct
 *
 * Return: return
 */
int hstrd(infot *a)
{
	int b, c = 0, d = 0;
	ssize_t e, f, g = 0;
	struct stat h;
	char *buffer = NULL, *k = hstflgt(a);

	if (!k)
		return (0);

	e = open(k, O_RDONLY);
	free(k);
	if (e == -1)
		return (0);
	if (!fstat(e, &h))
		g = h.st_size;
	if (g < 2)
		return (0);
	buffer = malloc(sizeof(char) * (g + 1));
	if (!buffer)
		return (0);
	f = read(e, buffer, g);
	buffer[g] = 0;
	if (f <= 0)
		return (free(buffer), 0);
	close(e);
	for (b = 0; b < g; b++)
		if (buffer[b] == '\n')
		{
			buffer[b] = 0;
			hstlstb(a, buffer + c, d++);
			c = b + 1;
		}
	if (c != b)
		hstlstb(a, buffer + c, d++);
	free(buffer);
	a->hstcnt = d;
	while (a->hstcnt-- >= HIST_MAX)
		dlindeno(&(a->hty), 0);
	hstrnbr(a);
	return (a->hstcnt);
}
