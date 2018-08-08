/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:02:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 10:02:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wolf_inc.h"

void		draw_enemy_util(t_sdl *sdl, t_enemy *enemy, int x)
{
	sdl->render.sprite_x = enemy->pos_x - sdl->map.player.pos_x;
	sdl->render.sprite_y = enemy->pos_y - sdl->map.player.pos_y;
	sdl->render.inv_det = 1.0 / (sdl->map.plane_x * sdl->map.player.dir_y -
	sdl->map.player.dir_x * sdl->map.plane_y);
	sdl->render.tr_x = sdl->render.inv_det * (sdl->map.player.dir_y *
	sdl->render.sprite_x - sdl->map.player.dir_x * sdl->render.sprite_y);
	sdl->render.tr_y = sdl->render.inv_det * (-sdl->map.plane_y *
	sdl->render.sprite_x + sdl->map.plane_x * sdl->render.sprite_y);
	sdl->render.sprite_height = abs((int)(SCREEN_HEIGHT / sdl->render.tr_y));
	sdl->render.draw_start_y = -sdl->render.sprite_height / 2 *
	SCREEN_HEIGHT / 2;
	sdl->render.draw_start_x = sdl->render.sprite_height / 2 +
	SCREEN_HEIGHT / 2;
	sdl->render.draw_start_x = sdl->render.draw_start_x >= SCREEN_HEIGHT ?
	SCREEN_HEIGHT - 1 : sdl->render.draw_start_x;
	sdl->render.draw_start_y = sdl->render.draw_start_y < 0 ? 0 :
	sdl->render.draw_start_y;
	if (x >= SCREEN_WIDTH / 2 - 5 && x <= SCREEN_WIDTH / 2 + 5 && sdl->render.t
		&& enemy->health > 0 && sdl->gui.fire && sdl->gui.gun_type != G_NOTHING)
	{
		Mix_PlayChannel(-1, enemy->s_sound, 0);
		enemy->health -= sdl->gui.fire_damage;
		sdl->render.t = 0;
	}
}

void		draw_enemy(t_sdl *sdl, t_enemy *enemy, int x)
{
	SDL_Surface *en;

	draw_enemy_util(sdl, enemy, x);
	en = SDL_CreateRGBSurface(0, 65, 65, 32, 0, 0, 0, 0);
	if (enemy->health <= 0)
		SDL_BlitSurface(enemy->texture, enemy->death_anim, en,
						&(SDL_Rect){0, 0, 65, 65});
	else if (enemy->walking && !enemy->fire)
		SDL_BlitSurface(enemy->texture,
						&enemy->walk_anim[(SDL_GetTicks() / 100) % 4], en,
						&(SDL_Rect){0, 0, 65, 65});
	else if (enemy->fire)
		SDL_BlitSurface(enemy->texture,
						&enemy->fire_anim[(SDL_GetTicks() / 100) % 4], en,
						&(SDL_Rect) {0, 0, 65, 65});
	else
		SDL_BlitSurface(enemy->texture, enemy->stand_anim, en,
						&(SDL_Rect){0, 0, 65, 65});
	draw_sprite(sdl, en, x);
	SDL_FreeSurface(en);
}

void		draw_ceiling_floor_utils(t_sdl *sdl)
{
	if (sdl->render.draw_end < 0)
		sdl->render.draw_end = SCREEN_HEIGHT;
	while (sdl->render.draw_end <= SCREEN_HEIGHT)
	{
		sdl->render.current_dist = SCREEN_HEIGHT / (2.0 * sdl->render.draw_end
		- SCREEN_HEIGHT);
		sdl->render.weight = (sdl->render.current_dist -
		sdl->render.dist_player) / (sdl->render.dist_wall -
		sdl->render.dist_player);
		sdl->render.current_floor_x = sdl->render.weight *
		sdl->render.floor_x_wall + (1.0 - sdl->render.weight) *
		sdl->map.player.pos_x;
		sdl->render.current_floor_y = sdl->render.weight *
		sdl->render.floor_y_wall + (1.0 - sdl->render.weight) *
		sdl->map.player.pos_y;
		sdl->render.floor_tex_x = (int)(sdl->render.current_floor_x * 64) % 64;
		sdl->render.floor_tex_y = (int)(sdl->render.current_floor_y * 64) % 64;
		put_pixel(sdl, sdl->map.floor, sdl->map.ceiling, (int[]){sdl->render.j,
		sdl->render.draw_end, 64, sdl->render.floor_tex_y,
		sdl->render.floor_tex_x});
		sdl->render.draw_end++;
	}
}

void		draw_ceiling_floor(t_sdl *sdl)
{
	if (sdl->render.side == 0 && sdl->render.ray_dir_x > 0)
	{
		sdl->render.floor_x_wall = sdl->render.map_x;
		sdl->render.floor_y_wall = sdl->render.map_y + sdl->render.wall_x;
	}
	else if (sdl->render.side == 0 && sdl->render.ray_dir_x < 0)
	{
		sdl->render.floor_x_wall = sdl->render.map_x + 1.0;
		sdl->render.floor_y_wall = sdl->render.map_y + sdl->render.wall_x;
	}
	else if (sdl->render.side == 1 && sdl->render.ray_dir_y > 0)
	{
		sdl->render.floor_x_wall = sdl->render.map_x + sdl->render.wall_x;
		sdl->render.floor_y_wall = sdl->render.map_y;
	}
	else
	{
		sdl->render.floor_x_wall = sdl->render.map_x + sdl->render.wall_x;
		sdl->render.floor_y_wall = sdl->render.map_y + 1.0;
	}
	sdl->render.dist_wall = sdl->render.perp_wall_dist;
	sdl->render.dist_player = 0.0;
	draw_ceiling_floor_utils(sdl);
}

SDL_Surface	*choose_wall(t_sdl *sdl)
{
	if (sdl->render.side && sdl->render.ray_dir_y > 0)
		return (sdl->textures.bluestone);
	else if (sdl->render.side && sdl->render.ray_dir_y < 0)
		return (sdl->textures.greystone);
	else if (!sdl->render.side && sdl->render.ray_dir_x < 0)
		return (sdl->textures.mossy_w);
	else
		return (sdl->textures.redbrick);
}
