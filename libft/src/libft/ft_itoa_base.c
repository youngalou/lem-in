/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:38:04 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/06 15:21:37 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*build_ret(intmax_t nb, int base, int digit, int neg_flag)
{
	char		*ret;
	intmax_t	base_var;

	base_var = 1;
	while (nb >= base_var)
	{
		base_var = base * base_var;
		digit++;
	}
	ret = (char*)malloc(sizeof(ret) * (digit + 1));
	ret[digit] = '\0';
	digit--;
	(neg_flag) ? ret[0] = '-' : 0;
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

char	*ft_itoa_base(intmax_t value, int base)
{
	intmax_t	nb;
	int			digit;
	int			neg_flag;

	nb = value;
	digit = 0;
	neg_flag = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb < 0)
	{
		nb = -nb;
		if (base == 10)
		{
			digit++;
			neg_flag = 1;
		}
	}
	return (build_ret(nb, base, digit, neg_flag));
}
