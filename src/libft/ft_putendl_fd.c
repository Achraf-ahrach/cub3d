/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <ajari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:47:14 by ajari             #+#    #+#             */
/*   Updated: 2023/05/22 17:00:18 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	if (fd == 2)
		write(2, RED_T, ft_strlen(RED_T));
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
	return (0);
}
