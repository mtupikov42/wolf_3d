/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:05:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 10:05:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wolf_inc.h"

void	draw_walls_utils(t_sdl *sdl, SDL_Surface *s)
{
	if (sdl->render.draw_start < 0)
		sdl->render.draw_start = 0;
	sdl->render.draw_end = sdl->render.line_height / 2 + SCREEN_HEIGHT / 2;
	if (sdl->render.draw_end >= SCREEN_HEIGHT)
		sdl->render.draw_end = SCREEN_HEIGHT - 1;
	if (!sdl->render.side)
		sdl->render.wall_x = sdl->map.player.pos_y + sdl->render.perp_wall_dist
		* sdl->render.ray_dir_y;
	else
		sdl->render.wall_x = sdl->map.player.pos_x + sdl->render.perp_wall_dist
		* sdl->render.ray_dir_x;
	sdl->render.wall_x -= floor(sdl->render.wall_x);
	sdl->render.tex_x = (int)(sdl->render.wall_x * (double)64);
	if (!sdl->render.side && sdl->render.ray_dir_x > 0)
		sdl->render.tex_x = 64 - sdl->render.tex_x - 1;
	if (sdl->render.side && sdl->render.ray_dir_y < 0)
		sdl->render.tex_x = 64 - sdl->render.tex_x - 1;
	put_pixels_in_line(sdl, (int[]){sdl->render.j, sdl->render.draw_start,
	sdl->render.draw_end, sdl->render.tex_x, sdl->render.line_height,
	sdl->render.side}, s);
}

void	draw_walls(t_sdl *sdl)
{
	SDL_Surface *s;

	if (sdl->map.map[sdl->render.map_y][sdl->render.map_x].type != WALL4)
		s = sdl->map.map[sdl->render.map_y][sdl->render.map_x].texture;
	else
		s = choose_wall(sdl);
	if (sdl->render.side == 0)
		sdl->render.perp_wall_dist = (sdl->render.map_x - sdl->map.player.pos_x
		+ (1 - sdl->render.step_x) / 2) / sdl->render.ray_dir_x;
	else
		sdl->render.perp_wall_dist = (sdl->render.map_y - sdl->map.player.pos_y
		+ (1 - sdl->render.step_y) / 2) / sdl->render.ray_dir_y;
	sdl->render.line_height = (int)(SCREEN_HEIGHT /
									sdl->render.perp_wall_dist);
	sdl->render.draw_start = -sdl->render.line_height / 2 + SCREEN_HEIGHT / 2;
	draw_walls_utils(sdl, s);
}

void	draw_camera_util(t_sdl *sdl)
{
	if (sdl->render.ray_dir_x < 0)
	{
		sdl->render.step_x = -1;
		sdl->render.side_dist_x = (sdl->map.player.pos_x -
		sdl->render.map_x) * sdl->render.delta_dist_x;
	}
	else
	{
		sdl->render.step_x = 1;
		sdl->render.side_dist_x = (1.0 - sdl->map.player.pos_x +
		sdl->render.map_x) * sdl->render.delta_dist_x;
	}
	if (sdl->render.ray_dir_y < 0)
	{
		sdl->render.step_y = -1;
		sdl->render.side_dist_y = (sdl->map.player.pos_y -
		sdl->render.map_y) * sdl->render.delta_dist_y;
	}
	else
	{
		sdl->render.step_y = 1;
		sdl->render.side_dist_y = (1.0 - sdl->map.player.pos_y +
		sdl->render.map_y) * sdl->render.delta_dist_y;
	}
}

void	draw_camera(t_sdl *sdl)
{
	sdl->render.camera_x = 2 * sdl->render.j / (double)SCREEN_WIDTH - 1;
	sdl->render.ray_dir_x = sdl->map.player.dir_x +
	sdl->map.plane_x * sdl->render.camera_x;
	sdl->render.ray_dir_y = sdl->map.player.dir_y +
	sdl->map.plane_y * sdl->render.camera_x;
	sdl->render.map_x = (int)sdl->map.player.pos_x;
	sdl->render.map_y = (int)sdl->map.player.pos_y;
	sdl->render.delta_dist_x = fabs(1 / sdl->render.ray_dir_x);
	sdl->render.delta_dist_y = fabs(1 / sdl->render.ray_dir_y);
	draw_camera_util(sdl);
}

double	dot_prod(double x1, double y1, double x2, double y2)
{
	return (x1 * x2 + y1 * y2);
}
