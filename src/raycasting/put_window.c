/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:21:45 by ajari             #+#    #+#             */
/*   Updated: 2023/06/07 16:18:14 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_positionplayer(t_lst *m, char **s)
{
	int	k;
	int	i;
	int	j;

	j = 0;
	while (s[j])
	{
		i = 0;
		while (s[j][i])
		{
			k = 0;
			(s[j][i] == 'S') && (m->t = PD, k = 1);
			(s[j][i] == 'N') && (m->t = 3 * PD, k = 1);
			(s[j][i] == 'E') && (m->t = 0, k = 1);
			(s[j][i] == 'W') && (m->t = PI, k = 1);
			(k) && (m->p.x = i * J + J / 2, m->p.y = j * J + J / 2);
			i++;
		}
		j++;
	}
}

int	put_squart(t_lst m, t_pos p, int x, int y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < J)
	{
		i = 0;
		while (i < J)
		{
			if (x * J + i - p.x <= 200 && y * J + j - p.y <= 200)
			{
				if (i && j)
					my_mlxput_pixel(m, x * J + i - p.x, y * J + j - p.y, color);
				else
					my_mlxput_pixel(m, x * J + i - p.x, y * J + j - p.y, BLACK);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	put_ply(t_lst m, t_pos p, int color)
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
			my_mlxput_pixel(m, p.x++, p.y, color);
		p.x = i;
		p.y++;
	}
	mlx_put_image_to_window(m.mx, m.wn, m.im.p, 0, 0);
	return (0);
}
void	put_miniblack(t_lst m)
{
	int	i;
	int	j;

	i = 0;
	while (i < 200)
	{
		j = 0;
		while (j < 200)
			my_mlxput_pixel(m, i, j++, BLACK);
		i++;
	}
}
void	my_drawline(t_lst m, t_pos p1, t_pos p2)
{
	float	a;
	float	b;

	a = (p1.y - p2.y) / (p1.x - p2.x);
	b = -a * p1.x + p1.y;
	while (p1.x != p2.x && p1.y != p1.y)
	{
		p1.y = a * p1.x + b;
		my_mlxput_pixel(m, ceil(p1.x), ceil(p1.y), ORANGE);
		p1.x++;
	}
}
void	putwindow(t_lst m, char **p, int x, int y)
{
	int k;
	int l;
	int i;
	int j;

	k = x % J;
	l = y % J;
	x = x / J - 5;
	y = y / J - 5;
	j = y;
	put_miniblack(m);
	while (abs(j - y) < 11)
	{
		i = x;
		while (abs(i - x) < 11)
		{
			printf("%d\n", abs(i - x));
			if (i < m.len && i >= 0 && j >= 0 && j < m.s_lin && p[j][i] == '1')
				put_squart(m, (t_pos){k, l}, i - x, j - y, WHITE);
			else
				put_squart(m, (t_pos){k, l}, i - x, j - y, BLACK);
			i++;
		}
		j++;
	}
}