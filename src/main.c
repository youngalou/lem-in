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
	if (check_room(data, line))
		data->room = parse_room(data, line);
	else if (check_link(data, line))
		parse_link(data, line);
	else if (check_comment(data, line))
		parse_comment(data, line);
	else
		error(data);
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
	int		bytes;

	get_next_line(0, &line);
	store_line(data, line);
	error_ants(data, line);
	while ((bytes = get_next_line(0, &line)) != 0)
	{
		if (bytes < 0)
			error(data);
		store_line(data, line);
		parse_data(data, line);
	}
	if (!data->start_id || !data->end_id)
		error(data);
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
	data->ant = NULL;
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
