/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:38:39 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/08 14:40:06 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

void	ft_lstaddr(t_list **lst, t_list *new)
{
	t_list *move;

	if (!*lst || !new)
		return ;
	move = *lst;
	while (move->next == NULL)
		move = move->next;
	move->next = new;
}