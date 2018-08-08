/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 04:08:44 by mtupikov          #+#    #+#             */
/*   Updated: 2018/04/21 04:08:58 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_itoa_base(t_pf_st *t_st, unsigned long value,
	unsigned long base, int up)
{
	unsigned long			i;
	char					*hex;
	int						ret;

	i = 1;
	ret = ft_itoa_count(value, base);
	hex = "0123456789ABCDEF";
	while (value / i > base - 1)
		i *= base;
	ret += num_padding(t_st, 0, ret, value);
	apply_flags(t_st, value);
	ret += precision(t_st, ft_itoa_count(value, base));
	if ((t_st->precision && value) || (!value && t_st->precision) || value)
		while (i != 0)
		{
			if (up)
				ft_putchar(hex[value / i]);
			else
				ft_putchar(ft_tolower(hex[value / i]));
			value %= i;
			i /= base;
		}
	ret += num_padding(t_st, 1, ret, value);
	return (ret);
}

int		ft_itoa_count(unsigned long value, unsigned long base)
{
	unsigned long	i;
	unsigned long	j;
	int				c;

	c = 0;
	j = 0;
	i = 1;
	while (value / i > base - 1)
		i *= base;
	while (i != 0)
	{
		c++;
		value %= i;
		i /= base;
		j++;
	}
	return (c);
}
