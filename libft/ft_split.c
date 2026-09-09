/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:53:32 by dodiogo           #+#    #+#             */
/*   Updated: 2026/08/19 16:50:43 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	free_split(char **pt, size_t count)
{
	while (count > 0)
		free(pt[--count]);
	free(pt);
}

static int	fill_split(char **pt, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		pt[count] = ft_substr(s, j, i - j);
		if (!pt[count])
		{
			free_split(pt, count);
			return (0);
		}
		count++;
	}
	pt[count] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**pt;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	pt = malloc((count + 1) * sizeof(char *));
	if (!pt)
		return (NULL);
	if (!fill_split(pt, s, c))
		return (NULL);
	return (pt);
}
