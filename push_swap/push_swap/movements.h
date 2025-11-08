/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:01:41 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/08 14:21:32 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENTS_H
# define MOVEMENTS_H
# include "ft_printf/src/ft_printf.h"
# include "libft/libft.h"

int		ft_swap(t_list **list);
void	ft_pb(t_data **data);
void	ft_pa(t_data **data);
void	ft_correct(t_list **data);
void    ft_ra(t_data **data);

#endif
