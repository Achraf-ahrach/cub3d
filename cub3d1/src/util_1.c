/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:45:31 by ajari             #+#    #+#             */
/*   Updated: 2023/05/23 09:11:50 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlxput_pixel(t_lst m, int x, int y, size_t color)
{
	int	offset;

	offset = y * m.im.ln_len + x * (m.im.b_pxl / 8);
	*((unsigned int *)(m.im.ad + offset)) = color;
}
