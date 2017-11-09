/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:49:11 by lyoung            #+#    #+#             */
/*   Updated: 2017/03/12 09:53:26 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		trim_front(const char *s)
{
	int		i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	return (i);
}

static int		trim_end(const char *s)
{
	int		i;
	int		count;

	i = ft_strlen(s) - 1;
	count = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		count++;
		i--;
	}
	return (count);
}

char			*ft_strtrim(const char *s)
{
	int		i;
	int		j;
	int		front;
	int		end;
	char	*str;

	if (!s)
		return (0);
	front = trim_front(s);
	end = (s[front] == '\0') ? 0 : trim_end(s);
	str = (char*)malloc(ft_strlen(s) + 1 - front - end);
	if (!str)
		return (0);
	i = front;
	j = 0;
	while (i < (int)ft_strlen(s) - end)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
