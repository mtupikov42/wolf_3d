/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 08:30:52 by mtupikov          #+#    #+#             */
/*   Updated: 2018/03/25 20:14:39 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *str)
{
	char *ret;

	ret = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (ret == NULL)
		return (NULL);
	ft_strcpy(ret, str);
	return (ret);
}
