/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:28:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 10:28:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_inc.h"

void	main_loop_events_util_3(t_sdl *sdl)
{
	if (sdl->keys[SDLK_d] && sdl->event.type != SDL_MOUSEMOTION)
	{
		sdl->render.old_dir_x = sdl->map.player.dir_x;
		sdl->map.player.dir_x = sdl->map.player.dir_x *
		cos(-sdl->render.rot_speed) - sdl->map.player.dir_y *
		sin(-sdl->render.rot_speed);
		sdl->map.player.dir_y = sdl->render.old_dir_x *
		sin(-sdl->render.rot_speed) + sdl->map.player.dir_y *
		cos(-sdl->render.rot_speed);
		sdl->render.old_plane_x = sdl->map.plane_x;
		sdl->map.plane_x = sdl->map.plane_x * cos(-sdl->render.rot_speed) -
		sdl->map.plane_y * sin(-sdl->render.rot_speed);
		sdl->map.plane_y = sdl->render.old_plane_x *
		sin(-sdl->render.rot_speed) + sdl->map.plane_y *
		cos(-sdl->render.rot_speed);
	}
	main_loop_events_util_3_1(sdl);
}

void	main_loop_events_util_4(t_sdl *sdl)
{
	if (sdl->event.type == SDL_MOUSEBUTTONDOWN &&
		sdl->gui.gun_type != G_NOTHING && sdl->map.map_type == KILL_ALL
		&& *sdl->gui.ammo > 0)
	{
		Mix_PlayChannel(-1, sdl->gui.fire_sound, 0);
		sdl->gui.fire = 1;
		*sdl->gui.ammo -= 1;
	}
	if (sdl->event.type == SDL_KEYDOWN && sdl->event.key.keysym.sym == SDLK_m)
	{
		if (!sdl->gui.minimap)
			sdl->gui.minimap = 1;
		else
			sdl->gui.minimap = 0;
	}
	if (sdl->event.type == SDL_KEYDOWN && sdl->event.key.keysym.sym >= SDLK_0
		&& sdl->event.key.keysym.sym <= SDLK_9)
		choose_gun(sdl, sdl->event.key.keysym.sym);
}

void	draw_face(t_sdl *sdl, int j)
{
	int			k;
	SDL_Surface	*en;

	if ((SDL_GetTicks() % 22) == 0)
		k = 0;
	else if ((SDL_GetTicks() % 21) == 0)
		k = 2;
	else
		k = 1;
	en = SDL_CreateRGBSurface(0, 24, 32, 32, 0, 0, 0, 0);
	SDL_BlitSurface(sdl->gui.blaz_face,
					&(SDL_Rect) {24 * k + k, j * 32, 64, 64}, en,
					&(SDL_Rect) {0, 0, 64, 64});
	SDL_BlitScaled(en, NULL, sdl->screen, &(SDL_Rect) {1210, 952, 115, 120});
	SDL_FreeSurface(en);
}

void	draw_gun(t_sdl *sdl)
{
	if (sdl->gui.gun_type == G_RIFLE)
		SDL_BlitScaled(sdl->gui.rifle_gui, NULL, sdl->screen,
						&(SDL_Rect) {1670, 957, 220, 115});
	else if (sdl->gui.gun_type == G_PISTOL)
		SDL_BlitScaled(sdl->gui.pistol_gui, NULL, sdl->screen,
						&(SDL_Rect) {1670, 957, 220, 115});
}

int		all_enemies_are_dead(t_sdl *sdl)
{
	int i;

	i = -1;
	while (++i < sdl->map.enemy_count)
		if (sdl->map.enemies[i].status == ALIVE)
			return (FALSE);
	return (TRUE);
}
