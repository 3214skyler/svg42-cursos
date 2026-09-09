/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:39:29 by dodiogo           #+#    #+#             */
/*   Updated: 2026/08/19 16:45:50 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	if (!s)
		return (NULL);
	i = 0;
	j = -1;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			j = i;
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	if (j >= 0)
		return ((char *)&s[j]);
	return (NULL);
}
