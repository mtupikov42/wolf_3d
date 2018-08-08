/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:01:57 by mtupikov          #+#    #+#             */
/*   Updated: 2018/03/25 21:07:43 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	int		j;
	int		i;
	int		k;

	if (s)
	{
		i = 0;
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
			i++;
		j = ft_strlen(s) - 1;
		if (!(ret = (char *)malloc(sizeof(char) * (j - i + 1))))
			return (NULL);
		while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j >= 0)
			j--;
		k = -1;
		while (i <= j)
		{
			ret[++k] = s[i];
			i++;
		}
		ret[++k] = '\0';
		return (ret);
	}
	return (NULL);
}
