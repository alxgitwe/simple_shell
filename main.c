#include "shell.h"

/**
 * main - function
 * @ac: arg count
 * @av: arg vector
 * Return: return
 */


int main(int ac, char **av)
{

	int b = 2;
	infot a[] = { INFO_INIT };

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (b)
		: "r" (b));

	if (!(ac != 2))
	{
		b = open(av[1], O_RDONLY);
		if (b == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				erpts(av[0]);
				erpts(": 0: Can't open ");
				erpts(av[1]);
				erptchr('\n');
				erptchr(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		a->rdfd = b;
	}
	lipolenv(a);
	hstrd(a);
	hsh(a, av);
	return (EXIT_SUCCESS);
}

