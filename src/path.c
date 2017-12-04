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

void	add_to_path(t_data *data, char **path, char *room_id)
{
	int		i;

	i = 0;
	while (i < data->rooms && path[i])
		i++;
	path[i] = ft_strdup(room_id);
}

void	remove_from_path(t_data *data, char **path, char *room_id)
{
	int		i;

	i = 0;
	while (i < data->rooms && path[i])
	{
		if (!ft_strcmp(path[i], room_id))
			ft_strdel(&path[i]);
		i++;
	}
}

int		search_path(t_data *data, char **path, char *room_id)
{
	int		i;

	i = 0;
	while (i < data->rooms && path[i])
	{
		if (!ft_strcmp(path[i], room_id))
			return (1);
		i++;
	}
	return (0);
}

void	find_path(t_data *data, t_room *room, char **path, int path_len)
{
	t_link	*link;

	add_to_path(data, path, room->id);
	if (!ft_strcmp(room->id, data->end_id))
	{
		add_valid_path(data, path, path_len);
		remove_from_path(data, path, room->id);
		return ;
	}
	link = room->link;
	while (link)
	{
		if (!search_path(data, path, link->room->id))
			find_path(data, link->room, path, path_len + 1);
		link = link->next;
	}
	remove_from_path(data, path, room->id);
}

void	start_path(t_data *data)
{
	char	**path;
	t_room	*room;
	int		i;

	path = malloc(sizeof(char*) * data->rooms);
	i = 0;
	while (i < data->rooms)
	{
		path[i] = NULL;
		i++;
	}
	room = data->room;
	while (room && ft_strcmp(room->id, data->start_id))
		room = room->next;
	find_path(data, room, path, 1);
}
