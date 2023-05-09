/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:41:06 by aahrach           #+#    #+#             */
/*   Updated: 2023/05/08 22:42:39 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    ft_cut_color(t_lst *list, char **str_spl, char x)
{
    int     nb;
    char    *str;
    int     i;
    int     j;
    int     len;

    i = -1;
    while (++i < 3)
    {
        j = 0;
        len = 0;
        str = ft_strtrim(str_spl[i], " ");
        free(str_spl[i]);
        while (str[j] == '0')
            j++;
        len = j;
        while (str[len])
        {
            if (str[len] < '0' || str[len] > '9')
                ft_eroor("THE COLOR IS NOT NUMBER !\n");
            len++;
        }
        len -= j;
        nb = ft_atoi(str + j);
        if (!str[0] || len > 3 || nb > 255 || nb < 0)
            ft_eroor("THE COLOR NUMBER GREATER THAN THE LIMIT !\n");
        if (x == 'f')
            list->f[i] = nb;
        else
            list->c[i] = nb;
        free(str);
    }
    free(str_spl);
}

void    foort_ceiling(t_lst *list, char **tmp, char x)
{
    int     i;
    char    *str;
    char    **str_spl;
    int     intervale;

    i = 0;
    intervale = 0;
    (*tmp)++;
    if (**tmp != ' ')
        ft_eroor("THE MAP IS NOT VALID !\n");
    (*tmp)++;
    str = malloc((100) * sizeof(char));
    if (x == 'f')
        list->f = malloc((3) * sizeof(int));
    else
        list->c = malloc((3) * sizeof(int));
    i = 0;
    while (**tmp != '\n')
    {
        str[i++] = **tmp;
        if (**tmp == ',')
            intervale++;
        (*tmp)++;
    }
    str[i] = '\0';
    if (intervale != 2)
        ft_eroor("THE FLOOR COLOR IS NOT VALID (intervale{,})\n");
    str_spl = ft_split(str, ',');
    i = 0;
    while (str_spl[i])
        i++;
    if (i != 3)
        ft_eroor("COLOR IS NOT VALID\n");
    ft_cut_color(list, str_spl, x);
}
