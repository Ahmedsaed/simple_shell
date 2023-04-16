#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define UNUSED __attribute__((unused))
#define MAX_ARGS 100

extern char **environ;

void flush(void);
void run_cmd(char *line_buffer, char *prog_name);
int parse_cmd(char *cmd, char **argv);
char *parse_path(char *cmd);

/* string functions */
void print_str(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);

/* environment functions */
char *_getenv(char *var);

#endif
