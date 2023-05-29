/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:04:31 by ajari             #+#    #+#             */
/*   Updated: 2023/05/29 15:03:28 by ajari            ###   ########.fr       */
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
		if (!m->map[i++])
			break ;
	}
}

int	move_key(int k, t_lst *m)
{
	double	t;

	t = m->t;
	if (k == 53)
		exit(0);
	rays(*m, 0, 0, BLACK);
	var_angle(k, m);
	put_ply(m, m->p, BLACK);
	(ok(m, k) == 125) && (m->p.x -= cos(t) * S, m->p.y -= sin(t) * S);
	(ok(m, k) == 126) && (m->p.x += cos(t) * S, m->p.y += sin(t) * S);
	(ok(m, k) == 2) && (m->p.x -= cos(t + PD) * S, m->p.y -= sin(t + PD) * S);
	(!ok(m, k)) && (m->p.x += cos(t + PD) * S, m->p.y += sin(t + PD) * S);
	(ok(m, k) == 1) && (m->p.x -= cos(t + PI) * S, m->p.y -= sin(t + PI) * S);
	(ok(m, k) == 13) && (m->p.x += cos(t + PI) * S, m->p.y += sin(t + PI) * S);
	put_ply(m, m->p, YELLOW);
	rays(*m, 0, 0, GREEN);
	mlx_put_image_to_window(m->mx, m->wn, m->im.p, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_lst m;

	(void)ac;
	m.mx = mlx_init();
	fill_map(av[1], &m, open(av[1], O_RDONLY, 0777), 0);
	m.wn = mlx_new_window(m.mx, SQ * m.len, m.s_lin * SQ, "My Cub3D");
	m.im.p = mlx_new_image(m.mx, SQ * m.len, m.s_lin * SQ);
	m.im.ad = mlx_get_data_addr(m.im.p, &m.im.b_pxl, &m.im.ln_len, &m.im.edn);
	putwindow(&m, m.map, 0, 0);
	mlx_hook(m.wn, 2, 0, move_key, &m);
	mlx_loop(m.mx);
}