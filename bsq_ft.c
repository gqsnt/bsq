#include "bsq.h"

int bsq_size(char **tab, t_coor max, t_coor coor, t_char param)
{
    int     size;
    int     i;
    int     j;
    int     error;

    size = 0;
    i = coor.y;
    j = coor.x;
    error = 0;
    if (tab[coor.y][coor.x] == param.block)
        return (0);
    while(size + coor.x < max.x && size + coor.y < max.y && error == 0)
    {
        if (check_line(tab, coor, size, param) + check_col(tab, coor, size, param) != 0)
        {
            return (size);
        }
        size = size + 1;
    }
    return (size);
}

t_coor    *bsq(char **tab, t_coor max, t_coor *max_bsq, t_char param)
{
    int i;
    int j;
    int temp;
    t_coor coor;

    i = 0;
    j = 0;
    temp = 0;
    while (i < max.y)
    {
        while (j < max.x)
        {   coor.x = j;
            coor.y = i;
            temp = bsq_size(tab, max, coor, param);
            if (temp > max_bsq->size)
            {
                set_max_bsq(max_bsq, coor, temp);
            }
            j = j + 1;
        }
    j = 0;
    i = i + 1;
    }
    return (max_bsq);
}

void    print_bsq(char **buff,t_coor max_bsq, t_coor max, t_char param)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < max_bsq.size)
    {
        while (j < max_bsq.size)
        {
            buff[max_bsq.y + i][max_bsq.x + j] = param.wildcard;
            j = j + 1;
        }
        j = 0;
        i = i + 1;
    }
    i = 0;
    while (i < max.y)
    {
        ft_putstr(buff[i]);
        ft_putchar('\n');
        i = i + 1;
    }
}
