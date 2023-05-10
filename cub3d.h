/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:53:24 by aahrach           #+#    #+#             */
/*   Updated: 2023/05/10 15:31:31 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <unistd.h>

typedef struct s_lst{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
	char	**map;
	char	orie;
}	t_lst;

///////////////////*  parsing  *////////////////////////////

void	ft_map(t_lst *list, char *str_map);
void	ft_eroor(char *str);
void	north(t_lst *list, char **tmp);
void	south(t_lst *list, char **tmp);
void	west(t_lst *list, char **tmp);
void	east(t_lst *list, char **tmp);
void	foort_ceiling(t_lst *list, char **tmp, char x, int i);
char	*read_line(char *name_file, int fd);
int		check_name_file(char *str);
void	fill_in_struct(t_lst *list, char *tmp);

////////////////////////////////////////////////////////////

#endif
