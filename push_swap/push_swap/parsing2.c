/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:44:18 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/07 03:40:26 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char ft_getnums(char *s, int *i, int *num)
{
	int start;
	char *str;

	while (s[*i] && (s[*i] == ' ' || (s[*i] >= 9 && s[*i] <= 13)))
		(*i)++;
	start = *i;
	if (s[*i] == '-')
		(*i)++;
	while (s[*i] && ft_isdigit(s[*i]))
		(*i)++;
	if (!s[*i] || (s[*i] == ' ') || (s[*i] >= 9 && s[*i] <= 13))
	{
		str = ft_substr(s, start, *i);
		if (!str)
			return ('F');
		*num = ft_atoi(str);
		free(str);
		return ('V');
	}
	else
		return ('F');
}

static int	ft_check_list(t_list *a, int num)
{
	t_list	*list;

	list = a;
	ft_lstsize(a);
	while (list)
	{
		if (list->num == num)
			return (0);
		else
			list = list->next;
	}
	return (1);
}

static int	add_list(t_list **a, int num, int id)
{
	t_list	*list;
	t_list	*new = malloc(sizeof(t_list));

	if (!new)
		return (0);
	new->num = num;
	new->id = id;
	list = *a;
	if (!list)
	{
		*a = new;
		list = new;
		if (!list)
			return (0);
		ft_printf("\n%d\n", list->num);
	}
	else
	{
		ft_lstadd_back(&list, new);
	}
	return (1);
}

t_list *ft_parsing(char **s, int len)
{
	int i;
	int j;
	int num;
	int id;
	char **str;
	t_list *a = NULL;

	id = 0;
	str = s;
	i = 1;
	while (str[i])
	{
		j = 0;
		if (ft_strlen(str[i]) > 1)
		{
			while (str[i][j])
			{
				if (ft_getnums(str[i], &j, &num) == 'V')
				{
					id++;
					if (!add_list(&a, num, id))
					{
						ft_lstclear(&a);
						return (NULL);
					}
					ft_printf("%d", num);
				}
				else
					return (NULL);
			}
		}
		else
		{
			if (ft_isdigit(str[i][j]))
			{
				id++;
				num = (str[i][j] - 48);
				ft_printf("%d", num);
				if (!add_list(&a, num, id))
				{
					ft_lstclear(&a);
					return (NULL);
				}
			}
			else
				return (NULL);
		}
		i++;
	}
	return (a);
}

static int	ft_getnums(char *s, int *i, int *num)
{
	int		start;
	char	*str;

	// Saltar espacios o tabulaciones
	while (s[*i] && (s[*i] == ' ' || (s[*i] >= 9 && s[*i] <= 13)))
		(*i)++;

	// Si llegamos al final, no hay más números, pero no es error
	if (!s[*i])
		return (2); // ← devuelve 2 para indicar "fin sin error"

	start = *i;

	// Posible signo negativo
	if (s[*i] == '-')
		(*i)++;

	// Avanzar mientras haya dígitos
	while (s[*i] && ft_isdigit(s[*i]))
		(*i)++;

	// Si no se encontró ningún dígito, ignoramos (pero no alteramos el valor previo)
	if (start == *i || (s[start] == '-' && start + 1 == *i))
		return (2);

	// Crear el substring del número
	str = ft_substr(s, start, *i - start);
	if (!str)
		return (0); // ← solo 0 en caso de error real (malloc falló)

	*num = ft_atoi(str);
	free(str);

	return (1); // número leído correctamente
}



