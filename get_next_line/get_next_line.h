/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 18:05:29 by dodiogo           #+#    #+#             */
/*   Updated: 2026/09/14 14:35:35 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_has_newline(char *s);
char	*ft_extract_line(char *stash);
char	*ft_update_stash(char *stash);
char	*ft_read_to_stash(int fd, char *stash, char *buffer);
char	*ft_copy_stash(char *stash, int i);
char	*ft_add_to_stash(char *stash, char *buffer);

#endif
