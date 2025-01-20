/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozan <ozan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:19:26 by ozan              #+#    #+#             */
/*   Updated: 2025/01/19 15:01:54 by ozan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len > 0)
		*(char *)(b + len-- - 1) = c;
	return (b);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*find_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*reassign_memory(char *str, int rd)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!str)
	{
		tmp = malloc(sizeof(char) * (rd + 1));
		if (!tmp)
			return (NULL);
		ft_memset(tmp, 0, rd + 1);
		return (tmp);
	}
	tmp = malloc(sizeof(char) * (ft_strlen(str) + rd + 1));
	if (!tmp)
		return (NULL);
	ft_memset(tmp, 0, ft_strlen(str) + rd + 1);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	free(str);
	return (tmp);
}

char	*save_read(char *str, char *buffer)
{
	int	i;
	int	j;	

	i = 0;
	j = ft_strlen(str);
	while (buffer[i])
	{
		str[j + i] = buffer[i];
		i++;
	}
	str[j + i] = '\0';
	return (str);
}
