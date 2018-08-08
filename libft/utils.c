/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 04:09:52 by mtupikov          #+#    #+#             */
/*   Updated: 2018/04/21 04:11:08 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			num_padding(t_pf_st *t_st, int side, int len, unsigned long value)
{
	int		pad_size;
	char	c;

	check_flags(t_st, len, value, side);
	if (t_st->is_zero && t_st->precision < len)
		c = '0';
	else
		c = ' ';
	if (!t_st->fw)
		return (0);
	if ((pad_size = t_st->fw - len) <= 0)
		return (0);
	if (side == 0 && t_st->is_min == 0)
		return (print_nchar(c, pad_size));
	else if (side == 1 && t_st->is_min == 1)
		return (print_nchar(' ', pad_size));
	return (0);
}

static void	check_f1(t_pf_st *t_st, unsigned long value, int side)
{
	if (t_st->c == 'p' && !side)
	{
		t_st->fw -= 2;
		t_st->length += 2;
		if (t_st->is_zero)
			write(1, "0x", 2);
	}
	else if ((t_st->is_hash && !side) &&
			(t_st->c == 'o' || t_st->c == 'O') && (value || !t_st->precision)
			&& (!t_st->is_hash || t_st->precision <= 0))
	{
		t_st->length++;
		t_st->fw--;
	}
	else if (t_st->is_space && side == 0 && t_st->pr_min == 0 &&
		(t_st->c == 'd' || t_st->c == 'i' || t_st->c == 'D'))
	{
		t_st->length++;
		t_st->fw--;
		write(1, " ", 1);
	}
}

static void	check_f2(t_pf_st *t_st, int len, int side)
{
	if (t_st->precision && t_st->precision > len && !t_st->is_min)
		t_st->fw -= t_st->precision - len;
	if ((t_st->is_zero || (t_st->precision > 0 && t_st->is_zero)
		|| t_st->is_space) && (t_st->pr_min || t_st->is_plus) && !side
			&& ft_tolower(t_st->c) != 'u' && ft_tolower(t_st->c) != 'o' &&
			ft_tolower(t_st->c) != 'x')
	{
		t_st->length++;
		t_st->fw--;
		t_st->is_plus = 0;
		t_st->pr_min == 1 ? write(1, "-", 1) : write(1, "+", 1);
		t_st->pr_min = 0;
	}
	else if ((t_st->pr_min || t_st->is_plus) && !side &&
			ft_tolower(t_st->c) != 'p' &&
			ft_tolower(t_st->c) != 'u' && ft_tolower(t_st->c) != 'c' &&
			ft_tolower(t_st->c) != 'o' && ft_tolower(t_st->c) != 'x')
	{
		t_st->length++;
		t_st->fw--;
	}
}

void		check_flags(t_pf_st *t_st, int len, unsigned long value, int side)
{
	if (t_st->is_plus)
		t_st->is_space = 0;
	if (!t_st->precision && !value && !side)
	{
		t_st->length--;
		t_st->fw++;
	}
	if (t_st->is_hash && value != 0 &&
		(t_st->c == 'x' || t_st->c == 'X'))
	{
		t_st->fw -= 2;
		t_st->length += 2;
		if (t_st->is_zero)
		{
			if (is_upper(t_st->c))
				write(1, "0X", 2);
			else
				write(1, "0x", 2);
		}
	}
	check_f1(t_st, value, side);
	check_f2(t_st, len, side);
}

void		apply_flags(t_pf_st *t_st, unsigned long value)
{
	if (t_st->is_hash && value != 0 && !t_st->is_zero &&
		(t_st->c == 'x' || t_st->c == 'X'))
	{
		if (is_upper(t_st->c))
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}
	else if (t_st->c == 'p' && !t_st->is_zero)
		write(1, "0x", 2);
	else if ((t_st->pr_min || t_st->is_plus) && ft_tolower(t_st->c) != 'u' &&
			ft_tolower(t_st->c) != 'c' && ft_tolower(t_st->c) != 'o' &&
			ft_tolower(t_st->c) != 'x')
		t_st->pr_min == 1 ? write(1, "-", 1) : write(1, "+", 1);
	else if (t_st->is_hash && (t_st->c == 'o' || t_st->c == 'O') &&
			(value || !t_st->precision) && (!t_st->is_hash ||
				t_st->precision <= 0))
		write(1, "0", 1);
	else if (t_st->is_plus && !t_st->pr_min &&
		(t_st->c == 'd' || t_st->c == 'i' ||
		t_st->c == 'D'))
		write(1, "+", 1);
}
