/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 02:03:23 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/03 01:26:11 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int n, int id)
{
	t_list	*list;

	list = (t_list *) malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->num = n;
	list->next = NULL;
	return (list);
}
/* 
int main()
{
	t_list *list = ft_lstnew(ft_strdup("guayaba"));
	printf("%s", (char *)list->content);
	
} */
