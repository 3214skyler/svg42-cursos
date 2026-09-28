/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 11:20:37 by dodiogo           #+#    #+#             */
/*   Updated: 2026/09/14 14:31:32 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_copy_stash(char *stash, int i)
{
	int		j;
	char	*new_stash;

	new_stash = malloc(ft_strlen(stash + i) + 1);
	if (!new_stash)
		return (NULL);
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	return (new_stash);
}

char	*ft_add_to_stash(char *stash, char *buffer)
{
	char	*new_stash;

	new_stash = ft_strjoin(stash, buffer);
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	free(stash);
	return (new_stash);
}

char	*ft_read_to_stash(int fd, char *stash, char *buffer)
{
	int	bytes_read;

	while (!stash || !ft_has_newline(stash))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(stash);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		stash = ft_add_to_stash(stash, buffer);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stash = ft_read_to_stash(fd, stash, buffer);
	free(buffer);
	if (!stash)
		return (NULL);
	line = ft_extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = ft_update_stash(stash);
	return (line);
}
