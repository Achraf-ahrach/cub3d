/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:20:55 by ajari             #+#    #+#             */
/*   Updated: 2023/06/06 11:44:02 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ok(t_lst *m, int k)
{
	int	x;
	int	y;

	(k == 125) && (x = m->p.x - cos(m->t) * S, y = m->p.y - sin(m->t) * S);
	(k == 126) && (x = m->p.x + cos(m->t) * S, y = m->p.y + sin(m->t) * S);
	(!k) && (x = m->p.x + cos(m->t + PD) * S, y = m->p.y + sin(m->t + PD) * S);
	(k == 2) && (x = m->p.x - cos(m->t + PD) * S, y = m->p.y - sin(m->t + PD)
			* S);
	(k == 1) && (x = m->p.x - cos(m->t + PI) * S, y = m->p.y - sin(m->t + PI)
			* S);
	(k == 13) && (x = m->p.x + cos(m->t + PI) * S, y = m->p.y + sin(m->t + PI)
			* S);
	if (k == 126 || k == 125 || !k || k == 13 || k == 1 || k == 2)
	{
		(m->map[(int)((y + PM) / J)][(int)((x + PM) / J)] == '1') && (k = -1);
		(m->map[(int)((y + PM) / J)][(int)((x - PM) / J)] == '1') && (k = -1);
		(m->map[(int)((y - PM) / J)][(int)((x + PM) / J)] == '1') && (k = -1);
		(m->map[(int)((y - PM) / J)][(int)((x - PM) / J)] == '1') && (k = -1);
	}
	return (k);
}

void	var_angle(int k, t_lst *m)
{
	if (k == 123)
	{
		m->t -= VAR_ANGLE;
		(m->t < 0) && (m->t = 2 * PI);
	}
	if (k == 124)
	{
		m->t += VAR_ANGLE;
		(m->t > 2 * PI) && (m->t = 0);
	}
}