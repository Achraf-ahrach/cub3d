/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:36:20 by ajari             #+#    #+#             */
/*   Updated: 2023/06/08 11:45:44 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_wall(t_lst m, double x, double y, int k)
{
	x = x / SQ;
	y = y / SQ;
	printf("x = %d y = %d \n", (int)y, (int)x);
	if (m.t > PI && m.t < 2 * PI && k)
		y--;
	if (m.t > PD && m.t < 3 * PD && !k && x)
		x--;
	printf("x = %d y = %d \n", (int)y, (int)x);
	if (y < 0 || y > m.s_lin || x < 0 || x > m.len
		|| m.map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

double	cord_horizo(t_lst m, double *x, double *y)
{
	double	dx;
	double	dy;

	dy = -SQ;
	*y = (int)(m.p.y / SQ) * SQ;
	(m.t > 0 && m.t < PI) && (*y += SQ);
	(m.t > 0 && m.t < PI) && (dy = SQ);
	dx = fabs(dy / tan(m.t));
	*x = m.p.x + fabs((*y - m.p.y) / tan(m.t));
	(m.t > PD && m.t < 3 * PD) && (*x = fabs(m.p.x - (*y - m.p.y) / tan(m.t)));
	(m.t > PD && m.t < 3 * PD) && (dx *= -1);
	while (1)
	{
		if (check_wall(m, *x, *y, 1))
			break ;
		*y += dy;
		*x += dx;
	}
	(*y > m.s_lin * SQ) && (*y = (m.s_lin - 1) * SQ);
	(*x > m.len * SQ) && (*x = (m.len - 1) * SQ);
	(*x < 0) && (*x = 0);
	(*y < 0) && (*y = 0);
	return (sqrt(pow(m.p.x - *x, 2) + pow(m.p.y - *y, 2)));
}

double	cord_verti(t_lst m, double *x, double *y)
{
	double	dx;
	double	dy;

	dx = SQ;
	*x = (int)(m.p.x / SQ) * SQ;
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
	(*y > m.s_lin * SQ) && (*y = (m.s_lin - 1) * SQ);
	(*x > m.len * SQ) && (*x = (m.len - 1) * SQ);
	(*x < 0) && (*x = 0);
	(*y < 0) && (*y = 0);
	return (sqrt(pow(m.p.x - *x, 2) + pow(m.p.y - *y, 2)));
}

void	rays(t_lst m, double dh, double dv, int color)
{
	double	h_x;
	double	h_y;
	double	v_x;
	double	v_y;
	double	t;

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
		//(dh < dv) && (v_x = h_x, v_y = h_y);
		//dh = fabs((SQ * tan(PI / 3 / 2)) / dv);
		(dh < dv) && (dv = dh);
		dh = (2 * SQ * HIE / 2) / (dv);
		dh = fabs((SQ * 320) / (dv * cos(fabs(m.t - t))));
		//printf("befor dh =%d \n", (int)dh);
		if (dh + (HIE / 2 - dh / 2) > HIE)
			dh = HIE - 1; //fabs(HIE / 2 - dh / 2) - 1;
		//printf("after dh =%d \n", (int)dh);
		//cord(">", fabs(HIE / 2 - dh / 2), fabs(HIE / 2 - dh / 2 + dh));
		draw_line(m, (t_pos){m.i, fabs(HIE / 2 - dh / 2)}, (t_pos){m.i, fabs(HIE
					/ 2 - dh / 2 + dh)}, color);
		m.i++;
		m.t += (PI / 3) / WIE;
		(m.t > 2 * PI) && (m.t = 0);
	}
}
