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

void	error(t_data *data)
{
	(void)data;
	// free_all(data);
	ft_printf("ERROR\n");
	exit(0);
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

int		is_digits(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}
