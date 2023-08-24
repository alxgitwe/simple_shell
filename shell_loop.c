#include "shell.h"

/**
 * hsh - main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(infot *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clrinf(info);
		if (itractv(info))
			_puts("$ ");
		errputchar(BUF_FLUSH);
		r = gtinpt(info);
		if (r != -1)
		{
			infset(info, av);
			builtin_ret = builtnfnd(info);
			if (builtin_ret == -1)
				cmdfnd(info);
		}
		else if (itractv(info))
			_putchar('\n');
		inffr(info, 0);
	}
	hstwrt(info);
	inffr(info, 1);
	if (!itractv(info) && info->sttus)
		exit(info->sttus);
	if (builtin_ret == -2)
	{
		if (info->nmerr == -1)
			exit(info->sttus);
		exit(info->nmerr);
	}
	return (builtin_ret);
}

/**
 * builtnfnd - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int builtnfnd(infot *info)
{
	int i, built_in_ret = -1;
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

	for (i = 0; builtintbl[i].tyype; i++)
		if (comparstr(info->argv[0], builtintbl[i].tyype) == 0)
		{
			info->lncnt++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * cmdfnd - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void cmdfnd(infot *info)
{
	char *path = NULL;
	int i, k;

	info->pth = info->argv[0];
	if (info->flglncnt == 1)
	{
		info->lncnt++;
		info->flglncnt = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!isdlm(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = pthfnd(info, gtenvir(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->pth = path;
		cmdfrk(info);
	}
	else
	{
		if ((itractv(info) || gtenvir(info, "PATH=")
			|| info->argv[0][0] == '/') && cmdis(info, info->argv[0]))
			cmdfrk(info);
		else if (*(info->arg) != '\n')
		{
			info->sttus = 127;
			errprnt(info, "not found\n");
		}
	}
}

/**
 * cmdfrk - forks a an exec thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void cmdfrk(infot *info)
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
		if (execve(info->pth, info->argv, envirget(info)) == -1)
		{
			inffr(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->sttus));
		if (WIFEXITED(info->sttus))
		{
			info->sttus = WEXITSTATUS(info->sttus);
			if (info->sttus == 126)
				errprnt(info, "Permission denied\n");
		}
	}
}

