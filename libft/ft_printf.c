/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 04:13:33 by mtupikov          #+#    #+#             */
/*   Updated: 2018/04/21 04:16:23 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	parse_options(t_pf_st *t_st)
{
	t_st->m_length = 0;
	t_st->c = 0;
	t_st->precision = -1;
	t_st->sm = 0;
	t_st->is_hash = 0;
	t_st->is_min = 0;
	t_st->is_plus = 0;
	t_st->is_zero = 0;
	t_st->is_space = 0;
	t_st->pr_min = 0;
	parse_flags(t_st);
	parse_width_n_precision(t_st);
	parse_size_mod(t_st);
	parse_conversion(t_st);
	print(t_st);
}

int		ft_printf(const char *format, ...)
{
	t_pf_st t_st;

	t_st.length = 0;
	t_st.format = (char *)format;
	va_start(t_st.list, format);
	while (*t_st.format)
	{
		if (*t_st.format == '%')
		{
			if (*++t_st.format == '%' || *t_st.format == '\0')
			{
				if (*t_st.format == '\0')
					break ;
				t_st.length += print_char('%');
				++t_st.format;
				continue ;
			}
			parse_options(&t_st);
			continue ;
		}
		t_st.length++;
		write(1, &*t_st.format++, 1);
	}
	va_end(t_st.list);
	return (t_st.length);
}
