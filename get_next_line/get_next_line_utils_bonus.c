/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 15:35:17 by dodiogo           #+#    #+#             */
/*   Updated: 2026/09/15 15:37:21 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*resultado;

	if (!s1)
		s1 = "";
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	resultado = malloc(len);
	if (!resultado)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		resultado[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		resultado[i++] = s2[j++];
	}
	resultado[i] = '\0';
	return (resultado);
}

int	ft_has_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_extract_line(char *stash)
{
	int		i;
	int		j;
	char	*linha;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	linha = malloc(i + 1);
	if (!linha)
		return (NULL);
	j = 0;
	while (j < i)
	{
		linha[j] = stash[j];
		j++;
	}
	linha[j] = '\0';
	return (linha);
}

char	*ft_update_stash(char *stash)
{
	int		i;
	char	*nova;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	nova = ft_copy_stash(stash, i);
	free(stash);
	return (nova);
}
