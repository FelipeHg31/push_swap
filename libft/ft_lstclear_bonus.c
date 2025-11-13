/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 04:41:01 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/04 18:51:08 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*list;
	t_list	*tmp;

	if (!*lst)
		return ;
	list = *lst;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	*lst = NULL;
}
