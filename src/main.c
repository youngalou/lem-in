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

void	load_data(t_data *data)
{
	char	*line;

	get_next_line(0, &line);
	data->ants = ft_atoi(line);
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
	return (data);
}

int		main(void)
{
	t_data	*data;

	data = init_data();
	load_data(data);
	print_rooms(data);
	print_links(data);
	//find_path(data);
	return (0);
}