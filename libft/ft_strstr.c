/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 08:31:56 by mtupikov          #+#    #+#             */
/*   Updated: 2018/03/25 20:04:59 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int tr;
	int i;
	int j;

	i = 0;
	if (ft_strlen(str2) == 0)
		return ((char *)str1);
	while (str1[i])
	{
		j = 0;
		tr = 1;
		while (str2[j])
		{
			if (str2[j] != str1[i + j])
				tr = 0;
			j++;
		}
		if (tr)
			return ((char *)&str1[i]);
		i++;
	}
	return (NULL);
}
