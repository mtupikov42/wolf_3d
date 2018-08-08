/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 08:34:42 by mtupikov          #+#    #+#             */
/*   Updated: 2018/03/25 20:03:45 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_tolower(int c)
{
	unsigned char uc;

	if (!ft_isascii(c))
		return (c);
	uc = (unsigned char)c;
	if (c >= 'A' && c <= 'Z')
		return ((int)uc + 32);
	return (c);
}
