/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:20:55 by ajari             #+#    #+#             */
/*   Updated: 2023/06/11 16:11:55 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ok(t_lst *m, int k)
{
	int	x;
	int	y;

	(k == 125) && (x = m->p.x - cos(m->t) * S, y = m->p.y - sin(m->t) * S);
	(k == 126) && (x = m->p.x + cos(m->t) * S, y = m->p.y + sin(m->t) * S);
	(k == 2) && (x = m->p.x + cos(m->t + PD) * S, y = m->p.y + sin(m->t + PD) * S);
	(k == 0) && (x = m->p.x - cos(m->t + PD) * S, y = m->p.y - sin(m->t + PD)
			* S);
	(k == 13) && (x = m->p.x - cos(m->t + PI) * S, y = m->p.y - sin(m->t + PI)
			* S);
	(k == 1) && (x = m->p.x + cos(m->t + PI) * S, y = m->p.y + sin(m->t + PI)
			* S);
	if (k == 126 || k == 125 || !k || k == 13 || k == 1 || k == 2)
	{
		(m->map[(int)((y + PM) / SQ)][(int)((x + PM) / SQ)] == '1') && (k = -1);
		(m->map[(int)((y + PM) / SQ)][(int)((x - PM) / SQ)] == '1') && (k = -1);
		(m->map[(int)((y - PM) / SQ)][(int)((x + PM) / SQ)] == '1') && (k = -1);
		(m->map[(int)((y - PM) / SQ)][(int)((x - PM) / SQ)] == '1') && (k = -1);
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