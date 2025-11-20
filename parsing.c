/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:16:28 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/20 13:31:29 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	ft_setnums(char *s, int *i, long *num)
{
	long	temp;
	int		start;
	char	*str;

	while (s[*i] && (s[*i] == ' ' || (s[*i] >= 9 && s[*i] <= 13)))
		(*i)++;
	if (!s[*i])
		return (2);
	start = *i;
	if (s[*i] == '-' || s[*i] == '+' )
		(*i)++;
	while (s[*i] && ft_isdigit(s[*i]))
		(*i)++;
	if (!s[*i] || (s[*i] == ' ') || (s[*i] >= 9 && s[*i] <= 13))
	{
		str = ft_substr(s, start, *i - start);
		if (!str)
			return (0);
		temp = ft_atoi(str);
		if (temp < -2147483648 || temp > 2147483647 || ft_strlen(str) > 11)
			return (free(str), 0);
		free(str);
		return (*num = temp, 1);
	}
	return (0);
}

static int	ft_getnums(char *s, int *i, long *num)
{
	if (ft_strlen(s) > 1)
		return (ft_setnums(s, i, num));
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

static int	add_list(t_list **a, long num)
{
	t_list	*list;
	t_list	*new;

	new = ft_calloc(sizeof(t_list), 1);
	if (!new)
		return (0);
	new->num = num;
	new->id = -1;
	new->pos = 0;
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
		ft_lstadd_back(&list, new);
	return (1);
}

static int	ft_add(t_list **list, int num, int res, t_list **a)
{
	if (res == 0)
	{
		ft_freelist(list);
		return (0);
	}
	else if (res == 1)
	{
		if (!add_list(list, num))
		{
			ft_freelist(a);
			return (0);
		}
	}
	else if (res == 2)
		return (2);
	return (1);
}

int	ft_parsing(char **av, t_list **a)
{
	int		pos[2];
	long	num;
	int		res[2];
	t_list	*list;

	list = *a;
	pos[0] = 1;
	while (av[pos[0]])
	{
		pos[1] = 0;
		if (av[pos[0]][pos[1]] == '\0')
			return (ft_freelist(&list), 0);
		while (av[pos[0]][pos[1]])
		{
			res[0] = ft_getnums(av[pos[0]], &pos[1], &num);
			res[1] = ft_add(&list, num, res[0], a);
			if (!res[1])
				return (0);
			else if (res[1] == 2)
				break ;
		}
		pos[0]++;
	}
	return (*a = list, 1);
}
