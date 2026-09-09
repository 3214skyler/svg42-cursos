/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:05:31 by dodiogo           #+#    #+#             */
/*   Updated: 2026/09/02 12:26:58 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printhex(unsigned long n)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_printhex(n / 16);
	write(1, &base[n % 16], 1);
	return (count + 1);
}

int	ft_printpointer(void *ptr)
{
	unsigned long	address;
	int				count;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	address = (unsigned long)ptr;
	write(1, "0x", 2);
	count = ft_printhex(address);
	return (2 + count);
}
