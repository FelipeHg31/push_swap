/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:16:28 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/07 03:59:26 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int ft_getnums(char *s, int *i, int *num)
{
	int		start;
	char	*str;

	if (ft_strlen(s) > 1)
	{
		while (s[*i] && (s[*i] == ' ' || (s[*i] >= 9 && s[*i] <= 13)))
			(*i)++;
		if (!s[*i])
			return (2);
		start = *i;
		if (s[*i] == '-')
			(*i)++;
		while (s[*i] && ft_isdigit(s[*i]))
			(*i)++;
		if (!s[*i] || (s[*i] == ' ') || (s[*i] >= 9 && s[*i] <= 13))
		{
			str = ft_substr(s, start, *i - start);
			if (!str)
				return (0);
			*num = ft_atoi(str);
			free(str);
			return (1);
		}
		else
			return (0);
	}
	else
	{
		if (ft_isdigit(s[*i]))
		{
			*num = ft_atoi(s);
			(*i)++;
			return (1);
		}
		else
			return (0);
	}
}




static int	add_list(t_list **a, int num, int id)
{
	t_list	*list;
	t_list	*new = ft_calloc(sizeof(t_list), 1);

	if (!new)
		return (0);
	new->num = num;
	new->id = id;
	list = *a;
	if (!list)
	{
		*a = new;
		if (!*a)
		{
			free(new);
			return (0);
		}
	}
	else
	{
		ft_lstadd_back(&list, new);
	}
	return (1);
}

int	ft_parsing(char **av, t_list **a)
{
	int		pos[2];
	int		num;
	int		id;
	int		res;
	t_list	*list;

	list = *a;
	id = 1;
	pos[0] = 1;
	while (av[pos[0]])
	{
		pos[1] = 0;
		while (av[pos[0]][pos[1]])
		{
			res = ft_getnums(av[pos[0]], &pos[1], &num);
			if (res == 0)
				return (0);
			else if (res == 1)
			{
				ft_printf("%d\n", num);
				if (!add_list(&list, num, id))
					return (0);
				id++;
			}
			else if (res == 2)
				break ;
		}
		pos[0]++;
	}
	*a = list;
	return (1);
}
