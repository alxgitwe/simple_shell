#include "shell.h"

/**
 * hsh - function
 * @a: a
 * @av: av
 * Return: return
 */
int hsh(infot *a, char **av)
{
	ssize_t b = 0;
	int c = 0;

	while (b != -1 && c != -2)
	{
		clrinf(a);
		if (itractv(a))
			_puts("$ ");
		errputchar(BUF_FLUSH);
		b = gtinpt(a);
		if (b != -1)
		{
			infset(a, av);
			c = builtnfnd(a);
			if (c == -1)
				cmdfnd(a);
		}
		else if (itractv(a))
			_putchar('\n');
		inffr(a, 0);
	}
	hstwrt(a);
	inffr(a, 1);
	if (!itractv(a) && a->sttus)
		exit(a->sttus);
	if (c == -2)
	{
		if (a->nmerr == -1)
			exit(a->sttus);
		exit(a->nmerr);
	}
	return (c);
}

/**
 * builtnfnd - function
 * @a: a
 * Return: return
 */
int builtnfnd(infot *a)
{
	int b, c = -1;
	tablebltn builtintbl[] = {
		{"exit", mext},
		{"env", menvr},
		{"help", mhlp},
		{"history", mhsty},
		{"setenv", mstenvir},
		{"unsetenv", mustenvir},
		{"cd", mchd},
		{"alias", alsmy},
		{NULL, NULL}
	};

	for (b = 0; builtintbl[b].tyype; b++)
		if (comparstr(a->argv[0], builtintbl[b].tyype) == 0)
		{
			a->lncnt++;
			c = builtintbl[b].func(a);
			break;
		}
	return (c);
}

/**
 * cmdfnd - function
 * @a: a
 * Return: return
 */
void cmdfnd(infot *a)
{
	char *b = NULL;
	int c, d;

	a->pth = a->argv[0];
	if (a->flglncnt == 1)
	{
		a->lncnt++;
		a->flglncnt = 0;
	}
	for (c = 0, d = 0; a->arg[c]; c++)
		if (!isdlm(a->arg[c], " \t\n"))
			d++;
	if (!d)
		return;

	b = pthfnd(a, gtenvir(a, "PATH="), a->argv[0]);
	if (b)
	{
		a->pth = b;
		cmdfrk(a);
	}
	else
	{
		if ((itractv(a) || gtenvir(a, "PATH=")
			|| a->argv[0][0] == '/') && cmdis(a, a->argv[0]))
			cmdfrk(a);
		else if (*(a->arg) != '\n')
		{
			a->sttus = 127;
			errprnt(a, "not found\n");
		}
	}
}

/**
 * cmdfrk - function
 * @a: a
 * Return: return
 */
void cmdfrk(infot *a)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(a->pth, a->argv, envirget(a)) == -1)
		{
			inffr(a, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(a->sttus));
		if (WIFEXITED(a->sttus))
		{
			a->sttus = WEXITSTATUS(a->sttus);
			if (a->sttus == 126)
				errprnt(a, "Permission denied\n");
		}
	}
}


