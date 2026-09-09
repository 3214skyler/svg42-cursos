/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 14:02:12 by dodiogo           #+#    #+#             */
/*   Updated: 2026/08/06 14:13:28 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*a1;
	const unsigned char	*a2;

	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-a2[0]);
	if (!s2)
		return (a1[0]);
	i = 0;
	while (i < n && a1[i] == a2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return (a1[i] - a2[i]);
}
