#include "shell.h"

/**
 * bfr - function
 * @a: a
 * Return: return
 */
int bfr(void **a)
{
	if (a && *a)
	{
		free(*a);
		*a = NULL;
		return (1);
	}
	return (0);
}


