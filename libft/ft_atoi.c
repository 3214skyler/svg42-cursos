/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:09:35 by dodiogo           #+#    #+#             */
/*   Updated: 2026/08/19 15:04:14 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sinal(const char *s, int *i)
{
	int	sinal;

	sinal = 1;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			sinal = -1;
		(*i)++;
	}
	return (sinal);
}

static int	converte_numero(const char *s, int i, int sinal)
{
	long	resultado;
	int		digito;

	resultado = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		digito = s[i] - '0';
		if (resultado > (INT_MAX - digito) / 10)
		{
			if (sinal == 1)
				return (INT_MAX);
			return (INT_MIN);
		}
		resultado = resultado * 10 + digito;
		i++;
	}
	return ((int)(resultado * sinal));
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sinal;

	if (!nptr)
		return (0);
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	sinal = ft_sinal(nptr, &i);
	return (converte_numero(nptr, i, sinal));
}
