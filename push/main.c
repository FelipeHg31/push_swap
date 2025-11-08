/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:31:32 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/08 19:31:30 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "movements.h"

static	int	ft_check_data(t_list *data)
{
	if (!ft_check(data))
		return (0);
	if (ft_order(data))
		return (2);
	return (1);
}

void	ft_free(t_data *stacks)
{
	ft_freelist(&stacks->a);
	free(stacks);
}

static int	ft_free_error(t_data *stacks)
{
	ft_free(stacks);
	ft_printf("Error.\n");
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*stacks;
	int		cdata;

	stacks = ft_calloc(sizeof(t_data), 1);
	stacks->a = NULL;
	if (ac < 1)
		return (ft_free_error(stacks));
	if (!ft_parsing(av, &stacks->a))
		return (ft_free_error(stacks));
	cdata = ft_check_data(stacks->a);
	if (cdata == 2)
	{
		ft_free(stacks);
		ft_printf("This list is order!\n");
		return (0);
	}
	else if (cdata == 0)
		return (ft_free_error(stacks));
	ft_swap(&stacks->a);
	ft_pb(&stacks);
	ft_pa(&stacks);
	ft_ra(&stacks);
	ft_free(stacks);
	return (0);
}
