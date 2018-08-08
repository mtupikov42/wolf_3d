/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 08:22:19 by mtupikov          #+#    #+#             */
/*   Updated: 2018/03/25 20:09:28 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t num)
{
	size_t len;

	if (!*str2)
		return ((char *)str1);
	len = ft_strlen(str2);
	while (*str1 && num-- >= len)
	{
		if (*str1 == *str2 && ft_memcmp(str1, str2, len) == 0)
			return ((char *)str1);
		str1++;
	}
	return (NULL);
}
