/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:45:31 by ajari             #+#    #+#             */
/*   Updated: 2023/06/06 20:55:22 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlxput_pixel(t_lst m, int x, int y, size_t color)
{
	int	offset;

	if (x < 0 || y < 0 || x >= WIE || y >= HIE)
		return ;
	offset = y * m.im.ln_len + x * (m.im.b_pxl / 8);
	*((unsigned int *)(m.im.ad + offset)) = color;
}
