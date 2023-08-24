#include "shell.h"

/**
 * gthistfl - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containg history file
 */

char *gthistfl(infot *info)
{
	char *buf, *dir;

	dir = gtenvir(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (lnstr(dir) + lnstr(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	cpystr(buf, dir);
	catstr(buf, "/");
	catstr(buf, HIST_FILE);
	return (buf);
}

/**
 * hstwrt - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int hstwrt(infot *info)
{
	ssize_t fd;
	char *filename = gthistfl(info);
	listst *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->hsty; node; node = node->next)
	{
		_putsfd(node->s, fd);
		fdput('\n', fd);
	}
	fdput(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * hstrd - reads history from file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int hstrd(infot *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = gthistfl(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			bldhistlst(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		bldhistlst(info, buf + last, linecount++);
	free(buf);
	info->hstcnt = linecount;
	while (info->hstcnt-- >= HIST_MAX)
		indxnddl(&(info->hsty), 0);
	hstrnbr(info);
	return (info->hstcnt);
}

/**
 * bldhistlst - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int bldhistlst(infot *info, char *buf, int linecount)
{
	listst *node = NULL;

	if (info->hsty)
		node = info->hsty;
	ndaddend(&node, buf, linecount);

	if (!info->hsty)
		info->hsty = node;
	return (0);
}

/**
 * hstrnbr - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int hstrnbr(infot *info)
{
	listst *node = info->hsty;
	int i = 0;

	while (node)
	{
		node->n = i++;
		node = node->next;
	}
	return (info->hstcnt = i);
}

