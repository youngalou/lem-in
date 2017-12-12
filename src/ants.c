/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:01:01 by lyoung            #+#    #+#             */
/*   Updated: 2017/12/11 12:01:02 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

t_ant	*new_ant(t_vpath *path, int i)
{
	t_ant	*new;

	new = malloc(sizeof(t_ant));
	new->num = i + 1;
	new->route = path;
	new->pos = 0;
	return (new);
}

void	assign_ants(t_data *data)
{
	int		i;
	t_vpath	*opt;
	t_vpath	*best;

	data->ant = malloc(sizeof(t_ant*) * data->ants);
	i = 0;
	while (i < data->ants)
	{
		opt = data->optimal;
		best = NULL;
		while (opt)
		{
			if (!best || opt->cost < best->cost)
				best = opt;
			opt = opt->next;
		}
		data->ant[i] = new_ant(best, i);
		best->cost++;
		i++;
	}
}

void	check_room_vac(t_data *data, t_ant *ant)
{
	char	*check;
	char	*prev;
	t_room	*room;

	if (ant->pos >= ant->route->len)
		return ;
	check = ant->route->path[ant->pos + 1];
	prev = ant->route->path[ant->pos];
	room = data->room;
	while (ft_strcmp(room->id, check))
		room = room->next;
	if (room->vac)
		return ;
	ant->pos++;
	if (ant->pos < ant->route->len)
		room->vac = 1;
	data->flag = 0;
	ft_printf("L%d-%s ", ant->num, room->id);
	room = data->room;
	while (ft_strcmp(room->id, prev))
		room = room->next;
	room->vac = 0;
}

void	move_ants(t_data *data)
{
	int		i;

	data->flag = 0;
	while (!data->flag)
	{
		ft_putchar('\n');
		data->flag = 1;
		i = 0;
		while (i < data->ants)
		{
			check_room_vac(data, data->ant[i]);
			i++;
		}
	}
}
