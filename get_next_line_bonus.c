/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozan <ozan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:12:02 by ozan              #+#    #+#             */
/*   Updated: 2025/01/19 15:04:21 by ozan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*rm_first_line(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	tmp = malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!tmp)
	{
		free(str);
		return (NULL);
	}
	i++;
	j = 0;
	while (str[i])
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	free(str);
	return (tmp);
}

static char	*assing_first_line(char *str)
{
	char	*s;
	int		i;

	if (!str[0])
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		s = malloc(sizeof(char) * (i + 2));
	else
		s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return (s);
}

static char	*find_first_line(int fd, char *str, int rd)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!find_n(str))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == 0)
			break ;
		if (rd < 0)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		str = reassign_memory(str, rd);
		if (!str)
			break ;
		str = save_read(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = find_first_line(fd, str[fd], 1);
	if (!str[fd])
		return (NULL);
	s = assing_first_line(str[fd]);
	str[fd] = rm_first_line(str[fd]);
	return (s);
}
