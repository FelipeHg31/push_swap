/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:49:35 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/12 17:05:24 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_swap(t_list **list)
{
	t_list	*temp;

	if (!*list || !list)
		return ;
	temp = *list;
	temp->before = (*list)->next;
	temp->next = temp;
	(*list) = (*list)->next;
	(*list)->before = NULL;
	(*list)->next = temp;
	ft_printf("sa\n");
}

void	ft_pb(t_data **data)
{
	t_list	*node;

	if (data || !(*data) || !(*data)->a || !(*data)->a->next)
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

	if (data || !(*data) || !(*data)->a || !(*data)->a->next)
		return ;
	node = (*data)->b;
	(*data)->b = (*data)->b->next;
	if ((*data)->b)
		(*data)->b->before = NULL;
	ft_lstadd_front(&(*data)->a, node);
	ft_printf("pa\n");
}

void ft_show(t_list *list)
{
	t_list *node;

	node = list;
	while(node)
	{
		ft_printf("%d\n", node->num);
		node = node->next;
	}
}