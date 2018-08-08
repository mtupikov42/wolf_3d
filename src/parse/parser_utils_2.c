/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 09:56:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 09:56:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wolf_inc.h"

#define P_ENEMY sdl->map.enemies[sdl->map.enemy_count]

void	parse_map_textures_util_6(t_sdl *sdl, int i, int j, const char *line)
{
	if (sdl->map.map[i][j].type == SPRITE && line[j] == 'z')
	{
		sdl->map.map[i][j].texture = sdl->textures.doom_box;
		sdl->map.map[i][j].sprite.x = j;
		sdl->map.map[i][j].sprite.y = i;
		sdl->map.map[i][j].sprite.type = T_INTER;
	}
	else if (sdl->map.map[i][j].type == SPRITE && line[j] == 'r')
	{
		sdl->map.map[i][j].texture = sdl->textures.doom_wtf;
		sdl->map.map[i][j].sprite.x = j;
		sdl->map.map[i][j].sprite.y = i;
		sdl->map.map[i][j].sprite.type = T_INTER;
	}
	else if (sdl->map.map[i][j].type == SPRITE && line[j] == 'f')
	{
		sdl->map.map[i][j].texture = sdl->textures.floor_light;
		sdl->map.map[i][j].sprite.x = j;
		sdl->map.map[i][j].sprite.y = i;
		sdl->map.map[i][j].sprite.type = T_INTER;
	}
}

void	parse_map_textures_util_7(t_sdl *sdl, int i, int j, const char *line)
{
	if (sdl->map.map[i][j].type == SPRITE && line[j] == 'y')
	{
		sdl->map.map[i][j].texture = sdl->textures.portal;
		sdl->map.map[i][j].sprite.x = j;
		sdl->map.map[i][j].sprite.y = i;
		sdl->map.map[i][j].sprite.type = T_INTER;
	}
	else if (sdl->map.map[i][j].type == SPRITE && line[j] == 'q')
	{
		sdl->map.map[i][j].texture = sdl->textures.tizh;
		sdl->map.map[i][j].sprite.x = j;
		sdl->map.map[i][j].sprite.y = i;
		sdl->map.map[i][j].sprite.type = T_PICKABLE;
		sdl->map.map[i][j].sprite.picked = FALSE;
		sdl->map.map[i][j].sprite.sp_type = S_PICK;
	}
	else if (sdl->map.map[i][j].type == SPRITE && line[j] == 'p')
	{
		sdl->map.map[i][j].texture = sdl->textures.pillar;
		sdl->map.map[i][j].sprite.x = j;
		sdl->map.map[i][j].sprite.y = i;
		sdl->map.map[i][j].sprite.type = T_INTER;
	}
}

void	parse_map_textures_util_8(t_sdl *sdl, int i, int j, const char *line)
{
	if (sdl->map.map[i][j].type == ENEMY && line[j] == 'w'
		&& sdl->map.enemy_count < 100)
	{
		P_ENEMY.texture = sdl->textures.wolf_sold;
		P_ENEMY.pos_x = j + 0.5;
		P_ENEMY.pos_y = i + 0.5;
		P_ENEMY.walking = 0;
		P_ENEMY.fire = 0;
		P_ENEMY.damage = 5.0;
		P_ENEMY.health = 100;
		P_ENEMY.status = ALIVE;
		P_ENEMY.fire_sound = sdl->media.wolf_s_fire;
		P_ENEMY.s_sound = sdl->media.wolf_p_in_s;
		P_ENEMY.death_sound = sdl->media.wolf_s_death;
		P_ENEMY.walk_anim = sdl->textures.wolf_s_go;
		P_ENEMY.fire_anim = sdl->textures.wolf_s_fire;
		P_ENEMY.stand_anim = &sdl->textures.wolf_s_s;
		P_ENEMY.death_anim = &sdl->textures.wolf_s_dead;
		P_ENEMY.dist_radius = 4;
		sdl->map.map[i][j].type = NOTHING;
		sdl->map.enemy_count++;
	}
}

void	parse_map_textures_util_9(t_sdl *sdl, int i, int j, const char *line)
{
	if (sdl->map.map[i][j].type == ENEMY && line[j] == 'g'
		&& sdl->map.enemy_count < 100)
	{
		P_ENEMY.texture = sdl->textures.doom_g;
		P_ENEMY.pos_x = j + 0.5;
		P_ENEMY.pos_y = i + 0.5;
		P_ENEMY.walking = 0;
		P_ENEMY.fire = 0;
		P_ENEMY.damage = 10.0;
		P_ENEMY.health = 100;
		P_ENEMY.status = ALIVE;
		P_ENEMY.fire_sound = sdl->media.doom_g_fire;
		P_ENEMY.s_sound = sdl->media.doom_p_in_s;
		P_ENEMY.death_sound = sdl->media.doom_g_death;
		P_ENEMY.walk_anim = sdl->textures.doom_g_go;
		P_ENEMY.fire_anim = sdl->textures.doom_g_fire;
		P_ENEMY.stand_anim = &sdl->textures.doom_g_s;
		P_ENEMY.death_anim = &sdl->textures.doom_g_dead;
		P_ENEMY.dist_radius = 2;
		sdl->map.map[i][j].type = NOTHING;
		sdl->map.enemy_count++;
	}
}

void	parse_map_textures_util_10(t_sdl *sdl, int i, int j, const char *line)
{
	if (sdl->map.map[i][j].type == ENEMY && line[j] == '*'
		&& sdl->map.enemy_count < 100)
	{
		P_ENEMY.texture = sdl->textures.unit_g;
		P_ENEMY.pos_x = j + 0.5;
		P_ENEMY.pos_y = i + 0.5;
		P_ENEMY.walking = 0;
		P_ENEMY.fire = 0;
		P_ENEMY.damage = 0.0;
		P_ENEMY.health = 100;
		P_ENEMY.status = ALIVE;
		P_ENEMY.fire_sound = sdl->media.doom_g_fire;
		P_ENEMY.s_sound = sdl->media.doom_p_in_s;
		P_ENEMY.death_sound = sdl->media.doom_g_death;
		P_ENEMY.walk_anim = sdl->textures.unit_g_go;
		P_ENEMY.fire_anim = sdl->textures.unit_g_fire;
		P_ENEMY.stand_anim = &sdl->textures.unit_g_s;
		P_ENEMY.death_anim = &sdl->textures.unit_g_dead;
		P_ENEMY.dist_radius = 2;
		sdl->map.map[i][j].type = NOTHING;
		sdl->map.enemy_count++;
	}
}
