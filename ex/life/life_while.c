#include "life.h"

int count_neighbors(t_env *e, int x, int y) {
	int count = 0;
	int i = -1;

	while (i <= 1) {
		int j = -1;
		while (j <= 1) {
			if (!(i == 0 && j == 0)) {
				int nx = x + j;
				int ny = y + i;
				if (nx >= 0 && ny >= 0 && nx < e->w && ny < e->h) {
					if (e->board[ny * e->w + nx])
						count++;
				}
			}
			j++;
		}
		i++;
	}
	return count;
}

void step(t_env *e) {
	int y = 0;

	while (y < e->h) {
		int x = 0;
		while (x < e->w) {
			int neighbors = count_neighbors(e, x, y);
			int index = y * e->w + x;

			if (e->board[index])
				e->next[index] = ((neighbors == 2 || neighbors == 3) ? 1 : 0);
			else
				e->next[index] = (neighbors == 3 ? 1 : 0);

			x++;
		}
		y++;
	}

	int size = e->w * e->h;
	int i = 0;
	while (i < size) {
		e->board[i] = e->next[i];
		i++;
	}
}

void parse_input(t_env *e) {
	unsigned char c;
	int x = 0;
	int y = 0;
	int drawing = 0;

	while (read(0, &c, 1) > 0) {
		if (c == 'x')
			drawing = !drawing;
		else if (c == 'w')
			y--;
		else if (c == 's')
			y++;
		else if (c == 'a')
			x--;
		else if (c == 'd')
			x++;

		if (x < 0)
			x = 0;
		if (y < 0)
			y = 0;
		if (x >= e->w)
			x = e->w - 1;
		if (y >= e->h)
			y = e->h - 1;

		if (drawing)
			e->board[y * e->w + x] = 1;
	}
}

int main(int argc, char **argv) {
	if (argc < 4)
		return 1;

	int w = atoi(argv[1]);
	int h = atoi(argv[2]);
	int iter = atoi(argv[3]);

	if (w <= 0 || h <= 0 || iter < 0)
		return 1;

	t_env e;
	e.w = w;
	e.h = h;

	e.board = calloc(w * h, sizeof(unsigned char));
	if (!e.board)
		return 1;

	e.next = calloc(w * h, sizeof(unsigned char));
	if (!e.next) {
		free(e.board);
		return 1;
	}

	parse_input(&e);

	while (iter-- > 0)
		step(&e);

	int y = 0;
	while (y < e.h) {
		int x = 0;
		while (x < e.w) {
			putchar(e.board[y * e.w + x] ? 'O' : ' ');
			x++;
		}
		putchar('\n');
		y++;
	}

	free(e.board);
	free(e.next);
	return 0;
}