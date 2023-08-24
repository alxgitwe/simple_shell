#include "shell.h"

/**
 * mext - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int mext(infot *info)
{
	int exitcheck;

	if (info->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = erratoii(info->argv[1]);
		if (exitcheck == -1)
		{
			info->sttus = 2;
			errprnt(info, "Illegal number: ");
			errputs(info->argv[1]);
			errputchar('\n');
			return (1);
		}
		info->nmerr = erratoii(info->argv[1]);
		return (-2);
	}
	info->nmerr = -1;
	return (-2);
}

/**
 * mchd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int mchd(infot *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = gtenvir(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = gtenvir(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (comparstr(info->argv[1], "-") == 0)
	{
		if (!gtenvir(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(gtenvir(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = gtenvir(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		errprnt(info, "can't cd to ");
		errputs(info->argv[1]), errputchar('\n');
	}
	else
	{
		stenvrn(info, "OLDPWD", gtenvir(info, "PWD="));
		stenvrn(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * mhlp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int mhlp(infot *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}

