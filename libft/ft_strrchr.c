/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:51:49 by mtupikov          #+#    #+#             */
/*   Updated: 2018/03/25 21:15:35 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *str, int symbol)
{
	int i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == symbol)
			return ((char *)&str[i]);
		i--;
	}
	if (str[i] == symbol)
		return ((char *)&str[i]);
	return (NULL);
}
