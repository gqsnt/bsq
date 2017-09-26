#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "bsq.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i = i + 1;
    }
}

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i = i + 1;
    return (i);
}

int		ft_atoi(const char *str)
{
	int i;
	int nbr;
	int negative;

	nbr = 0;
	negative = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (-nbr);
	else
		return (nbr);
}

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

int    is_bsq(char tab[200][200], t_coor coor, int size, t_char param)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < size)
    {
        while (j < size)
        {
            if (tab[coor.y + i][coor.x + j] == param.block)
                return (0);
            j = j + 1;
        }
        j = 0;
        i = i + 1;
    }
    return (1);
}

int bsq_size(char tab[200][200], t_coor max, t_coor coor, t_char param)
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

t_coor     set_max_bsq(t_coor *max_bsq, t_coor coor, int temp)
{
    max_bsq->x = coor.x;
    max_bsq->y = coor.y;
    max_bsq->size = temp;
}


t_coor    *bsq(char tab[200][200], t_coor max, t_coor *max_bsq, t_char param)
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

char **ft_read_line(int fd, char buff[200][200], int size, char good)
{
    char temp;
    int i;
    int j;
    int err;

    i = 0;
    j = 0;
    err = 1;
    temp = good;
    while(i < size && err != 0)
    {
            err = read(fd, &temp, 1);
            if (temp == '\n')
            {
                buff[i][j] = '\0';
                i = i + 1;
                j = 0;
                if (i > size)
                    return(buff);
            }
            else
            {
                buff[i][j] = temp;
                j = j + 1;
            }
    }
    return (buff);
}

void    print_bsq(char buff[200][200],t_coor max_bsq, t_coor max, t_char param)
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

char *ft_read_first_line(int fd, char *info)
{
    int i;
    char temp;

    i = 0;
    temp = '0';
    while(temp != '\n')
    {
        read(fd, &temp, 1);
        info[i] = temp;
        i = i + 1;
    }
    return (info);
}

t_char  *set_param(char *info, t_char *param, t_coor *max)
{
    int i;

    i = 0;
    max->y = ft_atoi(info);
    while (info[i] >= '0' && info[i] <= '9')
        i = i + 1;
    param->good = info[i];
    param->block = info[i + 1];
    param->wildcard = info[i + 2];

    return (param);
}

int main(int argc, char **argv)
{
    int fd;
    char buff[200][200];
    char info[10];
    t_char param;
    t_coor max_bsq;
    t_coor max;

    max_bsq.x = 0;
    max_bsq.y = 0;
    max_bsq.size = 0;
    if (argc >= 1)
    {
        fd = open("C:/Users/gab/Documents/c/bsq/bin/Debug/grid1", O_RDONLY);
        if (fd == -1)
            return (2);
        ft_read_first_line(fd, info);
        set_param(info, &param, &max);
        ft_read_line(fd, buff, max.y, param.good);
        max.x = ft_strlen(buff[1]);
        bsq(buff, max, &max_bsq, param);
        print_bsq(buff, max_bsq, max, param);
    }
    close(fd);
    return (1);
}
