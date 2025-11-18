/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_chunks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:40:06 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/17 20:28:13 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

static int ft_lot(int len)
{
    if (len <= 10)
        return (2);
    else if (len <= 50)
        return (3);
    else if (len <= 100)
        return (5);
    else if (len <= 200)
        return (7);
    else if (len <= 300)
        return (9);
    else if (len <= 400)
        return (10);
    else
        return (11);
        
}

static int ft_set_media(int size, int start)
{
    int sum;
    
    sum = size + start;
    if(sum % 2 == 0)
        return (sum / 2);
    else
        return ((sum + 1) / 2);
}

static void ft_setc(t_data **data, int len)
{
    int chunk;
    int media;
    int size;
    int start;   
    t_list *node;
    
    node = (*data)->a;
    chunk = 0;
    size = 0;
    start = 0;
    while (chunk < (*data)->chunks)
    {
        if (len < (size * 2))
            size = len - size;
        else 
            size = size + (*data)->lot;
        media = ft_set_media(size, start);
        while (start < size)
        {
            node = ft_search_id((*data)->a, start);
            node->median = media;
            node->chunk = chunk;
            node = node->next;
            start++;
        }
        chunk++;
    }
}

void    ft_set_chunks(t_data **data)
{
    int len;

    len = ft_lstsize((*data)->a);
    (*data)->chunks  = ft_lot(len);
    if (len % (*data)->chunks != 0)
        (*data)->lot = (len / (*data)->chunks) + 1;
    else
        (*data)->lot = (len / (*data)->chunks);
    ft_setc(data, len);   
}