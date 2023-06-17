/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:36:20 by ajari             #+#    #+#             */
/*   Updated: 2023/06/17 10:09:31 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	cord_horizo(t_lst m, double *x, double *y)
{
	double	dx;
	double	dy;

	dy = -SQ;
	*y = ((int)(m.p.y / SQ)) * SQ;
	(m.t > 0 && m.t < PI) && (*y += SQ);
	(m.t > 0 && m.t < PI) && (dy = SQ);
	dx = fabs(dy / tan(m.t));
	*x = m.p.x + fabs((*y - m.p.y) / tan(m.t));
	(m.t > PD && m.t < 3 * PD) && (*x = m.p.x - fabs((*y - m.p.y) / tan(m.t)));
	(m.t > PD && m.t < 3 * PD) && (dx *= -1);
	while (1)
	{
		if (check_wall(m, *x, *y, 1))
			break ;
		*y += dy;
		*x += dx;
	}
	(*y > m.sy * SQ) && (*y = (m.sy - 1) * SQ);
	(*x > m.sx * SQ) && (*x = (m.sx - 1) * SQ);
	(*x < 0) && (*x = 0);
	(*y < 0) && (*y = 0);
	return (sqrt(pow(m.p.x - *x, 2) + pow(m.p.y - *y, 2)));
}

double	cord_verti(t_lst m, double *x, double *y)
{
	double	dx;
	double	dy;

	dx = SQ;
	*x = ((int)(m.p.x / SQ)) * SQ;
	(m.t < PD || m.t > 3 * PD) && (*x += SQ);
	(m.t > PD && m.t < 3 * PD) && (dx = -SQ);
	dy = fabs(dx * tan(m.t));
	*y = m.p.y - fabs((*x - m.p.x) * tan(m.t));
	(m.t > 0 && m.t < PI) && (*y = m.p.y + fabs((*x - m.p.x) * tan(m.t)));
	(m.t > PI) && (dy *= -1);
	while (1)
	{
		if (check_wall(m, *x, *y, 0))
			break ;
		*y += dy;
		*x += dx;
	}
	(*y > m.sy * SQ) && (*y = (m.sy - 1) * SQ);
	(*x > m.sx * SQ) && (*x = (m.sx - 1) * SQ);
	(*x < 0) && (*x = 0);
	(*y < 0) && (*y = 0);
	return (sqrt(pow(m.p.x - *x, 2) + pow(m.p.y - *y, 2)));
}

unsigned int	get_color(t_textures *direction, int x, int y)
{
	int	offset;

	if (x < 0 || y < 0 || x >= direction->w || y >= direction->h)
		return (YELLOW);
	offset = y * direction->im.ln_len + x * (direction->im.b_pxl / 8);
	return (*((unsigned int *)(direction->im.ad + offset)));
}

int	ft_has_wall(t_lst m, int x, int y)
{
	if (m.map[y / SQ][x / SQ] == '1')
		return (1);
	else
		return (0);
}

void	texters(t_lst m, double dh, double v_x, double v_y)
{
	double			start;
	double			end;
	int				x;
	float			y;
	float			offy;
	unsigned int	color;
	t_textures		*direction;

	direction = NULL;
	y = 0;
	if (ft_has_wall(m, v_x, v_y + 0.005) && !ft_has_wall(m, v_x, v_y - 0.005))
		direction = m.west;
	else if (ft_has_wall(m, v_x + 0.005, v_y) && !ft_has_wall(m, v_x - 0.005,
				v_y))
		direction = m.east;
	else if (ft_has_wall(m, v_x - 0.005, v_y) && !ft_has_wall(m, v_x + 0.005,
				v_y))
		direction = m.south;
	else
		direction = m.north;
	offy = direction->h / dh;
	start = ceil(HIE / 2 - dh / 2);
	end = start + dh;
	x = (int)(direction->w * ((v_x + v_y) / SQ)) % (direction->w);
	while (start < end)
	{
		color = get_color(direction, x, y);
		my_mlxput_pixel(m, m.i, start, color);
		y += offy;
		start++;
	}
}

void	rays(t_lst m, double dh, double dv, double t)
{
	double	h_x;
	double	h_y;
	double	v_x;
	double	v_y;

	m.i = WIE / 2;
	t = m.t;
	while (--m.i)
	{
		m.t -= (PI / 3) / WIE;
		(m.t < 0) && (m.t = 2 * PI);
	}
	while (m.i < WIE)
	{
		dh = cord_horizo(m, &h_x, &h_y);
		dv = cord_verti(m, &v_x, &v_y);
		(dh < dv) && (dv = dh, v_x = h_x, v_y = h_y);
		dh = ceil(fabs((SQ * 320) / (dv * cos(fabs(m.t - t))))) * 2;
		draw_line(m, (t_pos){m.i, 0}, (t_pos){m.i, ceil(fabs(HIE / 2 - dh
						/ 2))}, m.c_rgb);
		texters(m, dh, v_x, v_y);
		draw_line(m, (t_pos){m.i, ceil(fabs(HIE / 2 - dh / 2 + dh))},
				(t_pos){m.i, HIE - 1}, m.f_rgb);
		m.i++;
		m.t += (PI / 3) / WIE;
		(m.t > 2 * PI) && (m.t = 0);
	}
}
