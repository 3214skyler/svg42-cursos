/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 10:40:33 by dodiogo           #+#    #+#             */
/*   Updated: 2026/08/11 10:40:34 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	t;
	size_t	i;
	char	*pt;

	if (!s)
		return (NULL);
	t = ft_strlen(s);
	if (start >= t)
		len = 0;
	else if (len > t - start)
		len = t - start;
	pt = malloc(len + 1);
	if (!pt)
		return (NULL);
	i = 0;
	while (i < len)
	{
		pt[i] = s[start + i];
		i++;
	}
	pt[i] = '\0';
	return (pt);
}
