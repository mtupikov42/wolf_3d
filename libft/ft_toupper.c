/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:51:49 by mtupikov          #+#    #+#             */
/*   Updated: 2018/03/25 20:25:48 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_toupper(int c)
{
	unsigned char uc;

	if (!ft_isascii(c))
		return (c);
	uc = (unsigned char)c;
	if (uc >= 'a' && uc <= 'z')
		return ((int)uc - 32);
	return (c);
}
