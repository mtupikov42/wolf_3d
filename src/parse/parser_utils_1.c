/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 09:55:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 09:55:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wolf_inc.h"

void	parse_map_textures_util_1(t_sdl *sdl, int i, int j, const char *line)
{
	if (sdl->map.map[i][j].type == WALL && line[j] == 'G')
		sdl->map.map[i][j].texture = sdl->textures.greystone;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'W')
		sdl->map.map[i][j].texture = sdl->textures.wood;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'B')
		sdl->map.map[i][j].texture = sdl->textures.bluestone;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'P')
		sdl->map.map[i][j].texture = sdl->textures.purplestone;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'R')
		sdl->map.map[i][j].texture = sdl->textures.redbrick;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'E')
		sdl->map.map[i][j].texture = sdl->textures.eagle_w;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'M')
		sdl->map.map[i][j].texture = sdl->textures.mossy_w;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'C')
		sdl->map.map[i][j].texture = sdl->textures.colorstone;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'L')
		sdl->map.map[i][j].texture = sdl->textures.bush_wall;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'Z')
		sdl->map.map[i][j].texture = sdl->textures.hitler_wood;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'X')
		sdl->map.map[i][j].texture = sdl->textures.prison_bluestone;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'V')
		sdl->map.map[i][j].texture = sdl->textures.prison_f_bluestone;
}

void	parse_map_textures_util_2(t_sdl *sdl, int i, int j, const char *line)
{
	if (sdl->map.map[i][j].type == WALL && line[j] == 'N')
		sdl->map.map[i][j].texture = sdl->textures.nazi_redbrick;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'K')
		sdl->map.map[i][j].texture = sdl->textures.gitler_greystone;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'J')
		sdl->map.map[i][j].texture = sdl->textures.nazi_greystone;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'H')
		sdl->map.map[i][j].texture = sdl->textures.brick_wall;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'F')
		sdl->map.map[i][j].texture = sdl->textures.metal_wall_1;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'D')
		sdl->map.map[i][j].texture = sdl->textures.metal_wall_2;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'A')
		sdl->map.map[i][j].texture = sdl->textures.metal_wall_stripe;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'T')
		sdl->map.map[i][j].texture = sdl->textures.pipe_wall;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'O')
		sdl->map.map[i][j].texture = sdl->textures.computer;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'Y')
		sdl->map.map[i][j].texture = sdl->textures.metal_wall_3;
	else if (sdl->map.map[i][j].type == WALL && line[j] == 'U')
		sdl->map.map[i][j].texture = sdl->textures.unit_wall;
	else if (sdl->map.map[i][j].type == WALL && line[j] == '4')
		sdl->map.map[i][j].type = WALL4;
}

void	parse_map_textures_util_3(t_sdl *sdl, int i, int j, const char *line)
{
	if (sdl->map.map[i][j].type == SPRITE && line[j] == 'b')
	{
		sdl->map.map[i][j].texture = sdl->textures.barrel;
		sdl->map.map[i][j].sprite.x = j;
		sdl->map.map[i][j].sprite.y = i;
		sdl->map.map[i][j].sprite.type = T_INTER;
	}
	else if (sdl->map.map[i][j].type == SPRITE && line[j] == 'l')
	{
		sdl->map.map[i][j].texture = sdl->textures.glight;
		sdl->map.map[i][j].sprite.x = j;
		sdl->map.map[i][j].sprite.y = i;
		sdl->map.map[i][j].sprite.type = T_NOINTER;
	}
	else if (sdl->map.map[i][j].type == SPRITE)
	{
		sdl->map.map[i][j].texture = sdl->textures.glight;
		sdl->map.map[i][j].sprite.x = j;
		sdl->map.map[i][j].sprite.y = i;
		sdl->map.map[i][j].sprite.type = T_NOINTER;
	}
}

void	parse_map_textures_util_4(t_sdl *sdl, int i, int j, const char *line)
{
	if (sdl->map.map[i][j].type == SPRITE && line[j] == 'm')
	{
		sdl->map.map[i][j].texture = sdl->textures.medpack;
		sdl->map.map[i][j].sprite.x = j;
		sdl->map.map[i][j].sprite.y = i;
		sdl->map.map[i][j].sprite.type = T_PICKABLE;
		sdl->map.map[i][j].sprite.picked = FALSE;
		sdl->map.map[i][j].sprite.sp_type = S_MEDPACK;
	}
	else if (sdl->map.map[i][j].type == SPRITE && line[j] == 'a')
	{
		sdl->map.map[i][j].texture = sdl->textures.ammo;
		sdl->map.map[i][j].sprite.x = j;
		sdl->map.map[i][j].sprite.y = i;
		sdl->map.map[i][j].sprite.type = T_PICKABLE;
		sdl->map.map[i][j].sprite.picked = FALSE;
		sdl->map.map[i][j].sprite.sp_type = S_AMMO;
	}
	else if (sdl->map.map[i][j].type == SPRITE && line[j] == 't')
	{
		sdl->map.map[i][j].texture = sdl->textures.toilet;
		sdl->map.map[i][j].sprite.x = j;
		sdl->map.map[i][j].sprite.y = i;
		sdl->map.map[i][j].sprite.type = T_INTER;
	}
}

void	parse_map_textures_util_5(t_sdl *sdl, int i, int j, const char *line)
{
	if (sdl->map.map[i][j].type == SPRITE && line[j] == 'n')
	{
		sdl->map.map[i][j].texture = sdl->textures.table;
		sdl->map.map[i][j].sprite.x = j;
		sdl->map.map[i][j].sprite.y = i;
		sdl->map.map[i][j].sprite.type = T_INTER;
	}
	else if (sdl->map.map[i][j].type == SPRITE && line[j] == 'c')
	{
		sdl->map.map[i][j].texture = sdl->textures.chair;
		sdl->map.map[i][j].sprite.x = j;
		sdl->map.map[i][j].sprite.y = i;
		sdl->map.map[i][j].sprite.type = T_INTER;
	}
	else if (sdl->map.map[i][j].type == SPRITE && line[j] == 'd')
	{
		sdl->map.map[i][j].texture = sdl->textures.doom_barrel;
		sdl->map.map[i][j].sprite.x = j;
		sdl->map.map[i][j].sprite.y = i;
		sdl->map.map[i][j].sprite.type = T_INTER;
	}
}
