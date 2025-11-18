/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:36:16 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/18 15:20:33 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

static void	ft_ext(t_data **data, t_list *m)
{
	int	position;
	int	len;

	len = ft_lstsize((*data)->a);
	position = m->pos;
	if (position <= (len / 2))
	{
		while (position > 1)
		{
			ft_ra(data);
			position--;
		}
		ft_pb(data);
		if (m->id >= m->median)
			ft_rb(data);
	}
	else
	{
		while (position <= len)
		{
			ft_rra(data);
			position++;
		}
		ft_pb(data);
		if (m->id >= m->median)
			ft_rb(data);
	}
	ft_positions(&(*data)->a);
}

static void	ft_ext_b(t_data **data, t_list *m)
{
	int	position;
	int	len;

	len = ft_lstsize((*data)->b);
	position = m->pos;
	if (position <= (len / 2))
	{
		while (position > 1)
		{
			ft_rb(data);
			position--;
		}
		ft_pa(data);
	}
	else
	{
		while ((position <= len) && (position != 1))
		{
			ft_rrb(data);
			position++;
		}
		ft_pa(data);
	}
	ft_positions(&(*data)->b);
}

void	ft_order_num(t_data **data)
{
	int		ch;
	int		size;
	int		id;
	int		len;
	t_list	*node;

	ch = 0;
	size = 0;
	id = 0;
	len = ft_lstsize((*data)->a);
	while (ch < (*data)->chunks)
	{
		if (len < (size * 2))
			size = len;
		else
			size = size + (*data)->lot;
		while (id < size)
		{
			node = ft_search_id((*data)->a, id);
			ft_ext(data, node);
			id++;
		}
		ch++;
	}
	ft_show((*data)->b);
	ft_positions(&(*data)->b);
	while (--id >= 0)
	{
		node = ft_search_id((*data)->b, id);
		ft_ext_b(data, node);
	}
}
