/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:31:32 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/07 00:33:26 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"


int	main(int argc, char **argv)
{
	t_data	*stacks;

	stacks = malloc(sizeof(t_data));
	stacks->a = NULL;
	if (argc < 1)
		return 1;
	if (!ft_parsing(argv, &stacks->a))
		return 1;

	if (!ft_check(stacks->a))
	{
		ft_printf("hay repeticiones\n");
		return 1;
	}
	if (ft_order(stacks->a))
	{
		ft_printf("esta ordenada, no tenemos que hacer na\n");
		return 0;
	}
	for (t_list *tmp = stacks->a; tmp; tmp = tmp->next)
		printf("nodo id %d, nodo num %d\n", tmp->id, tmp->num);
	
	ft_freelist(&stacks->a);
	free(stacks);
	return (0);
}
