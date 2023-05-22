/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:04:31 by ajari             #+#    #+#             */
/*   Updated: 2023/05/22 17:19:06 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_map(char *name, t_lst *m, int fd, int i)
{
	if (fd < 0)
		exit(ft_putendl_fd("error in mapfile", 2));
	while (get_next_line(fd))
		i++;
	m->map = malloc(sizeof(char *) * (i + 1));
	m->s_lin = i;
	m->len = 0;
	close(fd);
	fd = open(name, O_RDONLY, 0777);
	i = 0;
	while (1)
	{
		m->map[i] = get_next_line(fd);
		(m->len < (int)ft_strlen(m->map[i])) && (m->len = ft_strlen(m->map[i]));
		if (!m->map[i])
			break ;
	}
}

int	main(int ac, char **av)
{
	t_lst	m;

	(void)ac;
	m.mx = mlx_init();
	fill_map(av[1], &m, open(av[1], O_RDONLY, 0777), 0);
	mlx_new_window(m.mx, SQ * m.len, m.s_lin * SQ, "My Cub3D");
	mlx_loop(m.mx);
	printf("Hello World\n");
}
