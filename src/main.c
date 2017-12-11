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

#include "../lem-in.h"

void	error(char *line)
{
	ft_strdel(&line);
	ft_printf("ERROR\n");
	exit(0);
}

void	load_data(t_data *data)
{
	char	*line;

	get_next_line(0, &line);
	data->ants = ft_atoi(line);
	ft_strdel(&line);
	while (get_next_line(0, &line) > 0)
		parse_data(data, line);
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
	// print_links(data);
	// print_paths(data);
	print_optimal_paths(data);
	return (0);
}
