#ifndef LIFE_H
#define LIFE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_env {
	int w;
	int h;
	unsigned char *board;
	unsigned char *next;
} t_env;

void parse_input(t_env *e);
void step(t_env *e);
int count_neighbors(t_env *e, int x, int y);

#endif