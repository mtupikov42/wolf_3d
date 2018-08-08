/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:26:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 10:26:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_inc.h"

void	choose_gun_util(t_sdl *sdl, int n)
{
	if (n == SDLK_2)
	{
		sdl->gui.gun_type = G_RIFLE;
		sdl->gui.fire_anim = sdl->textures.rifle_fire;
		sdl->gui.walk_anim = &sdl->textures.rifle_go;
		sdl->gui.texture = sdl->textures.rifle;
		sdl->gui.fire_damage = 10.0;
		sdl->gui.fire_sound = sdl->media.rifle_fire;
		sdl->gui.ammo = &sdl->gui.rifle_ammo;
		sdl->gui.x_draw = 630;
		sdl->gui.y_draw = 500;
		sdl->gui.x_draw_m = 500;
		sdl->gui.y_draw_m = 700;
	}
	else
		sdl->gui.gun_type = G_NOTHING;
}

void	choose_gun(t_sdl *sdl, int n)
{
	if (n == SDLK_1)
	{
		sdl->gui.gun_type = G_PISTOL;
		sdl->gui.fire_anim = sdl->textures.pistol_fire;
		sdl->gui.walk_anim = &sdl->textures.pistol_go;
		sdl->gui.texture = sdl->textures.pistol;
		sdl->gui.fire_damage = 5.0;
		sdl->gui.fire_sound = sdl->media.pistol_fire;
		sdl->gui.ammo = &sdl->gui.pistol_ammo;
		sdl->gui.x_draw = 730;
		sdl->gui.y_draw = 600;
		sdl->gui.x_draw_m = 400;
		sdl->gui.y_draw_m = 500;
	}
	else
		choose_gun_util(sdl, n);
}

void	main_loop_events_util_1(t_sdl *sdl)
{
	t_map_cell *cell;

	if (sdl->keys[SDLK_w] && sdl->event.type != SDL_MOUSEMOTION)
	{
		cell = &sdl->map.map[(int)(sdl->map.player.pos_y +
		sdl->map.player.dir_y * sdl->render.move_speed)]
		[(int)sdl->map.player.pos_x];
		check_cell(sdl, cell);
		if (cell->type != WALL && cell->type != WALL4 &&
			(cell->type != SPRITE || cell->sprite.type == T_NOINTER ||
			cell->sprite.type == T_PICKABLE))
			sdl->map.player.pos_y += sdl->map.player.dir_y *
									sdl->render.move_speed;
		cell = &sdl->map.map[(int)sdl->map.player.pos_y]
		[(int)(sdl->map.player.pos_x + sdl->map.player.dir_x *
		sdl->render.move_speed)];
		check_cell(sdl, cell);
		if (cell->type != WALL && cell->type != WALL4 &&
			(cell->type != SPRITE || cell->sprite.type == T_NOINTER ||
			cell->sprite.type == T_PICKABLE))
			sdl->map.player.pos_x += sdl->map.player.dir_x *
									sdl->render.move_speed;
		sdl->gui.gr_r = (SDL_GetTicks() / 100) % 10;
	}
}

void	main_loop_events_util_2(t_sdl *sdl)
{
	t_map_cell *cell;

	if (sdl->keys[SDLK_s] && sdl->event.type != SDL_MOUSEMOTION)
	{
		cell = &sdl->map.map[(int)(sdl->map.player.pos_y -
		sdl->map.player.dir_y * sdl->render.move_speed)]
		[(int)sdl->map.player.pos_x];
		check_cell(sdl, cell);
		if (cell->type != WALL && cell->type != WALL4 &&
			(cell->type != SPRITE || cell->sprite.type == T_NOINTER ||
			cell->sprite.type == T_PICKABLE))
			sdl->map.player.pos_y -= sdl->map.player.dir_y *
									sdl->render.move_speed;
		cell = &sdl->map.map[(int)sdl->map.player.pos_y]
		[(int)(sdl->map.player.pos_x - sdl->map.player.dir_x *
		sdl->render.move_speed)];
		check_cell(sdl, cell);
		if (cell->type != WALL && cell->type != WALL4 &&
			(cell->type != SPRITE || cell->sprite.type == T_NOINTER ||
			cell->sprite.type == T_PICKABLE))
			sdl->map.player.pos_x -= sdl->map.player.dir_x *
									sdl->render.move_speed;
		sdl->gui.gr_r = (SDL_GetTicks() / 100) % 10;
	}
}

void	main_loop_events_util_3_1(t_sdl *sdl)
{
	if (sdl->keys[SDLK_a] && sdl->event.type != SDL_MOUSEMOTION)
	{
		sdl->render.old_dir_x = sdl->map.player.dir_x;
		sdl->map.player.dir_x = sdl->map.player.dir_x *
		cos(sdl->render.rot_speed) - sdl->map.player.dir_y *
		sin(sdl->render.rot_speed);
		sdl->map.player.dir_y = sdl->render.old_dir_x *
		sin(sdl->render.rot_speed) + sdl->map.player.dir_y *
		cos(sdl->render.rot_speed);
		sdl->render.old_plane_x = sdl->map.plane_x;
		sdl->map.plane_x = sdl->map.plane_x * cos(sdl->render.rot_speed)
		- sdl->map.plane_y * sin(sdl->render.rot_speed);
		sdl->map.plane_y = sdl->render.old_plane_x * sin(sdl->render.rot_speed)
		+ sdl->map.plane_y * cos(sdl->render.rot_speed);
	}
}
