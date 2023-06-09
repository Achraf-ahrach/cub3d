/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:04:31 by ajari             #+#    #+#             */
/*   Updated: 2023/06/08 15:01:05 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	move_key(int k, t_lst *m)
{
	double	t;

	t = m->t;
	if (k == 53)
		exit(0);
	put_ply(*m, (t_pos){100, 100}, BLACK);
	rays(*m, 0, 0, BLACK);
	var_angle(k, m);
	(ok(m, k) == 125) && (m->p.x -= cos(t) * S, m->p.y -= sin(t) * S);
	(ok(m, k) == 126) && (m->p.x += cos(t) * S, m->p.y += sin(t) * S);
	(ok(m, k) == 2) && (m->p.x -= cos(t + PD) * S, m->p.y -= sin(t + PD) * S);
	(!ok(m, k)) && (m->p.x += cos(t + PD) * S, m->p.y += sin(t + PD) * S);
	(ok(m, k) == 1) && (m->p.x -= cos(t + PI) * S, m->p.y -= sin(t + PI) * S);
	(ok(m, k) == 13) && (m->p.x += cos(t + PI) * S, m->p.y += sin(t + PI) * S);
	rays(*m, 0, 0, BLUE);
	putwindow(*m, m->map, m->p.x, m->p.y);
	put_ply(*m, (t_pos){100, 100}, RED);
	mlx_put_image_to_window(m->mx, m->wn, m->im.p, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_lst *m;

	(void)ac;
	m = list(ac, av);
	m->mx = mlx_init();
	m->wn = mlx_new_window(m->mx, WIE, HIE, "My Cub3D");
	m->im.p = mlx_new_image(m->mx, WIE, HIE);
	m->im.ad = mlx_get_data_addr(m->im.p, &m->im.b_pxl, &m->im.ln_len,
			&m->im.edn);
	get_positionplayer(m, m->map);
	putwindow(*m, m->map, m->p.x, m->p.y);
	//my_drawline(m, (t_pos){0, 0}, (t_pos){1000, 800});
	//draw_line(m, (t_pos){0, 0 + 5}, (t_pos){1000, 800 + 5}, GREEN);
	mlx_put_image_to_window(m->mx, m->wn, m->im.p, 0, 0);
	rays(*m, 0, 0, BLUE);
	put_ply(*m, (t_pos){100, 100}, RED);
	mlx_hook(m->wn, 2, 0, move_key, m);
	mlx_loop(m->mx);
}