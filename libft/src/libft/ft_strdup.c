/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 09:53:56 by lyoung            #+#    #+#             */
/*   Updated: 2017/03/05 12:44:20 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dupl;

	i = 0;
	dupl = (char*)malloc(ft_strlen(str) + 1);
	if (!dupl)
		return (NULL);
	while (str[i])
	{
		dupl[i] = str[i];
		i++;
	}
	dupl[i] = '\0';
	return (dupl);
}
