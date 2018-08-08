/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 09:56:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 09:56:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wolf_inc.h"

int		check_player(t_map *map)
{
	if ((int)map->player.pos_y < 1 ||
		(int)map->player.pos_y >= map->map_height ||
		(int)map->player.pos_x == map->map[(int)map->player.pos_y][0].len - 1 ||
		(int)map->player.pos_x > map->map[(int)map->player.pos_y - 1][0].len ||
		(int)map->player.pos_x > map->map[(int)map->player.pos_y + 1][0].len)
		return (0);
	return (1);
}
