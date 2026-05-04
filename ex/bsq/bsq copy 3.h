#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

typedef struct s_map {
	char **grid;
	int lines;
	int cols;
	char empty;
	char obstacle;
	char full;
} t_map;

typedef struct s_square {
	int size;
	int x;
	int y;
} t_square;

void print_error(void);
void free_map(t_map *map);
int parse_header(FILE *fp, t_map *map);
int process_map(FILE *fp);
int solve_bsq(t_map *map);
int is_better_same_size(t_square max, int size, int y, int x);

#endif