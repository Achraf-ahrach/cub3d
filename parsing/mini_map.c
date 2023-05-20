/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:24:22 by aahrach           #+#    #+#             */
/*   Updated: 2023/05/20 11:20:18 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_position(t_lst *list, char find, int *y, int *x)
{
	int	i;
	int	j;

	j = -1;
	while (list->map[++j])
	{
		i = -1;
		while (list->map[j][++i])
		{
			if (list->map[j][i] == find)
			{
				*y = j;
				*x = i;
			}
		}
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	my_mlx_put_image_to_window(t_data *data, int color, int x, int y)
{
	int	ny;
	int	nx;

	ny = y;
	while (ny < y + S_I)
	{
		nx = x;
		while (nx < x + S_I)
		{
			my_mlx_pixel_put(data, nx, ny, color);
			nx++;
		}
		ny++;
	}
}

void	img_mini_map(t_lst *list, t_data *d, int len_x, int len_y)
{
	d->y = list->y - 5;
	while (d->y < list->y + 6)
	{
		d->x = list->x - 5;
		d->i = 0;
		while (d->x < list->x + 6)
		{
			if (d->y < 0 || d->x < 0 || d->x >= len_x || d->y >= len_y)
				my_mlx_put_image_to_window(d, K, d->i * S_I, d->j * S_I);
			else if (list->map[d->y][d->x] == '1')
				my_mlx_put_image_to_window(d, R, d->i * S_I, d->j * S_I);
			else if (list->map[d->y][d->x] == '0')
				my_mlx_put_image_to_window(d, G, d->i * S_I, d->j * S_I);
			else if (list->map[d->y][d->x] == ' ')
				my_mlx_put_image_to_window(d, B, d->i * S_I, d->j * S_I);
			else if (list->map[d->y][d->x] == list->orie)
				my_mlx_put_image_to_window(d, L, d->i * S_I, d->j * S_I);
			d->x++;
			d->i++;
		}
		d->j++;
		d->y++;
	}
}

void	mini_map(t_lst *list)
{
	t_data	data;
	int		len_x;
	int		len_y;

	get_position(list, list->orie, &list->y, &list->x);
	data.i = 0;
	data.j = 0;
	len_y = -1;
	len_x = ft_strlen(list->map[0]);
	while (list->map[++len_y])
		;
	//data.mlx = mlx_init();
	//data.win = mlx_new_window(data.mlx, len_x * S, len_y * S, "achraf");
	data.img = mlx_new_image(data.mlx, 15 * S, 15 * S);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	img_mini_map(list, &data, len_x, len_y);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	//mlx_key_hook(data.win, key_hook, list);
	mlx_loop(data.mlx);
}
