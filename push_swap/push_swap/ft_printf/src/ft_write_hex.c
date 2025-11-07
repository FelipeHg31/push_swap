/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 04:29:37 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/02 17:53:32 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbaseh(unsigned int n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putnbaseh(n / 16, base);
	count += ft_write_char(base[n % 16]);
	return (count);
}

int	ft_write_hex(unsigned int n)
{
	unsigned int	len;

	len = 0;
	len = len + ft_putnbaseh(n, "0123456789abcdef");
	return (len);
}

int	ft_write_hex_c(unsigned int n)
{
	unsigned int	len;

	len = 0;
	len = len + ft_putnbaseh(n, "0123456789ABCDEF");
	return (len);
}
