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

void	parse_link(t_data *data, char *line)
{
	int		r1;
	int		r2;
	int		i;
	t_room	**hash;

	r1 = ft_atoi(line);
	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	i++;
	r2 = ft_atoi(&line[i]);
	hash = data->hash;
	//hash[r1]->link = (t_link*)malloc(sizeof(t_link));
	ft_strdel(&line);
}

t_room	 *parse_room(t_data *data, char *line)
{
	t_room	*new;
	t_room	*room;
	int		i;

	new = (t_room*)malloc(sizeof(t_room));
	new->name = ft_atoi(line);
	if (data->st_ed == 1)
		data->start = new->name;
	else if (data->st_ed == 2)
		data->end = new->name;
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
	{
		if (!data->hash_flag)
			set_hash(data);
		parse_link(data, line);
	}
	else if (line[i] == '#')
		parse_comment(data, line);
	else
		error();
}