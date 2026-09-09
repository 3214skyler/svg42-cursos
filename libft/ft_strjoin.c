/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 11:04:14 by dodiogo           #+#    #+#             */
/*   Updated: 2026/08/11 11:04:15 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	t1;
	size_t	t2;
	char	*pt;

	if (!s1 || !s2)
		return (NULL);
	t1 = ft_strlen(s1);
	t2 = ft_strlen(s2);
	pt = malloc(t1 + t2 + 1);
	if (!pt)
		return (NULL);
	ft_memcpy(pt, s1, t1);
	ft_memcpy(&pt[t1], s2, t2);
	pt[t1 + t2] = '\0';
	return (pt);
}
