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

#include "../lem-in.h"

void	error(void)
{
	ft_printf("ERROR\n");
	exit(0);
}

void	parse_comment(t_data *data, char *line)
{
	if (ft_strcmp(line, "##start") == 0)
		data->st_ed = 1;
	else if (ft_strcmp(line, "##end") == 0)
		data->st_ed = 2;
	ft_strdel(&line);
}

t_link	*add_link(t_room *r1, t_room *r2, int link_id)
{
	t_link	*link;
	t_link	*new;

	while (r2->id != link_id && r2->next)
		r2 = r2->next;
	new = (t_link*)malloc(sizeof(t_link));
	new->room = r2;
	new->next = NULL;
	if (!r1->link)
		return (new);
	link = r1->link;
	while (link->next)
	{
		if (link->room->id == r1->id)
			return (r1->link);
		link = link->next;
	}
	if (link->room->id != link_id)
		link->next = new;
	return (r1->link);
}

void	parse_link(t_data *data, char *line)
{
	int		r1;
	int		r2;
	int		i;
	t_room	*room;

	r1 = ft_atoi(line);
	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	i++;
	r2 = ft_atoi(&line[i]);
	room = data->room;
	while (room)
	{
		if (room->id == r1)
			room->link = add_link(room, data->room, r2);
		else if (room->id == r2)
			room->link = add_link(room, data->room, r1);
		room = room->next;
	}
	ft_strdel(&line);
}

t_room	 *parse_room(t_data *data, char *line)
{
	t_room	*new;
	t_room	*room;
	int		i;

	new = (t_room*)malloc(sizeof(t_room));
	new->id = ft_atoi(line);
	if (data->st_ed == 1)
		data->start = new->id;
	else if (data->st_ed == 2)
		data->end = new->id;
	data->st_ed = 0;
	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	i++;
	new->x = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	new->y = ft_atoi(&line[i]);
	new->next = NULL;
	new->link = NULL;
	data->rooms++;
	ft_strdel(&line);
	if (!data->room)
		return (new);
	room = data->room;
	while (room->next)
		room = room->next;
	room->next = new;
	return (data->room);
}

void	parse_data(t_data *data, char *line)
{
	int		i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == ' ')
		data->room = parse_room(data, line);
	else if (line[i] == '-')
		parse_link(data, line);
	else if (line[i] == '#')
		parse_comment(data, line);
	else
		error();
}