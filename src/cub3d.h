/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:53:24 by aahrach           #+#    #+#             */
/*   Updated: 2023/06/07 16:22:51 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_pos
{
	double	x;
	double	y;
}			t_pos;

typedef struct s_lst
{
	int		x;
	int		y;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
	char	**map;
	char	orie;
	double	t;
	t_pos	p;
}			t_lst;

t_pos;
///////////////////*  parsing  *////////////////////////////

# define R 0xFF0000
# define B 0x0000FF
# define L 0xFFFF00
# define G 0x00FF00
# define K 0xffffff
# define S 25
# define SP 6
# define S_I 20
# difine

typedef struct s_data
{
	int		i;
	int		j;
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void		ft_map(t_lst *list, char *str_map);
void		ft_eroor(char *str);
void		north(t_lst *list, char **tmp);
void		south(t_lst *list, char **tmp);
void		west(t_lst *list, char **tmp);
void		east(t_lst *list, char **tmp);
void		foort_ceiling(t_lst *list, char **tmp, char x, int i);
char		*read_line(char *name_file, int fd);
int			check_name_file(char *str);
void		fill_in_struct(t_lst *list, char *tmp);
void		mini_map(t_lst *list);

////////////////////////////////////////////////////////////

#endif
