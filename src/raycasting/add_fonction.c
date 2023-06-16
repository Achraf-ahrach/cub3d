/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:25:19 by ajari             #+#    #+#             */
/*   Updated: 2023/06/16 22:06:00 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_line(t_lst m, t_pos p1, t_pos p2, int color)
{
	while (p1.y < p2.y)
		my_mlxput_pixel(m, p1.x, p1.y++, color);
}
