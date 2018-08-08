/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:47:17 by mtupikov          #+#    #+#             */
/*   Updated: 2018/03/25 21:26:52 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		get_num_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void		add_num_to_s(char *s, int len, int num)
{
	if (len < 0)
		return ;
	s[len] = num % 10 + '0';
	add_num_to_s(s, --len, num / 10);
}

static void		check(int *a, int *b)
{
	if (*a == -1)
		*b += 1;
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		por;
	int		len;
	int		cop;

	cop = n;
	por = 1;
	if (n < 0)
	{
		if (n == -2147483648)
			n += 1;
		por = -1;
		n *= por;
	}
	len = get_num_len(n);
	check(&por, &len);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	add_num_to_s(ret, --len, n);
	if (por == -1)
		ret[0] = '-';
	if (cop == -2147483648)
		ret[len] = '8';
	ret[++len] = '\0';
	return (ret);
}
