/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 21:10:38 by mtupikov          #+#    #+#             */
/*   Updated: 2018/04/03 03:04:27 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		get_line(char **line, char *buffer)
{
	char	*tmp;
	int		len;

	if ((tmp = ft_strchr(buffer, EOL)))
	{
		*line = ft_strrealloc(*line, tmp - buffer);
		ft_strncat(*line, buffer, tmp - buffer);
		ft_memmove(buffer, tmp + 1, ft_strlen(tmp));
		return (1);
	}
	if ((len = ft_strlen(buffer)))
	{
		*line = ft_strrealloc(*line, len);
		ft_strncat(*line, buffer, len);
		*buffer = '\0';
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char *buffer[8192];
	int			rd;

	if (fd < 0 || fd > 8192 || read(fd, buffer[fd], 0) < 0 || !line ||
		(!buffer[fd] && !(buffer[fd] = ft_strnew(BUFF_SIZE))))
		return (-1);
	*line = NULL;
	if (get_line(line, buffer[fd]))
		return (1);
	while ((rd = read(fd, buffer[fd], BUFF_SIZE)) > 0)
	{
		buffer[fd][rd] = '\0';
		if (get_line(line, buffer[fd]))
			return (1);
	}
	if (*line)
		return (1);
	ft_strdel(&buffer[fd]);
	if (rd < 0)
		return (-1);
	return (0);
}
