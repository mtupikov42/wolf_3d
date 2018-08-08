/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:35:38 by mtupikov          #+#    #+#             */
/*   Updated: 2018/03/23 13:38:55 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *restrict memptr, int val, size_t num)
{
	char	*mem;
	size_t	i;

	mem = (char *)memptr;
	i = 0;
	while (i < num)
	{
		mem[i] = val;
		i++;
	}
	return (memptr);
}
