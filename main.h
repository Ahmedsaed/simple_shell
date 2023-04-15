#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define UNUSED __attribute__((unused))

void print_str(char *s);
void flush(void);


#endif
