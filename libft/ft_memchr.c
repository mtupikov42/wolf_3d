/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:07:39 by mtupikov          #+#    #+#             */
/*   Updated: 2018/03/23 14:11:52 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *restrict memptr, int val, size_t num)
{
	const unsigned char *mem;

	mem = memptr;
	while (num--)
		if (*mem++ == (unsigned char)val)
			return ((void *)--mem);
	return (NULL);
}
