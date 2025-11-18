/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:01:41 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/18 00:50:28 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENTS_H
# define MOVEMENTS_H
# include <limits.h>
# include "ft_printf/src/ft_printf.h"
# include "libft/libft.h"

int		ft_swap(t_list **list);
void	ft_pb(t_data **data);
void	ft_pa(t_data **data);
void	ft_ra(t_data **data);
void	ft_rb(t_data **data);
void	ft_rra(t_data **data);
void	ft_rrb(t_data **data);
void	ft_positions(t_list **data);
void	ft_set(t_data *data);
void	ft_order_2(t_data **data);
void	ft_order_3(t_data **data);
void	ft_order_4(t_data **data);
void	ft_order_5(t_data **data);
void    ft_order_num(t_data **data);
t_list	*ft_search_id (t_list *lst, int id);
void    ft_set_chunks(t_data **data);
void	ft_show(t_list *list);
#endif
