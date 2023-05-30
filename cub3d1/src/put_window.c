/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:21:45 by ajari             #+#    #+#             */
/*   Updated: 2023/05/29 18:04:01 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	put_squart(t_lst m, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < SQ - 1)
	{
		i = 0;
		while (i < SQ - 1)
		{
			my_mlxput_pixel(m, x * SQ + i, y * SQ + j, WHITE);
			i++;
		}
		j++;
	}
	return (0);
}

int	put_ply(t_lst *m, t_pos p, int color)
{
	int	i;
	int	j;

	p.x -= PM;
	p.y -= PM;
	j = p.y;
	while (p.y - j < PL)
	{
		i = p.x;
		while (p.x - i < PL)
			my_mlxput_pixel(*m, p.x++, p.y, color);
		p.x = i;
		p.y++;
	}
	return (0);
}

void	putwindow(t_lst *m, char **p, int x, int y)
{
	int k;

	while (p[y])
	{
		x = 0;
		while (p[y][x])
		{
			k = 0;
			(p[y][x] == 'S') && (k = 1, m->t = 3 * PD);
			(p[y][x] == 'N') && (k = 1, m->t = PD);
			(p[y][x] == 'E') && (k = 1, m->t = PI);
			(p[y][x] == 'W') && (k = 1, m->t = 0);
			//(p[y][x] == '1') && (put_squart(*m, x, y));
			(k) && (m->p.x = x * SQ + SM, m->p.y = y * SQ + SM);
			//(k) && (put_ply(m, m->p, YELLOW));
			x++;
		}
		y++;
	}
	//mlx_put_image_to_window(m->mx, m->wn, m->im.p, 0, 0);
}