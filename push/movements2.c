/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:37:05 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/08 20:00:11 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

void	ft_ra(t_data **data)
{
	t_list	*node;

	if (!data || !(*data))
		return ;
	node = (*data)->a;
	(*data)->a = (*data)->a->next;
	if ((*data)->a)
		(*data)->a->before = NULL;
	node->next = NULL;
	ft_lstadd_back(&(*data)->a, node);
}

void	ft_rb(t_data **data)
{
	t_list	*node;

	if (!data || !(*data))
		return ;
	node = (*data)->b;
	(*data)->b = (*data)->b->next;
	if ((*data)->b)
		(*data)->b->before = NULL;
	node->next = NULL;
	ft_lstadd_back(&(*data)->b, node);
}

void	ft_rra(t_data **data)
{
	t_list *node;
	t_list *list;
	
	if (!data || !(*data))
		return ;
	list = *data;
	while()
	
}
