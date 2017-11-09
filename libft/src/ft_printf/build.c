/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:49:53 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/06 13:43:22 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_res	*init_res(size_t cap)
{
	t_res	*res;

	res = (t_res*)malloc(sizeof(t_res));
	res->out = ft_strnew(cap);
	res->cap = cap;
	res->len = 0;
	res->size = 0;
	res->start = 0;
	res->fmt = 0;
	res->place = 0;
	return (res);
}

int		resize_res(t_res *res, size_t size)
{
	char	*tmp;

	if (res == 0 || res->cap == 0)
		return (-1);
	if (size + res->len > res->cap)
	{
		while (size + res->len > res->cap)
			res->cap = res->cap * 2;
		tmp = ft_strnew(res->cap);
		ft_strcpy(tmp, res->out);
		ft_strdel(&res->out);
		res->out = tmp;
	}
	return (0);
}

void	check_res(t_res *res, size_t size)
{
	if (size + res->len > res->cap)
		resize_res(res, size);
}

void	free_res(t_res *res)
{
	ft_strdel(&res->out);
	ft_strdel(&res->start);
	free(res);
}
