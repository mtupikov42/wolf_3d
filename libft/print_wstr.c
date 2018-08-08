/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 04:04:58 by mtupikov          #+#    #+#             */
/*   Updated: 2018/04/21 04:05:56 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		ft_wcharlen(wint_t nbr)
{
	if (nbr <= 127)
		return (1);
	else if (nbr <= 2047)
		return (2);
	else if (nbr <= 65535)
		return (3);
	else
		return (4);
}

static int		ft_strlen_w(const wchar_t *s)
{
	int len;

	len = 0;
	while (*s)
	{
		len += ft_wcharlen(*s);
		s++;
	}
	return (len);
}

static int		padding_w(t_pf_st *t_st, int side, wchar_t *s)
{
	int		pad_size;
	char	c;

	if (!t_st->fw)
		return (0);
	if (t_st->is_zero)
		c = '0';
	else
		c = ' ';
	if (t_st->precision < ft_strlen_w(s) && !side &&
		ft_strlen_w(s) && t_st->precision >= 0)
		t_st->fw += ft_strlen_w(s) - t_st->precision +
		(ft_wcharlen(*s) > 1 && t_st->precision ? 1 : 0);
	if ((pad_size = t_st->fw - ft_strlen_w(s)) <= 0)
		return (0);
	if (side == 0 && t_st->is_min == 0)
		return (print_nchar(c, pad_size));
	else if (side == 1 && t_st->is_min == 1)
		return (print_nchar(' ', pad_size));
	return (0);
}

int				print_wstr(t_pf_st *t_st, wchar_t *str, int prec)
{
	int		len;
	wchar_t	*cp;

	cp = str;
	if (!str)
		str = L"(null)";
	len = 0;
	len += padding_w(t_st, 0, str);
	if (prec == -1)
		while (*str)
		{
			len += print_wchr(*str);
			str++;
		}
	else
		while (*str)
		{
			if (prec < ft_wcharlen(*str))
				break ;
			len += print_wchr(*str);
			prec -= ft_wcharlen(*str);
			str++;
		}
	len += padding_w(t_st, 1, cp);
	return (len);
}
