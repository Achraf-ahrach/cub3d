/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:06:09 by ajari             #+#    #+#             */
/*   Updated: 2023/05/29 15:03:05 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_pos
{
	double	x;
	double	y;
}			t_pos;

typedef struct s_im
{
	void	*p;
	char	*ad;
	int		b_pxl;
	int		ln_len;
	int		edn;
}			t_im;

typedef struct s_lst
{
	void	*mx;
	void	*wn;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
	int		i;
	char	**map;
	char	orie;
	int		s_lin;
	int		len;
	double	t;
	t_pos	p;
	t_im	im;

}			t_lst;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define ORANGE 0xFFA500
# define WHITE 0xFFFFFF
# define MAGENTA 0x1E00F7
# define CYAN 0x03C4D4
# define YELLOW 0xFFF633
# define BLACK 0x000000
# define WIE 1000
# define HIE 800
# define SQ 50
# define PI 3.14159265359
# define PD PI / 2
# define PL 6
# define PM PL / 2
# define SM SQ / 2
# define S 7
///////////////////////// --fonctions get_line-- ///////////////////
char		*get_next_line(int fd);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_strchr_index(const char *s, int c);
char		*ft_strjoin(const char *s1, const char *s2);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
////////////////////////////////////////////////////////////////////

///////////////////////// --fonctions cub-- ////////////////////////
void		my_mlxput_pixel(t_lst m, int x, int y, size_t color);
int			put_squart(t_lst m, int x, int y);
int			put_ply(t_lst *m, t_pos p, int color);
void		putwindow(t_lst *m, char **p, int x, int y);
int			move(int k, t_lst *m);
void		print(t_lst m);
void		var_angle(int k, t_lst *m);
int			ok(t_lst *m, int k);
void		draw_line(t_lst m, t_pos p1, t_pos p2, int color);
void		rays(t_lst m, double dh, double dv, int color);
void		cord(char *s, double x, double y);
////////////////////////////////////////////////////////////////////

#endif