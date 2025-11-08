/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:37:05 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/08 14:44:36 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

void ft_ra(t_data **data)
{ 
    t_list *node;

    if(!data || !(*data))
        return ;
    node = (*data)->a;
    (*data)->a = (*data)->a->next;
    if ((*data)->a)
        (*data)->a->before = NULL;
    node->next = NULL;
    ft_lstaddr(&(*data)->a, node);
}