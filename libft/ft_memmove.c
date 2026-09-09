/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:23:37 by dodiogo           #+#    #+#             */
/*   Updated: 2026/07/31 10:11:07 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*a;
	const unsigned char	*b;

	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (dest);
	a = (unsigned char *)dest;
	b = (const unsigned char *)src;
	if (a > b)
	{
		while (n > 0)
		{
			n--;
			a[n] = b[n];
		}
		return (dest);
	}
	ft_memcpy(a, b, n);
	return (dest);
}
