/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:49:35 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/20 00:16:09 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_swap(t_list **list)
{
	t_list	*first;
	t_list	*second;

	if (!list || !*list || !(*list)->next)
		return ;
	first = *list;
	second = (*list)->next;
	first->before = second;
	first->next = second->next;
	second->next = first;
	second->before = first;
	*list = second;
	ft_printf("sa\n");
}

void	ft_pb(t_data **data)
{
	t_list	*node;

	if (!data || !(*data) || !(*data)->a)
		return ;
	node = (*data)->a;
	(*data)->a = (*data)->a->next;
	if ((*data)->a)
		(*data)->a->before = NULL;
	ft_lstadd_front(&(*data)->b, node);
	ft_printf("pb\n");
}

void	ft_pa(t_data **data)
{
	t_list	*node;

	if (!data || !(*data) || !(*data)->b)
		return ;
	node = (*data)->b;
	if (node)
		(*data)->b = (*data)->b->next;
	if ((*data)->b)
		(*data)->b->before = NULL;
	ft_lstadd_front(&(*data)->a, node);
	ft_printf("pa\n");
}

void	ft_show(t_list *list)
{
	t_list	*node;

	node = list;
	while (node)
	{
		ft_printf("%d\n", node->num);
		node = node->next;
	}
}
