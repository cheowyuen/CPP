#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>

void	ft_find_largest_square(int **map, int row, int col, char *characters);
void	ft_allocate_result(char ***result, int row, int col);
void	ft_fill_map(int **map, int row, int col, int *largest);
void	ft_find_largest(int **map, int row, int col, int largest);
void	ft_print_result(char **result, int row, int col);
int	ft_min(int a, int b, int c);
void	ft_mark_square(int **map, int row, int col, int largest);
void	ft_free_memory(char **grid, int row);
void	ft_free_memory_int(int **grid, int row);

#endif