#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define UNUSED __attribute__((unused))
#define MAX_ARGS_COUNT 100
#define MAX_ARG_LEN 100

extern char **environ;

void flush(void);
void run_cmd(char *line_buffer, char *prog_name);
int parse_cmd(char *cmd, char **argv);
char *parse_path(char *cmd);

/* string functions */
void print_str(char *s);
size_t _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
char *_strchr(char *str, int ch);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, size_t n);
char *_strcat(char *dest, char *src);
char *_strdup(char *s);

/* environment functions */
void _env(void);
char *_getenv(char *var);
int _setenv(char *name, char *value,
							    int overwrite);


#endif
