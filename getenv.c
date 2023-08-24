#include "shell.h"

/**
 * envirget - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **envirget(infot *info)
{
	if (!info->envrn || info->chenv)
	{
		info->envrn = strlstto(info->envir);
		info->chenv = 0;
	}

	return (info->envrn);
}

/**
 * ustenvrn - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int ustenvrn(infot *info, char *var)
{
	listst *node = info->envir;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = strtwth(node->s, var);
		if (p && *p == '=')
		{
			info->chenv = indxnddl(&(info->envir), i);
			i = 0;
			node = info->envir;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->chenv);
}

/**
 * stenvrn - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int stenvrn(infot *info, char *var, char *value)
{
	char *buf = NULL;
	listst *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(lnstr(var) + lnstr(value) + 2);
	if (!buf)
		return (1);
	cpystr(buf, var);
	catstr(buf, "=");
	catstr(buf, value);
	node = info->envir;
	while (node)
	{
		p = strtwth(node->s, var);
		if (p && *p == '=')
		{
			free(node->s);
			node->s = buf;
			info->chenv = 1;
			return (0);
		}
		node = node->next;
	}
	ndaddend(&(info->envir), buf, 0);
	free(buf);
	info->chenv = 1;
	return (0);
}

