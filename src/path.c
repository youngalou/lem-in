/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:58:59 by lyoung            #+#    #+#             */
/*   Updated: 2017/11/16 11:59:00 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

int		search_path(char **path, char *room_id)
{
	int		i;

	i = 0;
	while (path[i])
	{
		if (!ft_strcmp(path[i], room_id))
			return (1);
		i++;
	}
	return (0);
}

void	find_path(t_data *data, t_room *room, char **path, int path_len)
{
	int		i;
	int		j;
	t_link	*link;

	i = 0;
	while (path[i])
		i++;
	path[i] = room->id;
	link = room->link;
	while (link->next)
	{
		if (!search_path(path, link->room->id))
			find_path(data, link->room, path, path_len + link->dist);
		if (link->room->id == data->end_id)
		{
			j = 0;
			while (data->paths[j])
				j++;
			data->paths[j] = path;
		}
		link = link->next;
	}
}

void	start_path(t_data *data)
{
	t_room	*room;
	char	**path;

	data->paths = malloc(sizeof(char**) * data->ants);
	path = malloc(sizeof(char*) * data->rooms + 1);
	ft_bzero(path, data->rooms + 1);
	room = data->room;
	while (room && ft_strcmp(room->id, data->start_id))
		room = room->next;
	find_path(data, room, path, 0);
}