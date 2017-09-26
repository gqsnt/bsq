#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "bsq.h"



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
            return (0);
        ft_read_first_line(fd, info);
        set_param(info, &param, &max);
        ft_read_line(fd, buff, max.y, param.good);
        max.x = ft_strlen(buff[1]);
        bsq(buff, max, &max_bsq, param);
        print_bsq(buff, max_bsq, max, param);
    }
    close(fd);
    return (0);
}
