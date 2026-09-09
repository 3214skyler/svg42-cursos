/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:01:52 by dodiogo           #+#    #+#             */
/*   Updated: 2026/08/12 15:01:53 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(long nb)
{
	size_t	count;

	count = 0;
	if (nb == 0)
		count = 1;
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	count;
	char	*pt;
	size_t	i;
	long	nb;

	count = count_digits(n);
	pt = malloc(count + 1);
	if (!pt)
		return (NULL);
	nb = n;
	i = count - 1;
	if (nb == 0)
		pt[0] = '0';
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		pt[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	if (n < 0)
		pt[0] = '-';
	pt[count] = '\0';
	return (pt);
}
