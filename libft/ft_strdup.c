/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 12:34:37 by dodiogo           #+#    #+#             */
/*   Updated: 2026/08/07 13:46:51 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*pt;
	size_t	t;

	if (!s)
		return (NULL);
	t = ft_strlen(s);
	pt = malloc(t + 1);
	if (pt == NULL)
		return (NULL);
	ft_memcpy(pt, s, t + 1);
	return (pt);
}
