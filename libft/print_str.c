/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 04:03:24 by mtupikov          #+#    #+#             */
/*   Updated: 2018/04/21 04:04:30 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int				print_nchar(char c, int n)
{
	int l;

	l = n;
	while (l--)
		write(1, &c, 1);
	return (n);
}

int				print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

static int		padding(t_pf_st *t_st, int side, char *s)
{
	int		pad_size;
	char	c;

	if (!t_st->fw)
		return (0);
	if (t_st->is_zero)
		c = '0';
	else
		c = ' ';
	if (!t_st->fw)
		return (0);
	if (t_st->precision < (int)ft_strlen(s) &&
		!side && ft_strlen(s) && t_st->precision >= 0)
		t_st->fw += ft_strlen(s) - t_st->precision;
	if ((pad_size = t_st->fw - (int)ft_strlen(s)) <= 0)
		return (0);
	if (side == 0 && t_st->is_min == 0)
		return (print_nchar(c, pad_size));
	else if (side == 1 && t_st->is_min == 1)
		return (print_nchar(' ', pad_size));
	return (0);
}

int				print_str(t_pf_st *t_st, char *str, int prec)
{
	int len;

	if (!str)
		str = "(null)";
	len = 0;
	len += padding(t_st, 0, str);
	while (*str && prec--)
	{
		len += print_char(*str);
		str++;
	}
	len += padding(t_st, 1, str - len);
	return (len);
}
