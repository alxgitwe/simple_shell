#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */
ssize_t input_buf(infot *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		/*bfr((void **)info->buffercmd);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, hndlrsnt);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = linegt(info, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0'; /* remove trailing newline */
				r--;
			}
			info->flglncnt = 1;
			rmvcmnt(*buf);
			bldhistlst(info, *buf, info->hstcnt++);
			/* if (str_chr(*buf, ';')) is this a command chain? */
			{
				*len = r;
				info->buffercmd = buf;
			}
		}
	}
	return (r);
}

/**
 * gtinpt - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t gtinpt(infot *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len)	/* we have commands left in the chain buffer */
	{
		j = i; /* init new iterator to current buf position */
		p = buf + i; /* get pointer for return */

		chnchk(info, buf, &j, i, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (chnis(info, buf, &j))
				break;
			j++;
		}

		i = j + 1; /* increment past nulled ';'' */
		if (i >= len) /* reached end of buffer? */
		{
			i = len = 0; /* reset position and length */
			info->typebuffercmd = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (lnstr(p)); /* return length of current command */
	}

	*buf_p = buf; /* else not a chain, pass back buffer from linegt() */
	return (r); /* return length of buffer from linegt() */
}

/**
 * read_buf - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t read_buf(infot *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->rdfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * linegt - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int linegt(infot *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = str_chr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = rloct(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		strn_cat(new_p, buf + i, k - i);
	else
		strn_cpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * hndlrsnt - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void hndlrsnt(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}

