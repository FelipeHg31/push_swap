/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:35:57 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/07 00:16:45 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/src/ft_printf.h"
# include "libft/libft.h"

typedef struct s_ps_data
{
	t_list	*a;
	t_list	*b;
}	t_data;

int	ft_parsing(char **s, t_list **a);
int	ft_order(t_list *list);
int	ft_check(t_list *list);

#endif 
