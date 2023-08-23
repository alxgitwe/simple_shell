#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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


extern char **environ;


/**
 * struct lists - singlylinkedlist
 * @a: int
 * @s: char
 * @next: next nod pointer
 */

typedef struct lists
{
        int a;
        char *s;
        struct lists *next;
} listst;



/**
 *struct pinfot - struct
 * @argmt: arg
 * @argv: arg
 * @pth: arg
 * @argcmt: arg
 * @lncount: arg
 * @ernm: arg
 * @lncntf: arg
 * @fnme: arg
 * @envr: arg
 * @envrn: arg
 * @hty: arg
 * @als: arg
 * @envcd: arg
 * @st: arg
 * @cmbuffer: arg
 * @cmbuffertye: arg
 * @rdfd: arg
 * @hstcnt: arg
 */
typedef struct pinfot
{
	char *argmt;
	char **argv;
	char *pth;
	int argcmt;
	unsigned int lncount;
	int ernm;
	int lncntf;
	char *fnme;
	listst *envr;
	listst *hty;
	listst *als;
	char **envrn;
	int envcd;
	int st;
	char **cmbuffer;
	int cmbuffertye;
	int rdfd;
	int hstcnt;


} infot;
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}


/**
 *struct builtin - contains a builtin string and related function
 *@func: function
 *@type: char
 *@func: the function
 */
typedef struct builtin
{
	int (*func)(infot *);
	char *type;
} builtin_t;


/* string_f.c */
int _putchar(char);
void _puts(char *);
char *strdupl(const char *);
char *strcopy(char *, char *);
char strln(char *);

/* string_f2.c */
char *startwith(const char *, const char *);
int strcomp(char *, char *);
char *strct(char *, char *);
char **strw(char *, char *);
char **strw2(char *, char);

/* string_f3.c */
char *strcher(char *, char);
char *strcopyn(char *, char *, int);
char *strcatn(char *, char *, int);

/* memo_f.c */
char *fillmemoset(char *, char, unsigned int);
int freep(void **);
void *reallocat(void *, unsigned int, unsigned int);
void freestring(char **);

/* functionsx1.c */
int alpha(int);
int at_oi(char *);
int err_atoi(char  *);
int delimt(char, char *);
int itrtive(infot *);


/* functionsx2.c */
void prterror(infot *, char *);
int prtdi(int, int);
void rmcmt(char *);
char *cvrtnmbr(long int, int, int);

/* functionsx1.c */
int alpha(int);
int at_oi(char *);
int err_atoi(char  *);
int delimt(char, char *);
int itrtive(infot *);


/* functionsx2.c */
void prterror(infot *, char *);
int prtdi(int, int);
void rmcmt(char *);
char *cvrtnmbr(long int, int, int);


/* lists1.c */
size_t llnt(const listst *);
ssize_t gndindex(listst *, listst *);
listst *ndstrt(listst *, char *, char);
size_t plst(const listst *);
char **litstr(listst *);

/* lists2.c */
listst *addnd(listst **, const char *, int);
void frlst(listst **);
int dlindeno(listst **, unsigned int);
size_t prlis(const listst *);
listst *addnend(listst **, const char *, int);

/* erfnc.c */
void erpts(char *);
int ptfdsptr(char, int);
int putsdsptr(char *, int);
int erptchr(char);


/* infoget.c module */
void infoclr(infot *);
void infofree(infot *, int);
void infost(infot *, char **);

/* envir2.c module */
char *envirget(infot *, const char *);
int menvirust(infot *);
int lipolenv(infot *);
int menvirst(infot *);
int envir(infot *);

/* envir.c module */
char **envget(infot *);
int envst(infot *, char *, char *);
int envust(infot *, char *);

/* fnhst.c */
char *hstflgt(infot *info);
int hstlstb(infot *a, char *b, int c);
int hstwt(infot *a);
int hstrnbr(infot *a);
int hstrd(infot *a);

/* chn.c */
int ischn(infot *, char *, size_t *);
void chkch(infot *, char *, size_t *, size_t, size_t);
int aliasrplc(infot *);
int varsrplc(infot *);
int strplc(char **, char *);

/* hashx1.c */
int hsh(infot *, char **);

#endif

