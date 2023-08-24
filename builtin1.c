#include "shell.h"

/**
 * mhsty - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int mhsty(infot *info)
{
	lstprt(info->hsty);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(infot *info, char *str)
{
	char *p, c;
	int ret;

	p = str_chr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = indxnddl(&(info->als),
		indxndgt(info->als, ndstrtw(info->als, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(infot *info, char *str)
{
	char *p;

	p = str_chr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (ndaddend(&(info->als), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(listst *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = str_chr(node->s, '=');
		for (a = node->s; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * alsmy - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int alsmy(infot *info)
{
	int i = 0;
	char *p = NULL;
	listst *node = NULL;

	if (info->argc == 1)
	{
		node = info->als;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = str_chr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(ndstrtw(info->als, info->argv[i], '='));
	}

	return (0);
}

