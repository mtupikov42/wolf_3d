/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:20:24 by mtupikov          #+#    #+#             */
/*   Updated: 2018/04/21 04:02:12 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	parse_conversion(t_pf_st *t_st)
{
	char *c;

	c = ft_strchr("sSpdDioOuUxXcC", *t_st->format);
	if (c)
		t_st->c = *c;
	else
		t_st->c = *t_st->format;
	++t_st->format;
}

int		sm_util(t_pf_st *t_st)
{
	if (*t_st->format == 'l')
	{
		if (*++t_st->format == 'l')
		{
			t_st->sm = SM_LONG2;
			++t_st->format;
		}
		else
			t_st->sm = SM_LONG;
		return (1);
	}
	else if (*t_st->format == 'h')
	{
		if (*++t_st->format == 'h')
		{
			t_st->sm = SM_SHORT2;
			++t_st->format;
		}
		else
			t_st->sm = SM_SHORT;
		return (1);
	}
	return (0);
}

void	parse_size_mod(t_pf_st *t_st)
{
	if (sm_util(t_st))
		return ;
	else if (*t_st->format == 'j')
		t_st->sm = SM_MINT;
	else if (*t_st->format == 'z')
		t_st->sm = SM_SIZE_T;
	if (t_st->sm)
		++t_st->format;
}

void	parse_width_n_precision(t_pf_st *t_st)
{
	t_st->fw = ft_atoi(t_st->format);
	while (ft_isdigit(*t_st->format))
		++t_st->format;
	if (*t_st->format == '.')
	{
		t_st->precision = ft_atoi(&*++t_st->format);
		while (ft_isdigit(*t_st->format))
			++t_st->format;
	}
}

void	parse_flags(t_pf_st *t_st)
{
	char *s;

	while ((s = ft_strchr("-0+ #", *t_st->format)))
	{
		if (*s == '-')
			t_st->is_min = 1;
		if (*s == '+')
			t_st->is_plus = 1;
		if (*s == '0')
			t_st->is_zero = 1;
		if (*s == ' ')
			t_st->is_space = 1;
		if (*s == '#')
			t_st->is_hash = 1;
		t_st->format++;
	}
}
