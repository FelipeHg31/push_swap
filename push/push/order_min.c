/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:14:00 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/12 13:38:03 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

void ft_order_2(t_data **data)
{
    if((*data)->a->num > (*data)->a->next->num)
        ft_swap(&(*data)->a);    
}

void ft_order_3(t_data **data)
{
    t_list *min;
    
    min = (*data)->a;
    while (min->id != 0)
        min = min->next;
    if (min->pos == 1)
    {
        ft_ra(data);
        ft_order_2(data);
        ft_rra(data);
    }
    else if(min->pos == 2)
    {
        ft_rra(data);
        ft_order_2(data);
        ft_rra(data);
    }
    else if(min->pos == 3)
    {
        ft_order_2(data);
        ft_rra(data);
    }
}