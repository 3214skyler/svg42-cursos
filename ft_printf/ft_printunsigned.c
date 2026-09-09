/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:39:30 by dodiogo           #+#    #+#             */
/*   Updated: 2026/09/01 15:42:56 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(unsigned long nb)
{
	int		count;
	char	c;

	count = 0;
	if (nb >= 10)
		count += ft_printunsigned(nb / 10);
	c = '0' + (nb % 10);
	write(1, &c, 1);
	return (count + 1);
}
