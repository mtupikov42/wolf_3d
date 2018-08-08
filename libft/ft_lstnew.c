/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 17:59:12 by mtupikov          #+#    #+#             */
/*   Updated: 2018/03/25 18:09:29 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ret;

	if (!(ret = (t_list *)malloc(sizeof(*ret))))
		return (NULL);
	if (content == NULL)
		content_size = 0;
	else if (!(ret->content = malloc(content_size)))
		return (NULL);
	ft_memcpy(ret->content, content, content_size);
	ret->content_size = content_size;
	ret->next = NULL;
	return (ret);
}
