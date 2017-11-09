/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:23:05 by lyoung            #+#    #+#             */
/*   Updated: 2017/04/13 15:01:01 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	build_str(char **str, char *buff)
{
	char	*tmp;

	if (!*str)
	{
		*str = ft_strdup(buff);
		ft_bzero(buff, BUFF_SIZE + 1);
		return ;
	}
	tmp = ft_strjoin(*str, buff);
	free(*str);
	*str = tmp;
	ft_bzero(buff, BUFF_SIZE + 1);
}

int		add_line(char **str, char *end_line, char **line)
{
	char	*tmp;

	*line = ft_strndup(*str, (end_line - *str));
	tmp = ft_strdup(end_line + 1);
	free(*str);
	*str = tmp;
	return (1);
}

int		end_of_file(char **str, int fd, char **line)
{
	char	*end_line;

	if ((end_line = ft_strchr(str[fd], '\n')))
	{
		*line = ft_strndup(str[fd], (end_line - str[fd]));
		str[fd] = ft_strdup(end_line + 1);
		return (1);
	}
	else
	{
		*line = ft_strdup(str[fd]);
		ft_bzero(str[fd], ft_strlen(str[fd]));
		return (1);
	}
}

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	char			*end_line;
	int				nb_bytes;
	static char		*str[4864];

	if (fd < 0 || !line || BUFF_SIZE == 0)
		return (-1);
	ft_bzero(buff, BUFF_SIZE + 1);
	while ((nb_bytes = read(fd, &buff, BUFF_SIZE)) != 0)
	{
		if (nb_bytes < 0)
			return (-1);
		build_str(&str[fd], buff);
		if ((end_line = ft_strchr(str[fd], '\n')))
			return (add_line(&str[fd], end_line, line));
	}
	if (ft_strlen(str[fd]))
		return (end_of_file(str, fd, line));
	ft_strdel(&str[fd]);
	return (0);
}
