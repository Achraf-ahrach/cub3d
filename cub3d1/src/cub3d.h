/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:06:09 by ajari             #+#    #+#             */
/*   Updated: 2023/05/22 17:10:46 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef HEADER_H
#  define HEADER_H
#  include "libft/libft.h"
#  include <fcntl.h>
#  include <limits.h>
#  include <mlx.h>
#  include <stdio.h>
#  include <stdlib.h>
#  include <string.h>
#  include <unistd.h>

typedef struct s_pos
{
	double	x;
	double	y;
}			t_pos;
typedef struct s_im
{
	void	*im;
	void	*iad;
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
	char	**map;
	char	orie;
	int		s_lin;
	int		len;
	t_pos	p;

}			t_lst;
#  ifndef BUFFER_SIZE
#   define BUFFER_SIZE 1
#  endif

#  define RED 0xFF0000
#  define GREEN 0x00FF00
#  define BLUE 0x0000FF
#  define ORANGE 0xFFA500
#  define WHITE 0xFFFFFF
#  define MAGENTA 0x1E00F7
#  define CYAN 0x03C4D4
#  define YELLOW 0xFFF633
#  define WIE 1000
#  define HIE 800
#  define SQ 50
#  define PI 3.14159265359
#  define PD 1.57079632679
///////////////////////// --fonctions get_line-- /////////////////////////////
char		*get_next_line(int fd);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_strchr_index(const char *s, int c);
char		*ft_strjoin(const char *s1, const char *s2);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);

/////////////////////////////////////////////////////////////////////
# endif /* HEADER_H */

#endif