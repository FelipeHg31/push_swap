/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:23:59 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/20 00:31:29 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	ft_free(t_data **stacks)
{
	ft_freelist(&(*stacks)->a);
	if ((*stacks)->b)
		ft_freelist(&(*stacks)->b);
	free(*stacks);
}

int	ft_free_error(t_data **stacks)
{
	ft_free(stacks);
	write(2, "Error.", 6);
	return (1);
}
