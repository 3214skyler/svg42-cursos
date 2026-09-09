/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 12:08:40 by dodiogo           #+#    #+#             */
/*   Updated: 2026/08/04 12:47:37 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (dst == NULL)
		return (0);
	if (src == NULL)
		return (ft_strlen(dst));
	j = 0;
	while (j < size && dst[j] != '\0')
		j++;
	len = ft_strlen(src);
	if (j >= size)
		return (size + len);
	i = 0;
	while (src[i] != '\0' && (j + i + 1) < size)
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (j + len);
}
