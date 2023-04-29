#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define UNUSED __attribute__((unused))
#define MAX_ARGS_COUNT 1000
#define MAX_ARG_LEN 1000
#define PATH_MAX 4096

extern char **environ;
extern char *prog_name;
extern int status_code;
extern int hist;

/* Parsers */
int parse_cmd(char *cmd, char **argv);
char *parse_path(char *cmd);
void split_cmds(char *buffer, char *separator, char **cmd, char **rest);

/* Built-in shell functions */
int exit_shell(char *line_buffer, char **argv);
void _env(void);
char *format_tilde(char *str);
int change_dir(char *dir);
int alias(char **tokens);

/* string functions */
size_t _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
char *_strchr(char *str, int ch);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, size_t n);
char *_strcat(char *dest, char *src);
char *_strdup(char *s);
char *_substr(char *src, int m, int n);
int _atoi(char *str);
char *_itoa(int num);
int is_numeric(char *s);
int is_digit(char c);

/* getline functions */
int _getline(char **lineptr, size_t *n, int stream);

/* environment functions */
int setup_env(void);
int _getenvLen(void);
void free_env(void);
char *_getenv(char *var);
int _setenv(char *name, char *value);
int _unsetenv(char *name);

/* memory functions */
void _memcpy(void *dest, void *src, size_t n);
void *_realloc(void *ptr, unsigned int old_size,
		unsigned int new_size);
void *_memchr(char *s, char c, int n);
void *_calloc(size_t count, size_t size);
void *_recalloc(void *ptr, unsigned int old_size,
		unsigned int new_size);

/* print functions */
void print_str(char *s);
void print_err(char *s);

/* shell handlers */
void handle_variables(char **argv);
void handle_aliases(char **argv);

/* error handling */
void error_127(char *cmd);
void error_126(char *cmd);
void error_exit(char *value);
void error_cd(char *dir);

#endif
