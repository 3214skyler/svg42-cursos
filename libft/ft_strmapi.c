/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:39:28 by dodiogo           #+#    #+#             */
/*   Updated: 2026/08/12 15:39:29 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*pt;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	pt = malloc(ft_strlen(s) + 1);
	if (!pt)
		return (NULL);
	while (s[i])
	{
		pt[i] = f(i, s[i]);
		i++;
	}
	pt[i] = '\0';
	return (pt);
}
