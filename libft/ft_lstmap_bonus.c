/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:32:35 by ajari             #+#    #+#             */
/*   Updated: 2022/10/31 02:01:26 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*t;
	t_list	*temp;

	t = malloc(sizeof(t_list));
	if (!t || !lst || !f || !del)
		return (0);
	t->content = f(lst->content);
	t->next = 0;
	temp = t;
	lst = lst->next;
	while (lst)
	{
		t->next = malloc(sizeof(t_list));
		if (!(t->next))
		{
			ft_lstclear(&temp, del);
			return (0);
		}
		t->next->content = f(lst->content);
		t->next->next = 0;
		t = t->next;
		lst = lst->next;
	}
	return (temp);
}
