#ifndef LIFE_H
# define LIFE_H

# include <unistd.h>
# include <stdlib.h>


typedef struct s_env {
    int             w;
    int             h;
    unsigned char   *board;
    unsigned char   *next;
}               t_env;

/* Function Prototypes */
void    ft_putchar(char c);
int     count_neighbors(t_env *e, int x, int y);
void    step(t_env *e);
void    handle_input(t_env *e);

#endif