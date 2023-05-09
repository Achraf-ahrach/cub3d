/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:28:34 by aahrach           #+#    #+#             */
/*   Updated: 2023/05/09 11:46:42 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    ft_eroor(char *str)
{
    int i;

    i = 0;
    while (str[i])
        write(2, &str[i++], 1);
    exit (1);
}

int main(int ac, char **env)
{
    t_lst  *list;
    char    *map;

    list = malloc(sizeof(t_lst));
    if (ac != 2 || check_name_file(env[1]))
        ft_eroor("Error: NAME FILE\n");
    map = read_line(env[1], 0);
    fill_in_struct(list, map);
    // if (list->map)
    //     (abde);
}
