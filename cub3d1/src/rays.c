/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:36:20 by ajari             #+#    #+#             */
/*   Updated: 2023/05/24 09:23:24 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_wall(t_lst m, double x, double y)
{
	x = x / SQ;
	y = y / SQ;
	if (m.t > PI)
		y--;
	if (y < 0 || y > m.s_lin || x < 0 || x > m.len
		|| m.map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

void	cord_horizo(t_lst m, double *x, double *y)
{
	double	dx;
	double	dy;

	dy = -SQ;
	*y = (int)(m.p.x / SQ) * SQ;
	(m.t > 0 && m.t < PI) && (*y += SQ);
	(m.t > 0 && m.t < PI) && (dy = SQ);
	dx = fabs(dy / tan(m.t));
	*x = m.p.x + fabs((*y - m.p.y) / tan(m.t));
	(m.t > PD && m.t < 3 * PD) && (*x = m.p.x - fabs((*y - m.p.y) / tan(m.t)));
	(m.t > PD && m.t < 3 * PD) && (dx *= -1);
	cord("ray", *x, *y);
	printf(RED_T);
	cord("ply", m.p.x, m.p.y);
	printf(WHITE_T);
	while (1)
	{
		if (check_wall(m, *x, *y))
			break ;
		// cord("while", *x, *y);
		*y += dy;
		*x += dx;
	}
	(*y > m.s_lin * SQ) && (*y = (m.s_lin - 1) * SQ);
	(*x > m.len * SQ) && (*x = (m.len - 1) * SQ);
	(*x < 0) && (*x = 0);
	(*y < 0) && (*y = 0);
}

void	rays(t_lst *m, int color)
{
	(void)color;
	double h_x;
	double h_y;
	cord_horizo(*m, &h_x, &h_y);
	// printf("------------------->\n");
	// cord("ray", h_x, h_y);
	// cord("ply", m->p.x, m->p.y);
	draw_line(*m, m->p, (t_pos){h_x, h_y}, color);
}