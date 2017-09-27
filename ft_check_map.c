#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "bsq.h"

int			ft_check2_map(t_coor max, int fd, char g, char b)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = 0;
	while (i <= max.y)
	{
		temp = 0;
		while(temp != '\n' && j <= max.x && read(fd, &temp, 1) >= 0)
		{
			if (temp != g && temp != b && temp != '\n' && temp != '\0')
				return (0);
			j = j + 1;
			if (i == max.y && j == max.x)
				return (i);
		}
		if (j - 1 != max.x)
			return(0);
		j = 0;
		i = i + 1;
	}
	return (0);
}


int			ft_check_map(char *name)
{
	int		fd;
	char	info[10];
	t_coor	max;
	int i;

	i = 0;
	fd = open(name, O_RDONLY);
	max.x = ft_read_first_line(name, &fd, info);
	max.y = ft_atoi(info);
	while (info[i] >= '0' && info[i] <= '9' && i <= ft_strlen(info))
		i = i + 1;
	if (max.y <= 0 || max.x <= 0)
		return (0);
	if (ft_check2_map(max, fd, info[i], info[i + 1]) == max.y)
		return (1);
	return (0);
}
