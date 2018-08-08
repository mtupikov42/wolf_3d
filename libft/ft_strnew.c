/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 12:38:56 by mtupikov          #+#    #+#             */
/*   Updated: 2018/03/25 12:44:06 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *ret;

	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(ret, size + 1);
	return (ret);
}
