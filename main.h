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

void print_str(char *s);
void flush(void);
int run_cmd(char *line_buffer, char *prog_name);
int parse_cmd(char *cmd, char **argv);


#endif
