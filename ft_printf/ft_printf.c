/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:39:37 by dodiogo           #+#    #+#             */
/*   Updated: 2026/09/02 14:57:16 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, char c)
{
	if (c == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_printnumber(va_arg(args, int)));
	else if (c == 'u')
		return (ft_printunsigned(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_printpointer(va_arg(args, void *)));
	else if (c == 'x')
		return (ft_printhexa(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_printhexa(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_format(args, format[i + 1]);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}
