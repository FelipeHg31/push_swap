/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:35:57 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/03 00:41:13 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/src/ft_printf.h"
# include "libft/libft.h"

typedef struct s_list_num
{
    int num;
    int id;
    struct s_list_num *next;
} t_list_num;

void ft_parsing(char **s, int len);


#endif 