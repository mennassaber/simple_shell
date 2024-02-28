#ifndef SHELL_H
#define SHELL_H

/* Struct to hold shell information */
typedef struct info_s {
	char *arg;         /* Input argument */
	char **argv;       /* Argument vector */
	char *path;        /* Path */
	int argc;          /* Argument count */
	char *fname;       /* Filename */
	char **environ;    /* Environment variables */
	int readfd;        /* Read file descriptor */
	char **cmd_buf;    /* Command buffer */
	list_t *env;       /* Environment list */
	list_t *history;   /* History list */
	list_t *alias;     /* Alias list */
} info_t;

/* Function prototypes */
void clear_info(info_t *info);
void set_info(info_t *info, char **av);
void free_info(info_t *info, int all);

#endif /* SHELL_H */

