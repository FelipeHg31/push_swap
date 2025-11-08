/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:49:35 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/08 00:29:48 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_swap(t_list **list)
{
	t_list	*l;
	int		temp;

	if (!*list || !list)
		return ;
	l = *list;
	temp = l->num;
	l->num = l->next->num;
	l->next->num = temp;
}

void	ft_pb(t_data **data)
{
	t_list	*node;

	if (!data || !(*data)->a)
		return ;
	node = (*data)->a;
	(*data)->a = (*data)->a->next;
	if ((*data)->a)
		(*data)->a->before = NULL;
	ft_lstadd_front(&(*data)->b, node);
}

void	ft_pa(t_data **data)
{
	t_list	*node;

	if (!data || !(*data)->b)
		return ;
	node = (*data)->b;
	(*data)->b = (*data)->b->next;
	if ((*data)->b)
		(*data)->b->before = NULL;
	ft_lstadd_front(&(*data)->a, node);
}

void	ft_correct(t_list **data)
{
	t_list *list;
	int i;

	i = 0; 
	list =  *data;
	while(list)
	{
		i++;
		list->id = i;
		list = list->next;
	}
}