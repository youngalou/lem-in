/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:35:07 by lyoung            #+#    #+#             */
/*   Updated: 2017/12/13 13:35:09 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	error_ants(t_data *data, char *line)
{
	if (!line || !is_digits(line))
		error(data);
	else if (line[0] == 0 || line[0] == '\n')
		error(data);
	else if ((data->ants = ft_atoi(line)) == 0)
		error(data);
}

int		check_room(t_data *data, char *line)
{
	char	**str;

	(void)data;
	if (count_words(line, ' ') != 3)
		return (0);
	str = ft_strsplit(line, ' ');
	if (!is_digits(str[1]) || !is_digits(str[2]))
		return (0);
	else if (str[0][0] == '#')
		return (0);
	return (1);
}

int		check_link(t_data *data, char *line)
{
	char	**str;
	t_room	*room;
	char	r1;
	char	r2;

	if (count_words(line, '-') != 2)
		return (0);
	str = ft_strsplit(line, '-');
	r1 = 0;
	r2 = 0;
	room = data->room;
	while (room)
	{
		if (!ft_strcmp(str[0], room->id))
			r1++;
		if (!ft_strcmp(str[1], room->id))
			r2++;
		room = room->next;
	}
	if (r1 == 1 && r2 == 1)
		return (1);
	return (0);
}

int		check_comment(t_data *data, char *line)
{
	int		i;

	(void)data;
	i = 0;
	while (i < 2 && line[i])
	{
		if (line[i] != '#')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}
