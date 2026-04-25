
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwong <cwong@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:12:19 by cwong             #+#    #+#             */
/*   Updated: 2025/02/03 13:12:21 by cwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void process_buffer(char *buffer, int *line_start, int *end_detected, int *i)
{
    int j;

    j = *line_start;
    while (j < *i)
    {
        if (buffer[j] == '\n' || (j >= 2 && buffer[j - 2] == 'E' && buffer[j - 1] == 'N' && buffer[j] == 'D'))
        {
            //write(1, buffer + *line_start, j - *line_start + 1);
            if (j >= 2 && buffer[j - 2] == 'E' && buffer[j - 1] == 'N' && buffer[j] == 'D')
            {
                *end_detected = 1;
                return;
            }
            *line_start = j + 1;
        }
        j++;
    }
}

void shift_buffer(char *buffer, int *i, int *line_start)
{
    int k;
    int remaining;

    remaining = *i - *line_start;
    if (remaining > 0)
    {
        k = 0;
        while (k < remaining)
        {
            buffer[k] = buffer[*line_start + k];
            k++;
        }
        *i = remaining;
        *line_start = 0;
    }
    else
    {
        *i = 0;
        *line_start = 0;
    }
}

void read_from_stdin(void)
{
    char buffer[4096];
    ssize_t bytes_read;
    int end_detected;
    int i;
    int line_start;

    end_detected = 0;
    i = 0;
    line_start = 0;
    write(1, "Enter the map (type 'END' to finish):\n", 37);
    while ((bytes_read = read(0, buffer + i, sizeof(buffer) - 1 - i)) > 0)
    {
        i += bytes_read;
        buffer[i] = '\0';
        process_buffer(buffer, &line_start, &end_detected, &i);
        if (end_detected)
            break;
        if (i == sizeof(buffer) - 1)
            shift_buffer(buffer, &i, &line_start);
    }
    if (bytes_read == -1)
        write(1, "map error\n", 6);
}

int	main(int argc, char **argv)
{
	int row = 9;
	int col = 27;
    int i;
    int j;
	int **map;
    int **map2;

	if (argc < 2)
	{
		read_from_stdin();
		return (0);
	}
	map = (int **)malloc(row * sizeof(int *));
	i = 0;
	while (i < row)
	{
		map[i] = (int *)malloc(col * sizeof(int));
		j = 0;
		while (j < col)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	map[1][4] = -1;
	map[2][12] = -1;
	map[4][4] = -1;
	map[5][15] = -1;
	map[7][6] = -1;
	map[7][21] = -1;
	map[8][2] = -1;
	map[8][10] = -1;
	ft_find_largest_square(map, row, col, ".ox");
    map2 = (int **)malloc(5 * sizeof(int *));
    i = 0;
    while (i < 5)
	{
		map2[i] = (int *)malloc(5 * sizeof(int));
		i++;
	}
    int data[5][5] = {{0, -1, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {-1, -1, -1, 0, 0}, {0, 0, 0, 0, 0}};
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            map2[i][j] = data[i][j];
        }
    }
    ft_find_largest_square(map2, 5, 5, ".ox");
	ft_free_memory_int(map, row);
	ft_free_memory_int(map2, 5);
	return (0);
}
