/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:15:03 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/06 14:15:33 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_words(const char *s, char c)
{
	int		count;
	int		in_sub;

	count = 0;
	in_sub = 0;
	while (*s)
	{
		if (*s == c && in_sub == 1)
			in_sub = 0;
		if (*s != c && in_sub == 0)
		{
			in_sub = 1;
			count++;
		}
		s++;
	}
	return (count);
}
