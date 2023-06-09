/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:21:45 by ajari             #+#    #+#             */
/*   Updated: 2023/06/08 13:48:55 by ajari            ###   ########.fr       */
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
			(k) && (m->p.x = i * SQ + SQ / 2, m->p.y = j * SQ + SQ / 2);
			i++;
		}
		j++;
	}
}

int	put_squart(t_lst m, t_pos p, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < SQ)
	{
		i = 0;
		while (i < SQ)
		{
			if (x * SQ + i - p.x <= 200 && y * SQ + j - p.y <= 200)
			{
				if (i && j)
					my_mlxput_pixel(m, x * SQ + i - p.x, y * SQ + j - p.y,
							WHITE);
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

	k = x % SQ;
	l = y % SQ;
	x = x / SQ - 5;
	y = y / SQ - 5;
	j = y;
	put_miniblack(m);
	while (abs(j - y) < 11)
	{
		i = x;
		while (abs(i - x) < 11)
		{
			if (i < m.sx && i >= 0 && j >= 0 && j < m.sy && p[j][i] == '1')
				put_squart(m, (t_pos){k, l}, i - x, j - y);
			i++;
		}
		j++;
	}
}