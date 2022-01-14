/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:23:38 by mbascuna          #+#    #+#             */
/*   Updated: 2021/12/08 16:25:41 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read_file(int fd, char *str)
{
	char	*buffer;
	int		count;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	count = 1;
	while (!ft_strchr(str, '\n') && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count <= 0)
		{
			free(buffer);
			return (str);
		}
		buffer[count] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

static char	*ft_read_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}	
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_read_new_file(char *str)
{
	int		i;
	int		j;
	char	*new;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	if (str[i] == '\n')
		i++;
	new = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	if (!new)
		return (NULL);
	j = 0;
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	free(str);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[FD_SETSIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read_file(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_read_line(str[fd]);
	str[fd] = ft_read_new_file(str[fd]);
	return (line);
}
