/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:28:27 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/03 16:11:02 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int ft_getnums(char *s, int *i)
{
    int start;
    char *str;
    int num;
    
    while (s[*i] && (s[*i] == ' ' || (s[*i] >= 9 && s[*i] <= 13)))
        (*i)++;
    start = *i;
    while (s[*i] && ft_isdigit(s[*i]))
        (*i)++;
    if (!s[*i] || (s[*i] == ' ') || (s[*i] >= 9 && s[*i] <= 13))
    {
        str = ft_substr(s, start, *i);
        if (!str)
            return(NULL);
        num = ft_atoi(str);
        free(str);
        return (num);
    }
    else
        return (0);    
}

static int ft_check_list(t_list *a, int num)
{
    t_list *list;
    
    list = a;
    while (a)
    {
        if(list->num == num)
            return (0);
        else
            list = list->next;  
    }
    return (1);
}

static int add_list(t_list **a, int num, int id)
{
    int i;
    t_list *list;
    t_list *new;

    i = 0;
    list = *a;
    if (id == 1)
        list = ft_lstnew(num, id);
    else
    {
        if (ft_check_list(list, num))
        {
            new = ft_lstnew(num, id);
            if (!new)
                return (0);
            ft_lstadd_back(&list, new);  
        }
        
         
    }
    
}

void ft_parsing(char **s, int len)
{
    int i;
    int j;
    int num;
    int id;
    char **str;
    t_list *a;
    
    id = 0;
    str = s;
    i = 1;
	while (i < len)
	{
        j = 0;
        if (ft_strlen(str[i]) > 1)
        {
            j = 0;
            if (str[i][j])
            {
                num = ft_getnums(str[i], &j);
                if (num)
                {
                    id++;
                    a = add_list(&a, num, id); 
                    //ft_printf("%d", num);
                    
                }
            }            
        }
        else
        {
            if (ft_isdigit(str[i][0]))
            {
                id++;
                num = str[i][0] - 48;
                //ft_printf("%d", num);
                a = add_list(&a, num, id); 
            }
        }
        i++;  
	}
}