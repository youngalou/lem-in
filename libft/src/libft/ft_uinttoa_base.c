/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uinttoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:38:04 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/31 14:42:04 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uinttoa_base(uintmax_t value, int base)
{
	uintmax_t	nb;
	int			digit;
	char		*ret;

	nb = value;
	digit = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	while (value)
	{
		value = value / base;
		digit++;
	}
	ret = ft_strnew(digit);
	digit--;
	while (nb > 0)
	{
		if (nb % base > 9)
			ret[digit] = nb % base + 87;
		else
			ret[digit] = nb % base + '0';
		nb = nb / base;
		digit--;
	}
	return (ret);
}
