/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:29:35 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/25 14:36:12 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(intmax_t n)
{
	size_t		count;

	count = 1;
	while ((n = n / 10) != 0)
		count++;
	return (count);
}

char			*ft_itoa(intmax_t n)
{
	int			neg;
	uintmax_t	nb;
	int			len;
	char		*str;

	neg = (n >= 0) ? 0 : 1;
	nb = (neg == 0) ? n : -n;
	len = count_digits(nb);
	len = (neg == 0) ? len : len + 1;
	str = (char*)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	if (neg == 1)
		str[0] = '-';
	str[len] = '\0';
	while (len > neg)
	{
		len--;
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
