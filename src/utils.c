/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:53:18 by lyoung            #+#    #+#             */
/*   Updated: 2017/12/12 10:53:20 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	error(char *line)
{
	ft_strdel(&line);
	ft_printf("ERROR\n");
	exit(0);
}

void	free_all(t_data *data)
{
	void	*tmp;
	void	*tmp2;
	int		i;

	while (data->line)
	{
		tmp = data->line->next;
		ft_strdel(&data->line->str);
		data->line = tmp;
	}
	while (data->room)
	{
		tmp = data->room->next;
		ft_strdel(&data->room->id);
		while (data->room->link)
		{
			tmp2 = data->room->link->next;
			free(data->room->link);
			data->room->link = tmp2;
		}
		free(data->room);
		data->room = tmp;
	}
	while (data->valid)
	{
		tmp = data->valid->next;
		i = 0;
		while (i <= data->valid->len)
		{
			ft_strdel(&data->valid->path[i]);
			i++;
		}
		ft_strdel(data->valid->path);
		free(data->valid);
		data->valid = tmp;
	}
	while (data->optimal)
	{
		tmp = data->optimal->next;
		i = 0;
		while (i <= data->optimal->len)
		{
			ft_strdel(&data->optimal->path[i]);
			i++;
		}
		// ft_strdel(data->optimal->path); // don't need this free?
		free(data->optimal);
		data->optimal = tmp;
	}
	i = 0;
	while (i < data->ants)
	{
		free(data->ant[i]);
		i++;
	}
	free(data->ant);
	free(data);
}

void	print_input(t_data *data)
{
	t_line	*line;

	line = data->line;
	while (line)
	{
		ft_printf("%s\n", line->str);
		line = line->next;
	}
}
