/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:41:44 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/20 13:49:52 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

static void	ft_set_id(t_list *node, int num, int id)
{
	while (node && node->num != num)
		node = node->next;
	if (node)
		node->id = id;
}

void	ft_positions(t_list **data)
{
	t_list	*list;
	int		i;

	i = 0;
	list = *data;
	while (list)
	{
		i++;
		list->pos = i;
		list = list->next;
	}
}

static void	ft_set_init(t_list *data)
{
	t_list	*list;

	list = data;
	while (list)
	{
		list->id = -1;
		list = list->next;
	}
}

void	ft_set(t_data *data)
{
	t_list	*node;
	int		min;
	int		pos;
	int		size;

	size = ft_lstsize(data->a);
	pos = 0;
	ft_positions(&(data)->a);
	ft_set_init(data->a);
	while (pos < size)
	{
		node = data->a;
		min = INT_MAX;
		while (node)
		{
			if (node->id == -1 && node->num < min)
				min = node->num;
			node = node->next;
		}
		ft_set_id(data->a, min, pos);
		pos++;
	}
}

t_list	*ft_search_id(t_list *lst, int id)
{
	t_list	*node;

	node = lst;
	while (node->id != id)
		node = node->next;
	return (node);
}
