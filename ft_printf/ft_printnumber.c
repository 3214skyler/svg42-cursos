/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:39:26 by dodiogo           #+#    #+#             */
/*   Updated: 2026/09/01 14:49:24 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnumber(long nb)
{
	int		count;
	char	c;

	count = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		count++;
	}
	if (nb >= 10)
		count += ft_printnumber(nb / 10);
	c = '0' + (nb % 10);
	write(1, &c, 1);
	return (count + 1);
}
