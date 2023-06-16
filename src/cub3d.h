/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:53:24 by aahrach           #+#    #+#             */
/*   Updated: 2023/06/16 12:16:32 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
// # include "../mlx/mlx.h"
// # include "../mlx/mlx_png.h"
// # include "../mlx/mlx_opengl.h"
// # include "../mlx/mlx_new_window.h"
// # include "../mlx/mlx_int.h"
# include "../mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
///////////////////*  parsing  *////////////////////////////
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x87CEEB
# define WHITE 0xFFFFFF
# define YELLOW 0xFFF633
# define BLACK 0x000000
# define WIE 1000
# define HIE 800
# define SQ 20
# define PI 3.14159265359
# define PD PI / 2
# define PL 6
# define PM PL / 2
# define VAR_ANGLE 0.2
# define SM SQ / 2
# define S 7

typedef struct s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct s_im
{
	void			*p;
	char			*ad;
	int				b_pxl;
	int				ln_len;
	int				edn;
}					t_im;

typedef struct s_textures
{
	void			*img;
	int				w;
	int				h;
	t_im			im;
}					t_textures;

typedef struct s_lst
{
	int				sx;
	int				sy;
	void			*mx;
	void			*wn;
	t_textures		*north;
	t_textures		*south;
	t_textures		*west;
	t_textures		*east;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				*f;
	int				*c;
	unsigned int	f_rgb;
	unsigned int	c_rgb;
	int				i;
	char			**map;
	char			orie;
	int				s_lin;
	int				len;
	double			t;
	t_pos			p;
	t_im			im;
	int				old_p;
}					t_lst;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
///////////////////////// --fonctions get_line-- ///////////////////
char				*get_next_line(int fd);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_strchr_index(const char *s, int c);
char				*ft_strjoin(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
////////////////////////////////////////////////////////////////////

///////////////////////// --fonctions cub-- ////////////////////////
void				my_mlxput_pixel(t_lst m, int x, int y, size_t color);
void				draw_line(t_lst m, t_pos p1, t_pos p2, int color);
int					check_wall(t_lst m, double x, double y, int k);
void				rays(t_lst m, double dh, double dv, int color);
int					put_squart(t_lst m, t_pos p, int x, int y);
void				putwindow(t_lst m, char **p, int x, int y);
void				get_positionplayer(t_lst *m, char **s);
double				get_angle(double t, double add, int i);
int					put_ply(t_lst m, t_pos p, int color);
void				cord(char *s, double x, double y);
void				var_angle(int k, t_lst *m);
int					move(int k, t_lst *m);
int					ok(t_lst *m, int k);
void				print(t_lst m);
////////////////////////////////////////////////////////////////////

void				foort_ceiling(t_lst *list, char **tmp, char x, int i);
void				fill_in_struct(t_lst *list, char *tmp);
char				*read_line(char *name_file, int fd);
void				ft_map(t_lst *list, char *str_map);
void				north(t_lst *list, char **tmp);
void				south(t_lst *list, char **tmp);
void				west(t_lst *list, char **tmp);
void				east(t_lst *list, char **tmp);
int					check_name_file(char *str);
t_lst				*list(int ac, char **env);
void				mini_map(t_lst *list);
void				ft_error(char *str);
////////////////////////////////////////////////////////////

#endif
