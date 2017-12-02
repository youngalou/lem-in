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

char	**cpy_2D(char **dest, char **src, int n)
{
	int		i;

	dest = (char**)malloc(sizeof(char*) * n);
	i = 0;
	while (i < n)
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	return (dest);
}

void	add_valid_path(t_data *data, char **path, int path_len)
{
	t_vpath *valid;
	t_vpath *new;
	int		i;

	ft_printf("VALID\n");
	new = malloc(sizeof(t_vpath));
	new->path = cpy_2D(new->path, path, path_len + 1);
	new->len = path_len;
	new->next = NULL;
	i = 0;
	while (i < path_len)
		i++;
	if (!data->valid)
	{
		data->valid = new;
		return ;
	}
	valid = data->valid;
	while (valid->next)
		valid = valid->next;
	valid->next = new;
}

void	add_to_path(char **path, char *room_id)
{
	int		i;

	i = 0;
	while (path[i])
	{
		ft_printf("%s ", path[i]);
		i++;
	}
	ft_printf("%s\n", room_id);
	path[i] = ft_strdup(room_id);
}

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
	t_link	*link;

	ft_printf("room: %s\n", room->id);
	link = room->link;
	while (link)
	{
		ft_printf("- link: %s\n", link->room->id);
		if (!ft_strcmp(link->room->id, data->end_id))
			add_valid_path(data, path, path_len);
		if (!search_path(path, link->room->id))
		{
			add_to_path(path, link->room->id);
			find_path(data, link->room, path, path_len + 1);
		}
		link = link->next;
	}
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
	add_to_path(path, room->id); //adds the start room to the path
	find_path(data, room, path, 0);
}