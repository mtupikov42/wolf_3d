/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 17:48:52 by mtupikov          #+#    #+#             */
/*   Updated: 2018/03/25 21:27:34 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	print_num(int num, int fd)
{
	if (num == 0)
		return ;
	print_num(num / 10, fd);
	ft_putchar_fd(num % 10 + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	int por;
	int cop;

	cop = n;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
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
		ft_putchar_fd('-', fd);
	print_num(n, fd);
	if (cop == -2147483648)
		ft_putchar_fd('8', fd);
}
