/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_5_6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:01:03 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/20 00:13:52 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

static void	ft_min(t_data **data, t_list **m)
{
	*m = (*data)->a;
	while ((*m)->id != 0)
		*m = (*m)->next;
}

static void	ft_extract(t_data **data, t_list *m)
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
	}
	else
	{
		while (position <= len)
		{
			ft_rra(data);
			position++;
		}
		ft_pb(data);
	}
}

void	ft_order_5(t_data **data)
{
	t_list	*min1;
	t_list	*min2;

	ft_min(data, &min1);
	ft_extract(data, min1);
	ft_set(*data);
	ft_min(data, &min2);
	ft_extract(data, min2);
	ft_set(*data);
	ft_order_3(data);
	ft_pa(data);
	ft_pa(data);
}

void	ft_order_6(t_data **data)
{
	t_list	*min;

	ft_min(data, &min);
	ft_extract(data, min);
	ft_set(*data);
	ft_order_5(data);
	ft_pa(data);
}
