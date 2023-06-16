/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:25:19 by ajari             #+#    #+#             */
/*   Updated: 2023/06/16 21:52:06 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_line(t_lst m, t_pos p1, t_pos p2, int color)
{
	int	i;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = fabs(p2.x - p1.x);
	dy = fabs(p2.y - p1.y);
	sx = (p1.x < p2.x) ? 1 : -1;
	sy = (p1.y < p2.y) ? 1 : -1;
	err = dx - dy;
	while (1)
	{
		i = 0;
		my_mlxput_pixel(m, p1.x, p1.y, color);
		if ((int)p1.x == (int)p2.x && (int)p1.y == (int)p2.y)
			break ;
		e2 = 2 * err;
		if (e2 > -dy && (int)p1.x != (int)p2.x)
		{
			i = 1;
			err -= dy;
			p1.x += sx;
		}
		if (e2 < dx && (int)p1.y != (int)p2.y)
		{
			i = 1;
			err += dx;
			p1.y += sy;
		}
		if (!i)
			break ;
	}
}
