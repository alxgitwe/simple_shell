#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CMD_OR		1
#define CMD_AND		2
#define CMD_NORM	0
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
#define USElinegt 0
#define USE_STRTOK 0
#define CMD_CHAIN	3
#define HIST_FILE	".shell_history"
#define HIST_MAX	4096

extern char **environ;

/**
 * struct liststr - struct
 * @n: n
 * @s: s
 * @next: next
 */
typedef struct liststr
{
	int n;
	char *s;
	struct liststr *next;
} listst;

/**
 *struct infpass - struct
 *@arg: arg
 *@argv: argv
 *@pth: pth
 *@argc: argc
 *@lncnt: lncnt
 *@nmerr: nmerr
 *@flglncnt: flglncnt
 *@namefile: namefile
 *@envir: envir
 *@envrn: envrn
 *@hsty: hsty
 *@als: als
 *@chenv: chenv
 *@sttus: sttus
 *@buffercmd: buffercmd
 *@typebuffercmd: typebuffercmd
 *@rdfd: rdfd
 *@hstcnt: hstcnt
 */
typedef struct infpass
{
	char *arg;
	char **argv;
	char *pth;
	int argc;
	unsigned int lncnt;
	int nmerr;
	int flglncnt;
	char *namefile;
	listst *envir;
	listst *hsty;
	listst *als;
	char **envrn;
	int chenv;
	int sttus;
	char **buffercmd;
	int typebuffercmd;
	int rdfd;
	int hstcnt;
} infot;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct bltn - function
 *@tyype: tyype
 *@func: func
 */
typedef struct bltn
{
	char *tyype;
	int (*func)(infot *);
} tablebltn;


int hsh(infot *, char **);
int builtnfnd(infot *);
void cmdfnd(infot *);
void cmdfrk(infot *);
int cmdis(infot *, char *);
char *charsdupl(char *, int, int);
char *pthfnd(infot *, char *, char *);
int hsshloop(char **);
void errputs(char *);
int errputchar(char);
int fdput(char c, int fd);
int _putsfd(char *str, int fd);
int lnstr(char *);
int comparstr(char *, char *);
char *strtwth(const char *, const char *);
char *catstr(char *, char *);
char *cpystr(char *, char *);
char *duplstr(const char *);
void _puts(char *);
int _putchar(char);
char *strn_cpy(char *, char *, int);
char *strn_cat(char *, char *, int);
char *str_chr(char *, char);
char **strtw(char *, char *);
char **strtow2(char *, char);
char *stmem(char *, char, unsigned int);
void ffre(char **);
void *rloct(void *, unsigned int, unsigned int);
int bfr(void **);
int itractv(infot *);
int isdlm(char, char *);
int isaplph(int);
int atoii(char *);
int erratoii(char *);
void errprnt(infot *, char *);
int print_d(int, int);
char *nbrconv(long int, int, int);
void rmvcmnt(char *);
int mext(infot *);
int mchd(infot *);
int mhlp(infot *);
int mhsty(infot *);
int alsmy(infot *);
ssize_t gtinpt(infot *);
int linegt(infot *, char **, size_t *);
void hndlrsnt(int);
void clrinf(infot *);
void infset(infot *, char **);
void inffr(infot *, int);
char *gtenvir(infot *, const char *);
int menvr(infot *);
int mstenvir(infot *);
int mustenvir(infot *);
int ppenvirlst(infot *);
char **envirget(infot *);
int ustenvrn(infot *, char *);
int stenvrn(infot *, char *, char *);
char *gthistfl(infot *);
int hstwrt(infot *);
int hstrd(infot *);
int bldhistlst(infot *, char *, int);
int hstrnbr(infot *);
listst *ndadd(listst **, const char *, int);
listst *ndaddend(listst **, const char *, int);
size_t strprtlst(const listst *);
int indxnddl(listst **, unsigned int);
void lstfr(listst **);
size_t lenlst(const listst *);
char **strlstto(listst *);
size_t lstprt(const listst *);
listst *ndstrtw(listst *, char *, char);
ssize_t indxndgt(listst *, listst *);
int chnis(infot *, char *, size_t *);
void chnchk(infot *, char *, size_t *, size_t, size_t);
int alsrplc(infot *);
int vrsrplc(infot *);
int rplcstrn(char **, char *);

#endif

