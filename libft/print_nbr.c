/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:19:52 by mtupikov          #+#    #+#             */
/*   Updated: 2018/04/18 13:29:09 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		print_int(t_pf_st *t_st, int base)
{
	long long int nbr;

	if (t_st->sm == SM_SHORT2)
		nbr = (signed char)va_arg(t_st->list, long long int);
	else if (t_st->sm == SM_SHORT)
		nbr = (short)va_arg(t_st->list, long long int);
	else if (t_st->sm == SM_LONG)
		nbr = (long)va_arg(t_st->list, long long int);
	else if (t_st->sm == SM_LONG2)
		nbr = va_arg(t_st->list, long long int);
	else if (t_st->sm == SM_MINT)
		nbr = (intmax_t)va_arg(t_st->list, long long int);
	else if (t_st->sm == SM_SIZE_T)
		nbr = (size_t)va_arg(t_st->list, long long int);
	else
		nbr = (int)va_arg(t_st->list, long long int);
	if (nbr < 0)
	{
		nbr *= -1;
		t_st->pr_min = 1;
	}
	return (ft_itoa_base(t_st, nbr, base, 0));
}

int		print_uint(t_pf_st *t_st, int base, int up)
{
	unsigned long long int nbr;

	if (t_st->sm == SM_SHORT2)
		nbr = (unsigned char)va_arg(t_st->list, unsigned long long int);
	else if (t_st->sm == SM_SHORT)
		nbr = (unsigned short)va_arg(t_st->list, unsigned long long int);
	else if (t_st->sm == SM_LONG)
		nbr = (unsigned long)va_arg(t_st->list, unsigned long long int);
	else if (t_st->sm == SM_LONG2)
		nbr = va_arg(t_st->list, unsigned long long int);
	else if (t_st->sm == SM_MINT)
		nbr = (uintmax_t)va_arg(t_st->list, unsigned long long int);
	else if (t_st->sm == SM_SIZE_T)
		nbr = (size_t)va_arg(t_st->list, unsigned long long int);
	else
		nbr = (unsigned int)va_arg(t_st->list, unsigned long long int);
	return (ft_itoa_base(t_st, nbr, base, up));
}

int		print_lint(t_pf_st *t_st, int base)
{
	long long int	nbr;

	nbr = va_arg(t_st->list, long long int);
	if (nbr < 0 && t_st->c != 'U')
	{
		nbr *= -1;
		t_st->pr_min = 1;
	}
	return (ft_itoa_base(t_st, nbr, base, 0));
}

int		print_ptr(t_pf_st *t_st)
{
	void *ptr;

	ptr = va_arg(t_st->list, void *);
	t_st->is_hash = 1;
	return (ft_itoa_base(t_st, (unsigned long)ptr, 16, 0));
}

int		print_chr(t_pf_st *t_st, char a)
{
	char	c;
	int		ret;

	if (t_st->sm == SM_LONG)
		return (print_wchr(va_arg(t_st->list, wint_t)));
	ret = 0;
	ret += num_padding(t_st, 0, 1, 1);
	if (!a)
		c = (char)va_arg(t_st->list, int);
	else
		c = a;
	ret += print_char(c);
	ret += num_padding(t_st, 1, 1, 1);
	return (ret);
}
