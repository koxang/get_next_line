/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozan <ozan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:19:26 by ozan              #+#    #+#             */
/*   Updated: 2025/01/19 15:08:40 by ozan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	*ft_memset(void *b, int c, size_t len);
int		ft_strlen(const char *str);
char	*find_n(char *str);
char	*reassign_memory(char *str, int rd);
char	*save_read(char *str, char *buffer);

#endif
