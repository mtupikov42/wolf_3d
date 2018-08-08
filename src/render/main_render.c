/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 19:39:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/11 19:39:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wolf_inc.h"

void	check_enemy(t_sdl *sdl)
{
	int i;

	i = -1;
	while (++i < sdl->map.enemy_count)
		if (((int)sdl->map.enemies[i].pos_x == sdl->render.map_x &&
			(int)sdl->map.enemies[i].pos_y == sdl->render.map_y) ||
			((int)round(sdl->map.enemies[i].pos_x) == sdl->render.map_x
			&& (int)round(sdl->map.enemies[i].pos_y) == sdl->render.map_y))
		{
			if (sdl->gui.fire && sdl->map.enemies[i].health > 0 &&
				sdl->render.t && !(int)dot_prod(sdl->map.enemies[i].pos_x,
				sdl->map.enemies[i].pos_y, sdl->map.player.dir_x,
				sdl->map.player.dir_y))
			{
				sdl->map.enemies[i].health -= sdl->gui.fire_damage;
				sdl->render.t = 0;
			}
			draw_enemy(sdl, &sdl->map.enemies[i], sdl->render.j);
		}
}

void	dda(t_sdl *sdl)
{
	while (1)
	{
		if (sdl->render.side_dist_x < sdl->render.side_dist_y)
		{
			sdl->render.side_dist_x += sdl->render.delta_dist_x;
			sdl->render.map_x += sdl->render.step_x;
			sdl->render.side = 0;
		}
		else
		{
			sdl->render.side_dist_y += sdl->render.delta_dist_y;
			sdl->render.map_y += sdl->render.step_y;
			sdl->render.side = 1;
		}
		check_enemy(sdl);
		if (sdl->map.map[sdl->render.map_y][sdl->render.map_x].type == WALL
		|| sdl->map.map[sdl->render.map_y][sdl->render.map_x].type == WALL4)
			break ;
		if (sdl->map.map[sdl->render.map_y][sdl->render.map_x].type == SPRITE)
			sprite_rend(sdl, sdl->render.j);
	}
}

void	draw_bg(t_sdl *sdl)
{
	unsigned int	*pixels;
	unsigned int	*bg;

	bg = sdl->map.bg->pixels;
	pixels = sdl->screen->pixels;
	sdl->render.i = -1;
	while (++sdl->render.i < SCREEN_HEIGHT)
	{
		sdl->render.j = -1;
		while (++sdl->render.j < SCREEN_WIDTH)
			if (pixels[sdl->render.j +
				sdl->render.i * SCREEN_WIDTH] == 0x00FFFF)
				pixels[sdl->render.j + sdl->render.i * SCREEN_WIDTH] =
				bg[sdl->render.j + sdl->render.i * SCREEN_WIDTH];
	}
}

void	main_render(t_sdl *sdl)
{
	sdl->render.j = -1;
	sdl->render.t = 1;
	while (++sdl->render.j < SCREEN_WIDTH)
	{
		draw_camera(sdl);
		dda(sdl);
		draw_walls(sdl);
		draw_ceiling_floor(sdl);
	}
	if (sdl->map.has_ceiling == FALSE)
		draw_bg(sdl);
}
