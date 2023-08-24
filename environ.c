#include "shell.h"

/**
 * menvr - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int menvr(infot *info)
{
	strprtlst(info->envir);
	return (0);
}

/**
 * gtenvir - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *gtenvir(infot *info, const char *name)
{
	listst *node = info->envir;
	char *p;

	while (node)
	{
		p = strtwth(node->s, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * mstenvir - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int mstenvir(infot *info)
{
	if (info->argc != 3)
	{
		errputs("Incorrect number of arguements\n");
		return (1);
	}
	if (stenvrn(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * mustenvir - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int mustenvir(infot *info)
{
	int i;

	if (info->argc == 1)
	{
		errputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		ustenvrn(info, info->argv[i]);

	return (0);
}

/**
 * ppenvirlst - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int ppenvirlst(infot *info)
{
	listst *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		ndaddend(&node, environ[i], 0);
	info->envir = node;
	return (0);
}

