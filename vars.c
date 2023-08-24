#include "shell.h"

/**
 * chnis - test if current char in buffer is a chain delimeter
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int chnis(infot *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->typebuffercmd = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->typebuffercmd = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		info->typebuffercmd = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * chnchk - checks we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void chnchk(infot *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->typebuffercmd == CMD_AND)
	{
		if (info->sttus)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->typebuffercmd == CMD_OR)
	{
		if (!info->sttus)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * alsrplc - replaces an aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int alsrplc(infot *info)
{
	int i;
	listst *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = ndstrtw(info->als, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = str_chr(node->s, '=');
		if (!p)
			return (0);
		p = duplstr(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * vrsrplc - replaces vars in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int vrsrplc(infot *info)
{
	int i = 0;
	listst *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!comparstr(info->argv[i], "$?"))
		{
			rplcstrn(&(info->argv[i]),
				duplstr(nbrconv(info->sttus, 10, 0)));
			continue;
		}
		if (!comparstr(info->argv[i], "$$"))
		{
			rplcstrn(&(info->argv[i]),
				duplstr(nbrconv(getpid(), 10, 0)));
			continue;
		}
		node = ndstrtw(info->envir, &info->argv[i][1], '=');
		if (node)
		{
			rplcstrn(&(info->argv[i]),
				duplstr(str_chr(node->s, '=') + 1));
			continue;
		}
		rplcstrn(&info->argv[i], duplstr(""));

	}
	return (0);
}

/**
 * rplcstrn - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int rplcstrn(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

