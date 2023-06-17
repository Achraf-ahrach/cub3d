/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 01:52:27 by aahrach           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/17 10:39:50 by aahrach          ###   ########.fr       */
=======
/*   Updated: 2023/06/17 10:55:09 by ajari            ###   ########.fr       */
>>>>>>> 542690b92e3f9c59b8e72bdb726055d6cecb2b9f
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	texters(t_lst m, double dh, double x, double y)
{
	t_p	p;

	p.direction = NULL;
	p.y = 0;
	if (ft_has_wall(m, x, y + 0.005) && !ft_has_wall(m, x, y - 0.005))
		p.direction = m.west;
	else if (ft_has_wall(m, x + 0.005, y) && !ft_has_wall(m, x - 0.005, y))
		p.direction = m.east;
	else if (ft_has_wall(m, x - 0.005, y) && !ft_has_wall(m, x + 0.005, y))
		p.direction = m.south;
	else
		p.direction = m.north;
	p.offy = p.direction->h / dh;
	p.start = ceil(HI / 2 - dh / 2);
	p.end = p.start + dh;
<<<<<<< HEAD
	printf("x = %f, y = %f\n", v_x, v_y);
	exit (0);
	p.x = (int)(p.direction->w * ((v_x + v_y) / SQ)) % (p.direction->w);
=======
	p.x = (int)(p.direction->w * ((x + y) / SQ)) % (p.direction->w);
>>>>>>> 542690b92e3f9c59b8e72bdb726055d6cecb2b9f
	while (p.start < p.end)
	{
		p.color = get_color(p.direction, p.x, p.y);
		my_mlxput_pixel(m, m.i, p.start, p.color);
		p.y += p.offy;
		p.start++;
	}
}
