/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:20:44 by mtupikov          #+#    #+#             */
/*   Updated: 2018/04/18 13:29:38 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		put1byte(wint_t num)
{
	ft_putchar((unsigned int)num);
	return (1);
}

static int		put2bytes(wint_t num)
{
	unsigned int nbr;

	nbr = (unsigned int)num;
	ft_putchar(192 | (nbr >> 6 & 63));
	ft_putchar(128 | (nbr & 63));
	return (2);
}

static int		put3bytes(wint_t num)
{
	unsigned int nbr;

	nbr = (unsigned int)num;
	ft_putchar(224 | (nbr >> 12 & 63));
	ft_putchar(128 | (nbr >> 6 & 63));
	ft_putchar(128 | (nbr & 63));
	return (3);
}

static int		put4bytes(wint_t num)
{
	unsigned int nbr;

	nbr = (unsigned int)num;
	ft_putchar(240 | ((nbr >> 18) & 63));
	ft_putchar(128 | ((nbr >> 12) & 63));
	ft_putchar(128 | ((nbr >> 6) & 63));
	ft_putchar(128 | (nbr & 63));
	return (4);
}

int				print_wchr(wint_t num)
{
	unsigned int nbr;

	nbr = (unsigned int)num;
	if (nbr <= 127)
		return (put1byte(num));
	else if (nbr <= 2047)
		return (put2bytes(num));
	else if (nbr <= 65535)
		return (put3bytes(num));
	else
		return (put4bytes(num));
}
