/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 03:47:07 by mtupikov          #+#    #+#             */
/*   Updated: 2018/04/03 03:47:09 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_count_words(const char *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			s++;
			if (*s == c || ft_strlen(s) == 0)
				count++;
		}
	}
	return (count);
}
