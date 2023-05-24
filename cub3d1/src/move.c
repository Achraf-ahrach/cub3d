/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:20:55 by ajari             #+#    #+#             */
/*   Updated: 2023/05/23 18:11:56 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ok(t_lst *m, int k)
{
	int	x;
	int	y;

	(k == 125) && (x = m->p.x - cos(m->t) * SP, y = m->p.y - sin(m->t) * SP);
	(k == 126) && (x = m->p.x + cos(m->t) * SP, y = m->p.y + sin(m->t) * SP);
	(!k) && (x = m->p.x + cos(m->t + PD) * SP, y = m->p.y + sin(m->t + PD)
			* SP);
	(k == 2) && (x = m->p.x - cos(m->t + PD) * SP, y = m->p.y - sin(m->t + PD)
			* SP);
	(k == 1) && (x = m->p.x - cos(m->t + PI) * SP, y = m->p.y - sin(m->t + PI)
			* SP);
	(k == 13) && (x = m->p.x + cos(m->t + PI) * SP, y = m->p.y + sin(m->t + PI)
			* SP);
	if (k == 126 || k == 125 || !k || k == 13 || k == 1 || k == 2)
	{
		(m->map[(int)((y + PM) / SQ)][(int)((x + PM) / SQ)] == '1') && (k = -1);
		(m->map[(int)((y + PM) / SQ)][(int)((x - PM) / SQ)] == '1') && (k = -1);
		(m->map[(int)((y - PM) / SQ)][(int)((x + PM) / SQ)] == '1') && (k = -1);
		(m->map[(int)((y - PM) / SQ)][(int)((x - PM) / SQ)] == '1') && (k = -1);
	}
	return (k);
}

void	move_deri(t_lst *m, int k)
{
	if (k)
		m->map = 0;
}
void	var_angle(int k, t_lst *m)
{
	if (k == 123)
	{
		m->t -= 0.08726646259;
		(m->t < 0) && (m->t = 2 * PI);
	}
	if (k == 124)
	{
		m->t += 0.08726646259;
		(m->t > 2 * PI) && (m->t = 0);
	}
}