/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:56:29 by lyoung            #+#    #+#             */
/*   Updated: 2017/11/08 15:56:31 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	parse_comment(t_data *data, char *line)
{
	if (!ft_strcmp(line, "##start"))
	{
		if (data->start_id)
			error(data);
		data->st_ed = 1;
	}
	else if (!ft_strcmp(line, "##end"))
	{
		if (data->end_id)
			error(data);
		data->st_ed = 2;
	}
}

t_link	*add_link(t_data *data, t_room *r1, t_room *r2, char *link_id)
{
	t_link	*link;
	t_link	*new;
	int		dist_x;
	int		dist_y;

	while (r2->next && ft_strcmp(r2->id, link_id))
		r2 = r2->next;
	dist_x = r1->x - r2->x;
	dist_y = r1->y - r2->y;
	new = (t_link*)malloc(sizeof(t_link));
	new->room = r2;
	new->dist = sqrt((dist_x * dist_x) + (dist_y * dist_y));
	new->next = NULL;
	if (!r1->link)
		return (new);
	link = r1->link;
	while (link->next)
	{
		if (!ft_strcmp(link->room->id, link_id))
			error(data);
		link = link->next;
	}
	if (ft_strcmp(link->room->id, link_id))
		link->next = new;
	return (r1->link);
}

void	parse_link(t_data *data, char *line)
{
	char	**str;
	char	*r1;
	char	*r2;
	t_room	*room;

	str = ft_strsplit(line, '-');
	r1 = str[0];
	r2 = str[1];
	room = data->room;
	while (room)
	{
		if (!ft_strcmp(room->id, r1))
			room->link = add_link(data, room, data->room, r2);
		else if (!ft_strcmp(room->id, r2))
			room->link = add_link(data, room, data->room, r1);
		room = room->next;
	}
	ft_strdel(&str[0]);
	ft_strdel(&str[1]);
	free(str);
}

t_room	*add_room(t_data *data, char **str)
{
	t_room	*new;

	new = (t_room*)malloc(sizeof(t_room));
	new->id = str[0];
	if (data->st_ed == 1)
		data->start_id = new->id;
	else if (data->st_ed == 2)
		data->end_id = new->id;
	data->st_ed = 0;
	new->x = ft_atoi(str[1]);
	new->y = ft_atoi(str[2]);
	new->vac = 0;
	new->link = NULL;
	new->next = NULL;
	check_coordinates(data, new);
	return (new);
}

t_room	*parse_room(t_data *data, char *line)
{
	char	**str;
	t_room	*new;
	t_room	*room;

	if (*line == 'L')
		error(data);
	str = ft_strsplit(line, ' ');
	new = add_room(data, str);
	data->rooms++;
	ft_strdel(&str[1]);
	ft_strdel(&str[2]);
	free(str);
	if (!data->room)
		return (new);
	room = data->room;
	while (room->next)
		room = room->next;
	room->next = new;
	return (data->room);
}
