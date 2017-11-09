/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:58:12 by lyoung            #+#    #+#             */
/*   Updated: 2017/11/08 15:58:13 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

void	print_rooms(t_data *data)
{
	t_room	*room;

	ft_printf("start: %d\tend: %d\n", data->start, data->end);
	room = data->room;
	while (room)
	{
		ft_printf("name: %d\tx: %d\ty: %d\n", room->name, room->x, room->y);
		room = room->next;
	}
}

void	print_hash(t_data *data)
{
	int		i;

	ft_printf("start: %d\tend: %d\n", data->start, data->end);
	i = 0;
	while (i < data->rooms)
	{
		ft_printf("name: %d\tx: %d\ty: %d\n", data->hash[i]->name, data->hash[i]->x, data->hash[i]->y);
		i++;
	}
}