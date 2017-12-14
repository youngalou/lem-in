/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:04:09 by lyoung            #+#    #+#             */
/*   Updated: 2017/12/12 11:04:12 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	free_rooms(t_data *data)
{
	void	*tmp;
	void	*tmp2;

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
}

void	free_valid(t_data *data)
{
	void	*tmp;
	int		i;

	while (data->valid)
	{
		tmp = data->valid->next;
		i = 0;
		while (i <= data->valid->len)
		{
			ft_strdel(&data->valid->path[i]);
			i++;
		}
		free(data->valid->path);
		free(data->valid);
		data->valid = tmp;
	}
}

void	free_optimal(t_data *data)
{
	void	*tmp;
	int		i;

	while (data->optimal)
	{
		tmp = data->optimal->next;
		i = 0;
		while (i <= data->optimal->len)
		{
			ft_strdel(&data->optimal->path[i]);
			i++;
		}
		free(data->optimal->path);
		free(data->optimal);
		data->optimal = tmp;
	}
}

void	free_ants(t_data *data)
{
	int		i;

	if (data->ant)
	{
		i = 0;
		while (i < data->ants)
		{
			free(data->ant[i]);
			i++;
		}
		free(data->ant);
	}
}

void	free_all(t_data *data)
{
	void	*tmp;

	free_rooms(data);
	free_valid(data);
	free_optimal(data);
	free_ants(data);
	while (data->line)
	{
		tmp = data->line->next;
		ft_strdel(&data->line->str);
		free(data->line);
		data->line = tmp;
	}
	free(data);
}
