/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:13:13 by mtupikov          #+#    #+#             */
/*   Updated: 2018/03/23 13:27:03 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strnlen(const char *str, size_t max)
{
	size_t i;

	i = 0;
	while (i < max)
	{
		if (str[i] == '\0')
			return ((size_t)ft_strlen(str));
		i++;
	}
	return (max);
}
