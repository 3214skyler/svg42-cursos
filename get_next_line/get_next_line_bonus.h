/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodiogo <dodiogo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 15:35:27 by dodiogo           #+#    #+#             */
/*   Updated: 2026/09/15 15:52:53 by dodiogo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define OPEN_MAX 1024

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
