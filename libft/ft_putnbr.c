/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 17:28:16 by mtupikov          #+#    #+#             */
/*   Updated: 2018/03/25 21:27:07 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	print_num(int num)
{
	if (num == 0)
		return ;
	print_num(num / 10);
	ft_putchar(num % 10 + '0');
}

void		ft_putnbr(int n)
{
	int por;
	int cop;

	cop = n;
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	por = 1;
	if (n < 0)
	{
		if (n == -2147483648)
			n /= 10;
		por = -1;
		n *= por;
	}
	if (por == -1)
		ft_putchar('-');
	print_num(n);
	if (cop == -2147483648)
		ft_putchar('8');
}
