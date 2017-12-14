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

#include "../lemin.h"

char	**copy_path(char **dest, char **src, int n)
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

t_vpath	*add_path(t_vpath *valid, char **path, int path_len)
{
	t_vpath *new;
	t_vpath *tmp;

	new = malloc(sizeof(t_vpath));
	new->path = copy_path(new->path, path, path_len + 1);
	new->len = path_len;
	new->cost = path_len;
	new->next = NULL;
	if (!valid)
		return (new);
	tmp = valid;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (valid);
}

int		search_path(char **path, char *room_id, int path_len)
{
	int		i;

	i = 0;
	while (i <= path_len && path[i])
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

	path[path_len] = ft_strdup(room->id);
	if (!ft_strcmp(room->id, data->end_id))
	{
		data->valid = add_path(data->valid, path, path_len);
		ft_strdel(&path[path_len]);
		return ;
	}
	link = room->link;
	while (link)
	{
		if (!search_path(path, link->room->id, path_len))
			find_path(data, link->room, path, path_len + 1);
		link = link->next;
	}
	ft_strdel(&path[path_len]);
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
	find_path(data, room, path, 0);
	free(path);
	if (!data->valid)
		error(data);
}
