/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:21:45 by ajari             #+#    #+#             */
/*   Updated: 2023/06/06 12:41:21 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	put_squart(t_lst m, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < J - 1)
	{
		i = 0;
		while (i < J - 1)
		{
			my_mlxput_pixel(m, x * J + i, y * J + j, WHITE);
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
	printf("%d %d \n", (int )p.x, (int)p.y);
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

void	putwindow(t_lst *m, char **p, int x, int y, int init)
{
	int k;

	while (p[y])
	{
		x = 0;
		while (p[y][x])
		{
			k = 0;
			(p[y][x] == 'S' && init) && (k = 1, m->t = 3 * PD);
			(p[y][x] == 'N' && init) && (k = 1, m->t = PD);
			(p[y][x] == 'E' && init) && (k = 1, m->t = PI);
			(p[y][x] == 'W' && init) && (k = 1, m->t = 0);
			(p[y][x] == '1') && (put_squart(*m, x, y));
			(k && init) && (m->p.x = x * J + J / 2, m->p.y = y * J + J / 2);
			(k && init) && (put_ply(m, m->p, RED));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(m->mx, m->wn, m->im.p, 0, 0);
}