/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:58:45 by lyoung            #+#    #+#             */
/*   Updated: 2017/11/08 10:58:47 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	parse_data(t_data *data, char *line)
{
	int		i;

	i = 0;
	while (line[i] != ' ' && line[i] != '-' && line[i] != '#')
		i++;
	if (line[i] == ' ')
		data->room = parse_room(data, line);
	else if (line[i] == '-')
		parse_link(data, line);
	else if (line[i] == '#')
		parse_comment(data, line);
	else
		error(line);
}

void	store_line(t_data *data, char *line)
{
	t_line	*new;
	t_line	*tmp;

	new = malloc(sizeof(t_line));
	new->str = line;
	new->next = NULL;
	if (!data->line)
	{
		data->line = new;
		return ;
	}
	tmp = data->line;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	load_data(t_data *data)
{
	char	*line;

	get_next_line(0, &line);
	store_line(data, line);
	data->ants = ft_atoi(line);
	while (get_next_line(0, &line) > 0)
	{
		store_line(data, line);
		parse_data(data, line);
	}
}

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data*)malloc(sizeof(t_data));
	data->ants = 0;
	data->rooms = 0;
	data->st_ed = 0;
	data->start_id = 0;
	data->end_id = 0;
	data->line = NULL;
	data->room = NULL;
	data->valid = NULL;
	data->optimal = NULL;
	return (data);
}

int		main(void)
{
	t_data	*data;

	data = init_data();
	load_data(data);
	start_path(data);
	find_optimal_paths(data);
	assign_ants(data);
	print_input(data);
	move_ants(data);
	free_all(data);
	return (0);
}
