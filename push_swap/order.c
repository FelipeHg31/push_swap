/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:36:16 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/19 18:12:38 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while ((i * i) < n)
		i++;
	return (i);
}

void	ft_sort_b(t_data **data)
{
	int range;
	int i;

	range = (ft_sqrt(ft_lstsize((*data)->a)) * (133 / 100));
	i = 0;
	while ((*data)->a)
	{
		if ((*data)->a->id <= i)
		{
			ft_pb(data);
			ft_rb(data);
			i++;
		}
		else if ((*data)->a->id <= i + range)
		{
			ft_pb(data);
			i++;
		}
		else
			ft_ra(data);
	}
}

static int ft_big(t_list *list)
{
	int big;
	int pos;
	int i;

	big = list->id;
	pos = 0;
	i = 0;

	while (list)
	{
		if (list->id > big)
		{
			big = list->id;
			pos = i;
		}
		list = list->next;
		i++;
	}
	return (pos);
}

void	ft_sort_back(t_data **data)
{
	int pos;
	int size;

	while ((*data)->b)
	{
		pos = ft_big((*data)->b);
		size = ft_lstsize((*data)->b);
		if (pos <= (size / 2))
		{
			while (pos-- > 0)
				ft_rb(data);
		}
		else
		{
			while (pos++ < size)
				ft_rrb(data);
		}
		ft_pa(data);
	}
}
