/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:39:16 by dodiogo           #+#    #+#             */
/*   Updated: 2026/09/01 16:44:01 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int	ft_printnumber(long nb);
int	ft_printstr(char *s);
int	ft_printf(const char *format, ...);
int	ft_printunsigned(unsigned long nb);
int	ft_printchar(char c);
int	ft_printpointer(void *ptr);
int	ft_printhexa(unsigned int n, char *base);

#endif
