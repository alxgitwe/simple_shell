#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

/* chaining */

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_CHAIN       3
#define CMD_AND		2

/* cvrt nmbr */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2


/* buffers */
#define BUF_FLUSH -1
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024

/* getlinge */
#define HIST_FILE	".hsh_history"
#define HIST_MAX	4096
#define USE_GETLINE 0
#define USE_STRTOK 0


/**
 *struct builtin - contains a builtin string and related function
 *@func: function
 *@type: char
 *@func: the function
 */
typedef struct builtin
{
	int (*func)(info_t *);
	char *type;
} builtin_t;


/* string_f.c */
int _putchar(char);
void _puts(char *);
char *strdupl(const char *);
char *strcopy(char *, char *);
char strlen(char *);

/* string_f2.c */
char *startwith(const char *, const char *);
int strcomp(char *, char *);
char *strcat(char *, char *);
char strw(char *, char *);
char strw2(char *, char);

/* string_f3.c */
char *strcher(char *, char);
char *strcopyn(char *, char *, int);
char *strcatn(char *, char *, int);






#endif

