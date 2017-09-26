#include "bsq.h"

int check_line(char tab[200][200], t_coor coor, int size, t_char param)
{
    int i;

    i = 0;
    while (i <= size)
    {
        if (tab[coor.y + size][coor.x + i] == param.block)
            return (1);
        i = i + 1;
    }
    return (0);
}

int check_col(char tab[200][200], t_coor coor, int size, t_char param)
{
    int i;

    i = 0;
    while (i <= size)
    {
        if (tab[coor.y + i][coor.x + size] == param.block)
            return (1);
        i = i + 1;
    }
    return (0);
}

t_coor     set_max_bsq(t_coor *max_bsq, t_coor coor, int temp)
{
    max_bsq->x = coor.x;
    max_bsq->y = coor.y;
    max_bsq->size = temp;
}
