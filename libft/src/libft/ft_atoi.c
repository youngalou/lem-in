/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:15:54 by lyoung            #+#    #+#             */
/*   Updated: 2017/03/14 11:06:33 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int		i;
	int		j;
	int		val;
	int		neg;

	i = 0;
	j = 0;
	val = 0;
	neg = 1;
	while (ft_isspace(str[i]) || str[i] == '\\')
		i++;
	(str[i] == '-') ? neg = -1 : 0;
	(str[i] == '-' || str[i] == '+') ? i++ : 0;
	while (str[i] == '0')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		val = (val * 10) + (str[i++] - '0');
		j++;
	}
	if (j > 12)
		return ((neg == 1) ? -1 : 0);
	return (val * neg);
}
