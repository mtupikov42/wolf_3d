/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:23:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 10:23:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_inc.h"

void	enemy_ai_util1(t_sdl *sdl, int i)
{
	int j;

	sdl->map.enemies[i].walking = 1;
	j = sdl->map.map[(int)sdl->map.enemies[i].pos_y]
	[(int)(sdl->map.enemies[i].pos_x - 0.3)].type;
	if ((int)sdl->map.enemies[i].dx <= 0 && j != WALL && j != WALL4)
		sdl->map.enemies[i].pos_x -= 0.1;
	j = sdl->map.map[(int)(sdl->map.enemies[i].pos_y - 0.3)]
	[(int)sdl->map.enemies[i].pos_x].type;
	if ((int)sdl->map.enemies[i].dy <= 0 && j != WALL && j != WALL4)
		sdl->map.enemies[i].pos_y -= 0.1;
	j = sdl->map.map[(int)sdl->map.enemies[i].pos_y]
	[(int)(sdl->map.enemies[i].pos_x + 0.3)].type;
	if ((int)sdl->map.enemies[i].dx >= 0 && j != WALL && j != WALL4)
		sdl->map.enemies[i].pos_x += 0.1;
	j = sdl->map.map[(int)(sdl->map.enemies[i].pos_y + 0.3)]
	[(int)sdl->map.enemies[i].pos_x].type;
	if ((int)sdl->map.enemies[i].dy >= 0 && j != WALL && j != WALL4)
		sdl->map.enemies[i].pos_y += 0.1;
}

void	enemy_ai_util2(t_sdl *sdl, int i)
{
	sdl->map.enemies[i].dx = sdl->map.player.pos_x - sdl->map.enemies[i].pos_x;
	sdl->map.enemies[i].dy = sdl->map.player.pos_y - sdl->map.enemies[i].pos_y;
	sdl->map.enemies[i].dist = sqrt(sdl->map.enemies[i].dx *
	sdl->map.enemies[i].dx + sdl->map.enemies[i].dy * sdl->map.enemies[i].dy);
	if (sdl->map.enemies[i].dist > sdl->map.enemies[i].dist_radius &&
		sdl->map.enemies[i].dist < 15 && !sdl->map.enemies[i].fire)
		enemy_ai_util1(sdl, i);
	else
		sdl->map.enemies[i].walking = 0;
	if (sdl->map.enemies[i].fire)
	{
		Mix_PlayChannel(-1, sdl->map.enemies[i].fire_sound, 0);
		sdl->map.enemies[i].fire = 0;
		sdl->map.player.health -= sdl->map.enemies[i].damage;
	}
	if (sdl->map.enemies[i].dist <= sdl->map.enemies[i].dist_radius
		&& (SDL_GetTicks() / 100) % 20 == 0)
		sdl->map.enemies[i].fire = 1;
}

void	enemy_ai(t_sdl *sdl)
{
	int i;

	i = -1;
	while (++i < sdl->map.enemy_count)
	{
		if (sdl->map.enemies[i].health > 0)
			enemy_ai_util2(sdl, i);
		else if (sdl->map.enemies[i].status != DEAD)
		{
			Mix_PlayChannel(-1, sdl->map.enemies[i].death_sound, 0);
			sdl->map.enemies[i].status = DEAD;
		}
	}
}

int		check_enemy_minimap(t_sdl *sdl, int x, int y)
{
	int i;

	i = -1;
	while (++i < sdl->map.enemy_count)
		if (x == (int)sdl->map.enemies[i].pos_x &&
			y == (int)sdl->map.enemies[i].pos_y &&
			sdl->map.enemies[i].status == ALIVE)
			return (TRUE);
	return (FALSE);
}

void	check_cell(t_sdl *sdl, t_map_cell *cell)
{
	if (cell->type == SPRITE && cell->sprite.type == T_PICKABLE &&
		cell->sprite.sp_type == S_MEDPACK && sdl->map.player.health < 100.0
		&& !cell->sprite.picked)
	{
		Mix_PlayChannel(-1, sdl->media.pickup, 0);
		cell->sprite.picked = 1;
		sdl->map.player.health += 15;
		if (sdl->map.player.health > 100.0)
			sdl->map.player.health = 100.0;
	}
	else if (cell->type == SPRITE && cell->sprite.type == T_PICKABLE &&
			cell->sprite.sp_type == S_AMMO && !cell->sprite.picked &&
			sdl->gui.gun_type != G_NOTHING)
	{
		Mix_PlayChannel(-1, sdl->media.pickup, 0);
		cell->sprite.picked = 1;
		*sdl->gui.ammo += 20;
	}
	else if (cell->type == SPRITE && cell->sprite.type == T_PICKABLE &&
			cell->sprite.sp_type == S_PICK && !cell->sprite.picked)
	{
		Mix_PlayChannel(-1, sdl->media.pickup, 0);
		cell->sprite.picked = 1;
	}
}
