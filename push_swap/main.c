/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:31:32 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/19 18:11:32 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "movements.h"
#include "free.h"

static	int	ft_check_data(t_list *data)
{
	if (!ft_check(data))
		return (0);
	if (ft_order(data))
		return (2);
	return (1);
}

static void	ft_order_size(t_data **data)
{
	int	size;

	size = ft_lstsize((*data)->a);
	if (size == 2)
		ft_order_2(data);
	else if (size == 3)
		ft_order_3(data);
	else if (size == 4)
		ft_order_4(data);
	else if (size == 5)
		ft_order_5(data);
	else
	{
		ft_sort_b(data);
		ft_sort_back(data);
	}
}

int	main(int ac, char **av)
{
	t_data	*stacks;
	int		cdata;

	stacks = ft_calloc(sizeof(t_data), 1);
	stacks->a = NULL;
	if (ac < 2)
		return (ft_free_error(&stacks));
	if (!ft_parsing(av, &stacks->a))
		return (ft_free_error(&stacks));
	cdata = ft_check_data(stacks->a);
	if (cdata == 2)
	{
		ft_free(&stacks);
		ft_printf("This list is order!\n");
		return (0);
	}
	else if (cdata == 0)
		return (ft_free_error(&stacks));
	ft_set(stacks);
	ft_order_size(&stacks);
	//ft_show(stacks->a);
	ft_free(&stacks);
	return (0);
}
