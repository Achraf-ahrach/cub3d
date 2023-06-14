/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:28:34 by aahrach           #+#    #+#             */
/*   Updated: 2023/06/14 15:21:04 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int rgb(int *i)
{
    return ((i[0] * 256*256) + (i[1] * 256) + i[2]);
}
void	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
	exit(1);
}

// void	print_bit(int c)
// {
// 	int i = 0;
// 	while (i < 32)
// 	{
// 		if (i == 8 || i == 16 || i == 24)
// 			printf(" , ");
// 		printf("%d", (c & (INT_MIN)) == INT_MIN);
// 		c = c << 1;
// 		i++;
// 	}
// }

t_lst	*list(int ac, char **env)
{
	t_lst	*list;
	char	*map;
	char	*tmp;

	list = malloc(sizeof(t_lst));
	if (ac != 2 || check_name_file(env[1]))
		ft_error("Error: NAME FILE\n");
	map = read_line(env[1], 0);
	tmp = map;
	fill_in_struct(list, tmp);
	if (!list->map)
		ft_error("Error: THE MAP EMPTY !\n");
	while (list->map[list->sy])
		list->sy++;
	list->sx = ft_strlen(list->map[0]);
	list->c_rgb = rgb(list->c);
	list->f_rgb = rgb(list->f);
	return (free(map), list);
	//system("leaks cub3d");
}
