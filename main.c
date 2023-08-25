#include "shell.h"

/**
 * main - function
 * @ac: ac
 * @av: av
 * Return: return
 */
int main(int ac, char **av)
{
	infot a[] = { INFO_INIT };
	int b = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (b)
		: "r" (b));

	if (ac == 2)
	{
		b = open(av[1], O_RDONLY);
		if (b == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				errputs(av[0]);
				errputs(": 0: Can't open ");
				errputs(av[1]);
				errputchar('\n');
				errputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		a->rdfd = b;
	}
	ppenvirlst(a);
	hstrd(a);
	hsh(a, av);
	return (EXIT_SUCCESS);
}


