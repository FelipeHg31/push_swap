/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:14:00 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/19 21:02:26 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

void	ft_order_2(t_data **data)
{
	if ((*data)->a->num > (*data)->a->next->num)
		ft_swap(&(*data)->a);
}

void	ft_order_3(t_data **data)
{
	t_list	*max;

	max = (*data)->a;
	while (max->id != 2)
		max = max->next;
	if (max->pos == 1)
	{
		ft_ra(data);
		ft_order_2(data);
	}
	else if (max->pos == 2)
	{
		ft_rra(data);
		ft_order_2(data);
	}
	else if (max->pos == 3)
		ft_order_2(data);
}

static int	ft_order4_3(t_data **data, int pos_min, int pos_max)
{
	if (pos_min == 2)
	{
		ft_ra(data);
		ft_pb(data);
		ft_set(*data);
		ft_order_3(data);
		ft_pa(data);
		return (1);
	}
	else if (pos_max == 2)
	{
		ft_ra(data);
		ft_pb(data);
		ft_set(*data);
		ft_order_3(data);
		ft_pa(data);
		ft_ra(data);
		return (1);
	}
	return (0);
}

static int	ft_order4_2(t_data **data, int pos_min, int pos_max)
{
	if (pos_max == 1)
	{
		ft_pb(data);
		ft_set(*data);
		ft_order_3(data);
		ft_pa(data);
		ft_ra(data);
		return (1);
	}
	else if (pos_max == 4)
	{
		ft_rra(data);
		ft_pb(data);
		ft_set(*data);
		ft_order_3(data);
		ft_pa(data);
		ft_ra(data);
		return (1);
	}
	else if (ft_order4_3(data, pos_min, pos_max))
		return (1);
	return (0);
}

void	ft_order_4(t_data **data)
{
	t_list	*min_max[2];

	min_max[1] = (*data)->a;
	min_max[0] = (*data)->a;
	while (min_max[1]->id != 3)
		min_max[1] = min_max[1]->next;
	while (min_max[0]->id != 0)
		min_max[0] = min_max[0]->next;
	if (min_max[0]->pos == 1)
	{
		ft_pb(data);
		ft_set(*data);
		ft_order_3(data);
		ft_pa(data);
	}
	else if (min_max[0]->pos == 4)
	{
		ft_rra(data);
		ft_pb(data);
		ft_set(*data);
		ft_order_3(data);
		ft_pa(data);
	}
	else
		ft_order4_2(data, min_max[0]->pos, min_max[1]->pos);
}
