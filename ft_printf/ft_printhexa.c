/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:43:46 by dodiogo           #+#    #+#             */
/*   Updated: 2026/09/01 16:43:47 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(unsigned int n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_printhexa(n / 16, base);
	write(1, &base[n % 16], 1);
	return (count + 1);
}
