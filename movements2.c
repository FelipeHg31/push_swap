/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:37:05 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/19 21:01:38 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

void	ft_ra(t_data **data)
{
	t_list	*node;

	if (!data || !(*data) || !(*data)->a || !(*data)->a->next)
		return ;
	node = (*data)->a;
	(*data)->a = (*data)->a->next;
	if ((*data)->a)
		(*data)->a->before = NULL;
	node->next = NULL;
	ft_lstadd_back(&(*data)->a, node);
	ft_printf("ra\n");
}

void	ft_rb(t_data **data)
{
	t_list	*node;

	if (!data || !(*data) || !(*data)->b || !(*data)->b->next)
		return ;
	node = (*data)->b;
	(*data)->b = (*data)->b->next;
	if ((*data)->b)
		(*data)->b->before = NULL;
	node->next = NULL;
	ft_lstadd_back(&(*data)->b, node);
	ft_printf("rb\n");
}

void	ft_rra(t_data **data)
{
	t_list	*node;
	t_list	*before_node;

	if (!data || !(*data) || !(*data)->a || !(*data)->a->next)
		return ;
	node = (*data)->a;
	while (node->next)
		node = node->next;
	before_node = node->before;
	before_node->next = NULL;
	node->before = NULL;
	node->next = (*data)->a;
	(*data)->a->before = node;
	(*data)->a = node;
	ft_printf("rra\n");
}

void	ft_rrb(t_data **data)
{
	t_list	*node;
	t_list	*before_node;

	if (!data || !(*data) || !(*data)->b)
		return ;
	node = (*data)->b;
	while (node->next)
		node = node->next;
	before_node = node->before;
	before_node->next = NULL;
	node->before = NULL;
	node->next = (*data)->b;
	(*data)->b->before = node;
	(*data)->b = node;
	ft_printf("rrb\n");
}
