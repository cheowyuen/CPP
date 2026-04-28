#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct s_map {
    int lines;
    int cols;
    char empty;
    char obs;
    char full;
    char **grid;
} t_map;

typedef struct s_square {
    int size;
    int x;
    int y;
} t_square;

void print_error() {
    fprintf(stderr, "map error\n");
}

void free_map(t_map *map) {
    if (!map->grid) return;
    for (int i = 0; i < map->lines; i++) free(map->grid[i]);
    free(map->grid);
}

int parse_header(FILE *fp, t_map *map) {
    if (fscanf(fp, "%d %c %c %c\n", &map->lines, &map->empty, &map->obs, &map->full) != 4)
        return 0;
    if (map->empty == map->obs || map->empty == map->full || map->obs == map->full)
        return 0;
    return 1;
}

void solve_bsq(t_map *map) {
    int **dp = malloc(sizeof(int *) * map->lines);
    t_square max = {0, 0, 0};

    for (int i = 0; i < map->lines; i++) {
        dp[i] = calloc(map->cols, sizeof(int));
        for (int j = 0; j < map->cols; j++) {
            if (map->grid[i][j] == map->obs) {
                dp[i][j] = 0;
            } else {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    int min = dp[i-1][j];
                    if (dp[i][j-1] < min) min = dp[i][j-1];
                    if (dp[i-1][j-1] < min) min = dp[i-1][j-1];
                    dp[i][j] = min + 1;
                }
                if (dp[i][j] > max.size) {
                    max.size = dp[i][j];
                    max.y = i;
                    max.x = j;
                }
            }
        }
    }

    // Draw the square
    for (int i = max.y - max.size + 1; i <= max.y; i++) {
        for (int j = max.x - max.size + 1; j <= max.x; j++) {
            map->grid[i][j] = map->full;
        }
    }

    // Print result
    for (int i = 0; i < map->lines; i++) {
        fputs(map->grid[i], stdout);
        fputs("\n", stdout);
        free(dp[i]);
    }
    free(dp);
}

void process_map(FILE *fp) {
    t_map map = {0, 0, 0, 0, 0, NULL};
    if (!parse_header(fp, &map) || map.lines <= 0) {
        print_error();
        return;
    }

    char *line = NULL;
    size_t cap = 0;
    map.grid = malloc(sizeof(char *) * map.lines);

    for (int i = 0; i < map.lines; i++) {
        int len = getline(&line, &cap, fp);
        if (len <= 0) { free_map(&map); free(line); print_error(); return; }
        if (line[len - 1] == '\n') line[--len] = '\0';
        
        if (i == 0) map.cols = len;
        if (len != map.cols || len == 0) { free_map(&map); free(line); print_error(); return; }

        map.grid[i] = malloc(len + 1);
        for (int j = 0; j < len; j++) {
            if (line[j] != map.empty && line[j] != map.obs) { free_map(&map); free(line); print_error(); return; }
            map.grid[i][j] = line[j];
        }
        map.grid[i][len] = '\0';
    }
    
    solve_bsq(&map);
    free_map(&map);
    free(line);
}

int main(int ac, char **av) {
    if (ac == 1) {
        process_map(stdin);
    } else {
        for (int i = 1; i < ac; i++) {
            FILE *fp = fopen(av[i], "r");
            if (!fp) { print_error(); continue; }
            process_map(fp);
            fclose(fp);
            if (i < ac - 1) printf("\n");
        }
    }
    return 0;
}