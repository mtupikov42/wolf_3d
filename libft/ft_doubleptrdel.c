/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubleptrdel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 05:03:10 by mtupikov          #+#    #+#             */
/*   Updated: 2018/04/03 08:26:29 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_doubleptrdel(void ***ptr)
{
	void	**p;
	int		i;

	i = 0;
	p = *ptr;
	while (*p)
	{
		ft_memdel(p);
		i++;
		p = &(*ptr)[i];
	}
	ft_memdel(*ptr);
}
