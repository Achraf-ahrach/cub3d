/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:33:44 by aahrach           #+#    #+#             */
/*   Updated: 2023/05/08 22:39:34 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    north(t_lst *list, char **tmp)
{
    int i;

    i = 0;
    (*tmp)++;
    (*tmp)++;
    if (**tmp != ' ')
        ft_eroor("THE MAP IS NOT VALID !\n");
    if (list->no)
        ft_eroor("THE TEXTURE DUPLICATE !\n");
    (*tmp)++;
    while (tmp[0][i] != '\n')
        i++;
    list->no = malloc((i + 1) * sizeof(char));
    i = 0;
    while (**tmp != '\n')
    {
        list->no[i++] = **tmp;
        (*tmp)++;
    }
    list->no[i] = '\0';
}

void    south(t_lst *list, char **tmp)
{
    int i;

    i = 0;
    (*tmp) += 2;
    if (**tmp != ' ')
        ft_eroor("THE MAP IS NOT VALID !\n");
    if (list->so)
        ft_eroor("THE TEXTURE DUPLICATE !\n");
    (*tmp)++;
    while (tmp[0][i] != '\n')
        i++;
    list->so = malloc((i + 1) * sizeof(char));
    i = 0;
    while (**tmp != '\n')
    {
        list->so[i++] = **tmp;
        (*tmp)++;
    }
    list->so[i] = '\0';
}

void    west(t_lst *list, char **tmp)
{
    int i;

    i = 0;
    (*tmp) += 2;
    if (**tmp != ' ')
        ft_eroor("THE MAP IS NOT VALID !\n");
    if (list->we)
        ft_eroor("THE TEXTURE DUPLICATE !\n");
    (*tmp)++;
    while (tmp[0][i] != '\n')
        i++;
    list->we = malloc((i + 1) * sizeof(char));
    i = 0;
    while (**tmp != '\n')
    {
        list->we[i++] = **tmp;
        (*tmp)++;
    }
    list->we[i] = '\0';
}

void    east(t_lst *list, char **tmp)
{
    int i;

    i = 0;
    (*tmp) += 2;
    if (**tmp != ' ')
        ft_eroor("THE MAP IS NOT VALID !\n");
    if (list->ea)
        ft_eroor("THE TEXTURE DUPLICATE !\n");
    (*tmp)++;
    while (tmp[0][i] != '\n')
        i++;
    list->ea = malloc((i + 1) * sizeof(char));
    i = 0;
    while (**tmp != '\n')
    {
        list->ea[i++] = **tmp;
        (*tmp)++;
    }
    list->ea[i] = '\0';
}
