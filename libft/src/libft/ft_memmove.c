/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:39:51 by lyoung            #+#    #+#             */
/*   Updated: 2017/03/05 15:42:37 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tempdst;
	unsigned const char	*tempsrc;

	tempdst = (unsigned char*)dst;
	tempsrc = (unsigned char*)src;
	if (tempsrc < tempdst)
	{
		while (len--)
			tempdst[len] = tempsrc[len];
	}
	else
		ft_memcpy(tempdst, tempsrc, len);
	return (tempdst);
}
