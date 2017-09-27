#ifndef BSQ_H
# define BSQ_H

typedef struct	s_coor
{
	int			x;
	int			y;
	int			size;
}	t_coor;

typedef struct	s_char
{
	char		good;
	char		block;
	char		wildcard;
}		t_char;

int		ft_read_first_line(char *name, int *fd, char *info);
int		ft_check2_map(t_coor max, int fd, char g, char b);
int		ft_check_map(char *name);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
char	**malloc_tab(char **tab, t_coor max);
int		check_line(char **tab, t_coor coor, int size, t_char param);
int		check_col(char **tab, t_coor coor, int size, t_char param);
t_coor	*set_max_bsq(t_coor *max_bsq, t_coor coor, int temp);
void	print_bsq(char **buff,t_coor max_bsq, t_coor max, t_char param);
t_coor	*bsq_search(char **tab, t_coor max, t_coor *max_bsq, t_char param);
int		bsq_size(char **tab, t_coor max, t_coor coor, t_char param);

#endif
