/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:24:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 10:24:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_inc.h"

void		draw_minimap_util(t_sdl *sdl, const int xy[2], const int ij[2])
{
	if (xy[0] < sdl->map.map_height && xy[1] < sdl->map.map[xy[0]][0].len
		&& (sdl->map.map[xy[0]][xy[1]].type == WALL ||
			(sdl->map.map[xy[0]][xy[1]].type == SPRITE &&
			sdl->map.map[xy[0]][xy[1]].sprite.type == T_INTER)))
		SDL_FillRect(sdl->screen, &(SDL_Rect){1600 + ij[1] * 10,
		20 + ij[0] * 10, 15, 15}, 0xFFFFFF);
	else if (xy[0] == (int)(sdl->map.player.pos_y) &&
			xy[1] == (int)(sdl->map.player.pos_x))
		SDL_FillRect(sdl->screen, &(SDL_Rect){1600 + ij[1] * 10,
		20 + ij[0] * 10, 10, 10}, 0x00FF00);
	else if (check_enemy_minimap(sdl, xy[1], xy[0]))
		SDL_FillRect(sdl->screen, &(SDL_Rect){1600 + ij[1] * 10,
		20 + ij[0] * 10, 10, 10}, 0xFF0000);
}

void		draw_minimap(t_sdl *sdl)
{
	int i;
	int j;
	int x;
	int y;
	int xx;

	SDL_FillRect(sdl->screen, &(SDL_Rect){1590, 10, 325, 325}, 0x000000);
	x = ((int)(sdl->map.player.pos_x - 15)) < 0 ? 0 :
	(int)(sdl->map.player.pos_x - 15);
	y = ((int)(sdl->map.player.pos_y - 15)) < 0 ? 0 :
	(int)(sdl->map.player.pos_y - 15);
	i = -1;
	xx = x;
	while (++i < 30)
	{
		x = xx;
		j = -1;
		while (++j < 30)
		{
			draw_minimap_util(sdl, (int[]){y, x}, (int[]){i, j});
			++x;
		}
		++y;
	}
}

void		check_mouse_util(t_sdl *sdl)
{
	if (sdl->mouse.new_x < 0)
	{
		sdl->render.old_dir_x = sdl->map.player.dir_x;
		sdl->map.player.dir_x = sdl->map.player.dir_x *
		cos(sdl->render.rot_speed) - sdl->map.player.dir_y *
		sin(sdl->render.rot_speed);
		sdl->map.player.dir_y = sdl->render.old_dir_x *
		sin(sdl->render.rot_speed) + sdl->map.player.dir_y *
		cos(sdl->render.rot_speed);
		sdl->render.old_plane_x = sdl->map.plane_x;
		sdl->map.plane_x = sdl->map.plane_x * cos(sdl->render.rot_speed) -
		sdl->map.plane_y * sin(sdl->render.rot_speed);
		sdl->map.plane_y = sdl->render.old_plane_x * sin(sdl->render.rot_speed)
		+ sdl->map.plane_y * cos(sdl->render.rot_speed);
	}
}

void		check_mouse(t_sdl *sdl)
{
	SDL_GetRelativeMouseState(&sdl->mouse.new_x, &sdl->mouse.new_y);
	if (sdl->mouse.new_x > 0)
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
	check_mouse_util(sdl);
}

SDL_Surface	*create_surface(SDL_Surface *walls, int i, int j)
{
	SDL_Surface	*en;
	SDL_Surface	*ret;

	en = SDL_CreateRGBSurface(0, 64, 64, 32, 0, 0, 0, 0);
	SDL_BlitSurface(walls, &(SDL_Rect){j * 64, i * 64, 64, 64},
					en, &(SDL_Rect){0, 0, 64, 64});
	ret = SDL_DuplicateSurface(en);
	SDL_FreeSurface(en);
	return (ret);
}
