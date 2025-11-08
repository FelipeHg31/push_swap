/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:27:19 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/07 00:23:00 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	ft_repeat(t_list *list, t_list *num)
{
	while (list)
	{
		if (list->num == num->num && list->id != num->id)
			return (1);
		list = list->next;
	}
	return (0);
}

int	ft_order(t_list *list)
{
	t_list	*test;

	test = list;
	while (test->next)
	{
		if (test->num > test->next->num)
			return (0);
		test = test->next;
	}
	return (1);
}

int	ft_check(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp)
	{
		if (ft_repeat(list, temp))
			return (0);
		temp = temp->next;
	}
	return (1);
}
