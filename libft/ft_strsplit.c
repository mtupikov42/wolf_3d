/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:19:58 by mtupikov          #+#    #+#             */
/*   Updated: 2018/03/25 21:28:21 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		get_word_len(char const *s, char c, int w)
{
	int count;
	int len;

	len = 0;
	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			if (count == w)
				len++;
			else if (count > w)
				break ;
			s++;
			if (*s == c)
				count++;
		}
	}
	return (len);
}

static char		*get_word(char const *s, char c, int w)
{
	int		count;
	char	*ret;
	int		i;

	i = -1;
	ret = (char *)malloc(sizeof(char) * (get_word_len(s, c, w) + 1));
	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			if (count == w)
				ret[++i] = *s;
			else if (count > w)
				break ;
			s++;
			if (*s == c || ft_strlen(s) == 0)
				count++;
		}
	}
	ret[++i] = '\0';
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(ret = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1))))
		return (NULL);
	while (i < ft_count_words(s, c))
	{
		ret[i] = get_word(s, c, i);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
