/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:21:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/19 15:21:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static double	frac_part(char *num, int *div)
{
	double frac;

	frac = 0;
	num++;
	while (*num)
	{
		if (ft_isdigit(*num))
		{
			*div *= 10;
			frac = frac * 10 + (*num - 48);
		}
		else
			return (frac);
		num++;
	}
	return (frac);
}

double			ft_atof(char *num)
{
	double	integer_part;
	int		div;
	int		sign;

	integer_part = 0;
	div = 1;
	sign = 1;
	if (!num || !*num)
		return (0);
	if (*num == '-')
	{
		++num;
		sign = -1;
	}
	while (*num && *num != '.')
	{
		if (ft_isdigit(*num))
			integer_part = integer_part * 10 + (*num - 48);
		else
			return (sign * integer_part);
		num++;
	}
	return (sign * (integer_part + frac_part(num, &div) / div));
}
