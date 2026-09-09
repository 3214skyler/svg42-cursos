/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 15:07:07 by dodiogo           #+#    #+#             */
/*   Updated: 2026/07/30 15:59:38 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*b;

	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (dest);
	p = (unsigned char *)dest;
	b = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		p[i] = b[i];
		i++;
	}
	return (dest);
}
