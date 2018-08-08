/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:52:28 by mtupikov          #+#    #+#             */
/*   Updated: 2018/03/25 20:32:08 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;

	i = 0;
	if (s1 && s2)
	{
		if (!(ret = (char *)malloc(sizeof(char) +
			(ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		while (s1[i])
		{
			ret[i] = s1[i];
			i++;
		}
		i = 0;
		while (s2[i])
		{
			ret[i + ft_strlen(s1)] = s2[i];
			i++;
		}
		ret[i + ft_strlen(s1)] = '\0';
		return (ret);
	}
	return (NULL);
}
