#include "shell.h"



/**
 * _putchar - function
 * @s: char
 *
 * Return: return
 */

int _putchar(char s)
{
	static char buffer[WRITE_BUF_SIZE];

	static int a;

	if (a >= WRITE_BUF_SIZE || s == BUF_FLUSH)
	{
		write(1, buffer, a);
		a = 0;
	}

	if (!(s == BUF_FLUSH))
	{
		buffer[a++] = s;
	} return (1);

}

/**
 * _puts - function
 * @s: char
 *
 * Return: return
 */

void _puts(char *s)
{
	int a = 0;

	if (!s)
		return;
	while (s[a] != '\0')
	{
		_putchar([a]);
		a++;
	}
}

/**
 * strdupl - function
 * @s: char
 *
 * Return: return
 */

char *strdupl(const char *s)
{
	char *str;
	int a = 0;

	if (s == NULL)
		return (NULL);
	while (*s++)
		a++;
	str = malloc((a + 1) * sizeof(char));
	if (!str)
		return (NULL);
	for (a++; a--;)
		str[a] = *--s;
	return (str);

}

/**
 * strcopy - function
 * @str1: char
 * @str2: char
 *
 * Return: return
 */
char *strcopy(char *str1, char *str2)
{
	int a = 0;

	if (str2 == 0 || str1 == str2)
		return (str1);
	while (str2[a])
	{
		str1[a] = str2[a];
		a++;
	} str1[a] = 0;
	return (str1);

}

/**
 * strlen - functioon
 * @str: char
 *
 * Return: return
 */
char strlen(char *str)
{
	int a;

	a = 0;

	if (!str)
		return (0);
	while (*str++)
		a++;
	return (a);

}
