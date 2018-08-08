/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:44:29 by mtupikov          #+#    #+#             */
/*   Updated: 2018/03/25 20:33:32 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *restrict destptr,
		const void *restrict srcptr, size_t num)
{
	char	*temp;

	temp = ft_strnew(num);
	if (temp)
	{
		temp = ft_memcpy(temp, srcptr, num);
		destptr = ft_memcpy(destptr, temp, num);
	}
	free(temp);
	return (destptr);
}
