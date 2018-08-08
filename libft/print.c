/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 04:06:37 by mtupikov          #+#    #+#             */
/*   Updated: 2018/04/21 04:21:17 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int				is_upper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

static int		get_base(char c)
{
	if (c == 'p' || c == 'x' || c == 'X')
		return (16);
	else if (c == 'o' || c == 'O')
		return (8);
	else
		return (10);
}

int				precision(t_pf_st *t_st, int len)
{
	int prec_size;

	if ((prec_size = t_st->precision - len) <= 0)
		return (0);
	return (print_nchar('0', prec_size));
}

void			print(t_pf_st *t_st)
{
	char *a;

	if (ft_strchr("di", t_st->c))
		t_st->length += print_int(t_st, 10);
	else if ((a = ft_strchr("ouxX", t_st->c)))
		t_st->length += print_uint(t_st, get_base(*a), is_upper(t_st->c));
	else if ((a = ft_strchr("DOU", t_st->c)))
		t_st->length += print_lint(t_st, get_base(*a));
	else if (t_st->c == 's' && t_st->sm != SM_LONG)
		t_st->length += print_str(t_st,
		va_arg(t_st->list, char *), t_st->precision);
	else if (t_st->c == 'S' || t_st->c == 's')
		t_st->length += print_wstr(t_st,
		va_arg(t_st->list, wchar_t *), t_st->precision);
	else if (t_st->c == 'c')
		t_st->length += print_chr(t_st, 0);
	else if (t_st->c == 'C')
		t_st->length += print_wchr(va_arg(t_st->list, wint_t));
	else if (t_st->c == 'p')
		t_st->length += print_ptr(t_st);
	else
		t_st->length += print_chr(t_st, t_st->c);
}
