/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:39:33 by dodiogo           #+#    #+#             */
/*   Updated: 2026/09/01 14:49:31 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		count = 6;
	}
	else
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
			count++;
		}
	}
	return (count);
}
