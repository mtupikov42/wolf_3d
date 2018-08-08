/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 08:33:09 by mtupikov          #+#    #+#             */
/*   Updated: 2018/03/25 20:18:47 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *str, int symbol)
{
	while (*str)
	{
		if (*str == symbol)
			return ((char *)&*str);
		str++;
	}
	if (*str == symbol)
		return ((char *)&*str);
	return (NULL);
}
