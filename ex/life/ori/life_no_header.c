#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_env {
	int w;
	int h;
	unsigned char *board;
	unsigned char *next;
} t_env;

void ft_putchar(char c) {
	write(1, &c, 1);
}

int count_neighbors(t_env *e, int x, int y) {
	int count = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0) continue;
			int nx = x + j;
			int ny = y + i;
			if (nx >= 0 && nx < e->w && ny >= 0 && ny < e->h) {
				// Strict check for the '1' bit
				if (e->board[ny * e->w + nx] == 1)
					count++;
			}
		}
	}
	return count;
}

void step(t_env *e) {
	int size = e->w * e->h;
	
	// Calculate next generation
	for (int y = 0; y < e->h; y++) {
		for (int x = 0; x < e->w; x++) {
			int neighbors = count_neighbors(e, x, y);
			int idx = y * e->w + x;
			if (e->board[idx] == 1)
				e->next[idx] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
			else
				e->next[idx] = (neighbors == 3) ? 1 : 0;
		}
	}
	// Copy next back to current
	for (int i = 0; i < size; i++) {
		e->board[i] = e->next[i];
	}
}

void handle_input(t_env *e) {
	int x = 0, y = 0, drawing = 0;
	unsigned char c;
	
	while (read(0, &c, 1) > 0) {
		if (c == 'x') drawing = !drawing;
		else if (c == 'w') y--;
		else if (c == 's') y++;
		else if (c == 'a') x--;
		else if (c == 'd') x++;
		// Ignore any other characters (like \n or garbage)
		
		if (x < 0) x = 0;
		if (x >= e->w) x = e->w - 1;
		if (y < 0) y = 0;
		if (y >= e->h) y = e->h - 1;
		
		if (drawing)
			e->board[y * e->w + x] = 1;
	}
}

int main(int ac, char **av) {
	if (ac != 4) return 0;

	// atoi can be risky; in a real exam, a custom ft_atoi with 
	// overflow protection is better, but this suffices for the logic.
	int w = atoi(av[1]);
	int h = atoi(av[2]);
	int iter = atoi(av[3]);

	if (w <= 0 || h <= 0 || iter < 0) return 0;

	t_env e;
	e.w = w;
	e.h = h;
	// Using unsigned char to prevent signed bit interference
	e.board = calloc(w * h, sizeof(unsigned char));
	e.next = calloc(w * h, sizeof(unsigned char));
	
	if (!e.board || !e.next) return 1;

	handle_input(&e);

	while (iter-- > 0)
		step(&e);

	for (int y = 0; y < e.h; y++) {
		for (int x = 0; x < e.w; x++) {
			ft_putchar(e.board[y * e.w + x] ? 'O' : ' ');
		}
		ft_putchar('\n');
	}

	free(e.board);
	free(e.next);
	return 0;
}