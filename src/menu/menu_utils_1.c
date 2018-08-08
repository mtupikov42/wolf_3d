/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:08:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 10:08:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wolf_inc.h"

void	default_player(t_sdl *sdl)
{
	sdl->map.plane_x = 0.0;
	sdl->map.plane_y = 0.66;
	sdl->map.player.pos_x = -1;
	sdl->map.player.pos_y = -1;
	sdl->map.player.dir_x = -1;
	sdl->map.player.dir_y = 0;
	sdl->render.old_time = 0;
	sdl->render.new_time = 0;
	sdl->gui.gr_r = 0;
	sdl->gui.fire = 0;
	sdl->gui.minimap = 0;
	sdl->map.player.health = 100.0;
	sdl->gui.rifle_ammo = 50;
	sdl->gui.pistol_ammo = 20;
	sdl->map.enemy_count = 0;
	sdl->gui.gun_type = G_NOTHING;
}

void	put_menu_info(t_sdl *sdl, int x, int y)
{
	if (x > 1700 && x < 1860 && y > 950 && y < 980)
		put_info(sdl, WOLF_FONT, "NEW GAME",
				(int[]){1700, 950, 40, 0xFF / 2, 0xFF / 2, 0xFF / 2});
	else
		put_info(sdl, WOLF_FONT, "NEW GAME",
				(int[]){1700, 950, 40, 0xFF, 0xFF, 0xFF});
	if (x > 1700 && x < 1770 && y > 1030 && y < 1060)
		put_info(sdl, WOLF_FONT, "EXIT",
				(int[]){1700, 1030, 40, 0xFF / 2, 0xFF / 2, 0xFF / 2});
	else
		put_info(sdl, WOLF_FONT, "EXIT",
				(int[]){1700, 1030, 40, 0xFF, 0xFF, 0xFF});
}

void	put_maps_info_utils_1(t_sdl *sdl, int x, int y)
{
	if (x > 100 && x < 300 && y > 100 && y < 300)
		SDL_BlitSurface(sdl->textures.wolf_icon[1], NULL, sdl->screen,
						&(SDL_Rect){100, 100, 200, 200});
	else
		SDL_BlitSurface(sdl->textures.wolf_icon[0], NULL, sdl->screen,
						&(SDL_Rect){100, 100, 200, 200});
	if (x > 500 && x < 700 && y > 100 && y < 300)
		SDL_BlitSurface(sdl->textures.test_icon[1], NULL, sdl->screen,
						&(SDL_Rect){500, 100, 200, 200});
	else
		SDL_BlitSurface(sdl->textures.test_icon[0], NULL, sdl->screen,
						&(SDL_Rect){500, 100, 200, 200});
	if (x > 900 && x < 1100 && y > 100 && y < 300)
		SDL_BlitSurface(sdl->textures.maze_icon[1], NULL, sdl->screen,
						&(SDL_Rect){900, 100, 200, 200});
	else
		SDL_BlitSurface(sdl->textures.maze_icon[0], NULL, sdl->screen,
						&(SDL_Rect){900, 100, 200, 200});
	if (x > 1300 && x < 1500 && y > 100 && y < 300)
		SDL_BlitSurface(sdl->textures.doom_icon[1], NULL, sdl->screen,
						&(SDL_Rect){1300, 100, 200, 200});
	else
		SDL_BlitSurface(sdl->textures.doom_icon[0], NULL, sdl->screen,
						&(SDL_Rect){1300, 100, 200, 200});
}

void	put_maps_info(t_sdl *sdl, int x, int y)
{
	put_maps_info_utils_1(sdl, x, y);
	if (x > 100 && x < 300 && y > 500 && y < 700)
		SDL_BlitSurface(sdl->textures.unit_icon[1], NULL, sdl->screen,
						&(SDL_Rect){100, 500, 200, 200});
	else
		SDL_BlitSurface(sdl->textures.unit_icon[0], NULL, sdl->screen,
						&(SDL_Rect){100, 500, 200, 200});
	put_info(sdl, WOLF_FONT, "WOLF3D",
			(int[]){130, 320, 40, 0xFF, 0xFF, 0xFF});
	put_info(sdl, WOLF_FONT, "TEST", (int[]){560, 320, 40, 0xFF, 0xFF, 0xFF});
	put_info(sdl, WOLF_FONT, "LABYRINTH",
			(int[]){915, 320, 40, 0xFF, 0xFF, 0xFF});
	put_info(sdl, WOLF_FONT, "DOOM", (int[]){1360, 320, 40, 0xFF, 0xFF, 0xFF});
	put_info(sdl, WOLF_FONT, "UNIT", (int[]){130, 720, 40, 0xFF, 0xFF, 0xFF});
	if (x > 1750 && x < 1830 && y > 1030 && y < 1060)
		put_info(sdl, WOLF_FONT, "BACK",
				(int[]){1750, 1030, 40, 0xFF / 2, 0xFF / 2, 0xFF / 2});
	else
		put_info(sdl, WOLF_FONT, "BACK",
				(int[]){1750, 1030, 40, 0xFF, 0xFF, 0xFF});
}

char	*select_map_events_util_1(t_sdl *sdl, int x, int y)
{
	if (x > 1750 && x < 1830 && y > 1030 && y < 1070 &&
		sdl->event.type == SDL_MOUSEBUTTONDOWN)
		return (NULL + 2);
	if (x > 100 && x < 300 && y > 100 && y < 300 &&
		sdl->event.type == SDL_MOUSEBUTTONDOWN)
		return (WOLF_C);
	if (x > 500 && x < 700 && y > 100 && y < 300 &&
		sdl->event.type == SDL_MOUSEBUTTONDOWN)
		return (TEST_C);
	return (NULL);
}
