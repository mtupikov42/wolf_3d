/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 16:54:13 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/13 16:54:53 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/ft_printf.h"

int		ft_strsplit_count(char **split)
{
	int len;
	int i;

	if (!split)
		return (0);
	len = 0;
	i = -1;
	while (split[++i])
		len++;
	return (len);
}

int		ft_split_has_dupl(char **split)
{
	int i;
	int j;

	i = -1;
	while (split[++i])
	{
		j = -1;
		while (split[++j])
			if (i != j)
			{
				if (!ft_strcmp(split[i], split[j]))
					return (1);
			}
	}
	return (0);
}

char	**ft_splitrealloc(char **old, int size)
{
	char	**new;
	int		i;

	new = ft_memalloc(sizeof(char *) * size);
	if (!old)
	{
		new[size] = NULL;
		return (new);
	}
	i = -1;
	while (++i < size - 1)
	{
		new[i] = ft_strrealloc(new[i], ft_strlen(old[i]));
		ft_strcpy(new[i], old[i]);
	}
	new[size - 1] = NULL;
	new[size] = NULL;
	ft_splitdel(&old);
	return (new);
}

void	print_split(char **split)
{
	int i;

	i = -1;
	while (split[++i])
		ft_printf("%s\n", split[i]);
}
