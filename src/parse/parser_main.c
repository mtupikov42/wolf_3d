/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:15:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/11 17:15:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wolf_inc.h"

void	parse_map_textures_utils(t_sdl *sdl, int i, int j, const char *line)
{
	if (sdl->map.map[i][j].type == WALL)
		sdl->map.map[i][j].texture = sdl->textures.bluestone;
	else
		sdl->map.map[i][j].texture = NULL;
	parse_map_textures_util_1(sdl, i, j, line);
	parse_map_textures_util_2(sdl, i, j, line);
	parse_map_textures_util_3(sdl, i, j, line);
	parse_map_textures_util_4(sdl, i, j, line);
	parse_map_textures_util_5(sdl, i, j, line);
	parse_map_textures_util_6(sdl, i, j, line);
	parse_map_textures_util_7(sdl, i, j, line);
	parse_map_textures_util_8(sdl, i, j, line);
	parse_map_textures_util_9(sdl, i, j, line);
	parse_map_textures_util_10(sdl, i, j, line);
}

void	parse_map_textures(t_sdl *sdl, char *name)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	if ((fd = open(name, O_RDONLY)) < 0)
		error("Texture map error.");
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		j = 0;
		while (sdl->map.map[i][j].end != TRUE)
		{
			parse_map_textures_utils(sdl, i, j, line);
			if (++j > sdl->map.map[i][0].len)
				error("Texture map error.");
		}
		ft_strdel(&line);
		if (++i >= sdl->map.map_height)
			break ;
	}
	if (i != sdl->map.map_height)
		error("Texture map error.");
}

void	parse_map_util_1(t_map *map, const int ij[2], int l_s, char *line)
{
	if (ft_strchr(WALL_SYMB, line[ij[1]]) || ij[1] == 0 ||
		ij[0] == 0 || ij[0] == map->map_height - 1)
		map->map[ij[0]][ij[1]].type = WALL;
	else if (line[ij[1]] == PLAYER_SYMB && map->map[ij[0] - 1][ij[1]].len > 0)
	{
		map->player.pos_x = ij[1] + 0.5;
		map->player.pos_y = ij[0] + 0.5;
		map->map[ij[0]][ij[1]].type = NOTHING;
	}
	else if (line[ij[1]] == SPRITE_SYMB)
		map->map[ij[0]][ij[1]].type = SPRITE;
	else if (line[ij[1]] == ENEMY_SYMB)
		map->map[ij[0]][ij[1]].type = ENEMY;
	else
		map->map[ij[0]][ij[1]].type = NOTHING;
	map->map[ij[0]][ij[1]].end = FALSE;
	map->map[ij[0]][ij[1]].len = l_s;
}

void	parse_map_util_2(t_map *map, const int i, char *line)
{
	int		l_s;
	int		j;
	int		k;

	if ((l_s = (int)ft_strlen(line)) == 0)
		error("Parse map error.");
	map->map[i] = (t_map_cell *)malloc(sizeof(t_map_cell) * (l_s + 1));
	j = -1;
	while (++j < l_s)
		parse_map_util_1(map, (int[]){i, j}, l_s, line);
	ft_strdel(&line);
	if (i > 0 && map->map[i][0].len > map->map[i - 1][0].len)
	{
		k = map->map[i - 1][0].len - 1;
		while (++k < map->map[i][0].len)
			map->map[i][k].type = WALL;
	}
	if (i > 0 && map->map[i][0].len < map->map[i - 1][0].len)
	{
		k = map->map[i][0].len - 1;
		while (++k < map->map[i - 1][0].len)
			map->map[i - 1][k].type = WALL;
	}
	map->map[i][j - 1].type = WALL;
	map->map[i][j].end = TRUE;
}

void	parse_map(t_map *map, char *name)
{
	int		fd;
	int		i;
	char	*line;

	if ((fd = open(name, O_RDONLY)) < 0)
		error("Parse map error.");
	map->map = NULL;
	get_next_line(fd, &line);
	if (!line || (map->map_height = (int)ft_atoi(line)) <= 0)
		error("Parse map error.");
	ft_strdel(&line);
	map->map = (t_map_cell **)malloc(sizeof(t_map_cell *) * map->map_height);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		parse_map_util_2(map, i, line);
		if (++i >= map->map_height)
			break ;
	}
	if (i != map->map_height || map->player.pos_x < 0 || !check_player(map))
		error("Parse map error.");
}
