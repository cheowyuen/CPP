#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct s_map
{
	int		lines;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
}	t_map;

typedef struct s_square
{
	int	size;
	int	x;
	int	y;
}	t_square;

void	print_error(void)
{
	fprintf(stderr, "map error\n");
}

void	free_map(t_map *map)
{
	int	i;

	if (!map->grid)
		return ;
	i = 0;
	while (i < map->lines)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

int	parse_header(FILE *fp, t_map *map)
{
	if (fscanf(fp, "%d %c %c %c\n",
			&map->lines,
			&map->empty,
			&map->obstacle,
			&map->full) != 4)
		return (0);
	if (map->lines <= 0)
		return (0);
	if (!isprint((unsigned char)map->empty)
		|| !isprint((unsigned char)map->obstacle)
		|| !isprint((unsigned char)map->full))
		return (0);
	if (map->empty == map->obstacle
		|| map->empty == map->full
		|| map->obstacle == map->full)
		return (0);
	return (1);
}

int	is_better_same_size(t_square max, int size, int y, int x)
{
	int	new_top;
	int	new_left;
	int	old_top;
	int	old_left;

	if (size != max.size)
		return (0);
	new_top = y - size + 1;
	new_left = x - size + 1;
	old_top = max.y - max.size + 1;
	old_left = max.x - max.size + 1;
	if (new_top < old_top)
		return (1);
	if (new_top == old_top && new_left < old_left)
		return (1);
	return (0);
}

void	solve_bsq(t_map *map)
{
	int			**dp;
	t_square	max;
	int			i;
	int			j;
	int			min;

	dp = malloc(sizeof(int *) * map->lines);
	max.size = 0;
	max.x = 0;
	max.y = 0;
	i = 0;
	while (i < map->lines)
	{
		dp[i] = calloc(map->cols, sizeof(int));
		i++;
	}
	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->grid[i][j] == map->obstacle)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = 1;
			else
			{
				min = dp[i - 1][j];
				if (dp[i][j - 1] < min)
					min = dp[i][j - 1];
				if (dp[i - 1][j - 1] < min)
					min = dp[i - 1][j - 1];
				dp[i][j] = min + 1;
			}
			if (dp[i][j] > max.size
				|| is_better_same_size(max, dp[i][j], i, j))
			{
				max.size = dp[i][j];
				max.y = i;
				max.x = j;
			}
			j++;
		}
		i++;
	}
	i = max.y - max.size + 1;
	while (i <= max.y)
	{
		j = max.x - max.size + 1;
		while (j <= max.x)
		{
			map->grid[i][j] = map->full;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < map->lines)
	{
		fputs(map->grid[i], stdout);
		fputs("\n", stdout);
		free(dp[i]);
		i++;
	}
	free(dp);
}

int	process_map(FILE *fp)
{
	t_map	map;
	char	*line;
	size_t	cap;
	ssize_t	len;
	int		i;
	int		c;

	map.grid = NULL;
	map.lines = 0;
	map.cols = 0;
	line = NULL;
	cap = 0;
	if (!parse_header(fp, &map))
		return (print_error(), 0);
	map.grid = malloc(sizeof(char *) * map.lines);
	i = 0;
	while (i < map.lines)
	{
		len = getline(&line, &cap, fp);
		if (len <= 0)
			return (free(line), free_map(&map), print_error(), 0);
		if (line[len - 1] != '\n')
			return (free(line), free_map(&map), print_error(), 0);
		line[--len] = '\0';
		if (i == 0)
			map.cols = len;
		if (len <= 0 || len != map.cols)
			return (free(line), free_map(&map), print_error(), 0);
		map.grid[i] = malloc(len + 1);
		for (int j = 0; j < len; j++)
		{
			if (line[j] != map.empty && line[j] != map.obstacle)
				return (free(line), free_map(&map), print_error(), 0);
			map.grid[i][j] = line[j];
		}
		map.grid[i][len] = '\0';
		i++;
	}
	c = fgetc(fp);
	if (c != EOF)
		return (free(line), free_map(&map), print_error(), 0);
	solve_bsq(&map);
	free(line);
	free_map(&map);
	return (1);
}

int	main(int ac, char **av)
{
	FILE	*fp;
	int		i;

	if (ac == 1)
	{
		process_map(stdin);
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		fp = fopen(av[i], "r");
		if (!fp)
			print_error();
		else
		{
			process_map(fp);
			fclose(fp);
		}
		i++;
	}
	return (0);
}