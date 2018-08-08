/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:00:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 10:00:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wolf_inc.h"

void	put_pixel(t_sdl *sdl, SDL_Surface *floor,
					SDL_Surface *ceiling, const int k[5])
{
	unsigned int	*pixels;
	unsigned int	*floor_pixels;
	unsigned int	*ceiling_pixels;
	int				col;

	pixels = sdl->screen->pixels;
	if (floor)
	{
		floor_pixels = floor->pixels;
		col = floor_pixels[k[2] * k[3] + k[4]];
		if (pixels[k[0] + SCREEN_WIDTH * k[1]] == 0x00FFFF)
			pixels[k[0] + SCREEN_WIDTH * k[1]] = col;
	}
	if (ceiling && sdl->map.has_ceiling)
	{
		ceiling_pixels = ceiling->pixels;
		col = ceiling_pixels[k[2] * k[3] + k[4]];
		if (pixels[k[0] + SCREEN_WIDTH * (SCREEN_HEIGHT - k[1])] == 0x00FFFF)
			pixels[k[0] + SCREEN_WIDTH * (SCREEN_HEIGHT - k[1])] = col;
	}
}

void	put_pixels_in_line(t_sdl *sdl, const int k[6], SDL_Surface *texture)
{
	unsigned int	*pixels;
	unsigned int	*texture_pixels;
	int				id[2];
	int				tex_y;
	int				color;

	pixels = sdl->screen->pixels;
	id[0] = k[1] - 1;
	while (++id[0] < k[2])
	{
		texture_pixels = texture->pixels;
		id[1] = id[0] * 256 - SCREEN_HEIGHT * 128 + k[4] * 128;
		tex_y = ((id[1] * 64) / k[4]) / 256;
		color = texture_pixels[64 * tex_y + k[3]];
		if (pixels[k[0] + SCREEN_WIDTH * id[0]] == 0x00FFFF)
		{
			if (k[5] == 1)
				color = (color >> 1) & 8355711;
			pixels[k[0] + SCREEN_WIDTH * id[0]] = (unsigned int)color;
		}
	}
}

void	draw_sprite(t_sdl *sdl, SDL_Surface *texture, int x)
{
	unsigned int	*pixels;
	unsigned int	*texture_pixels;
	int				tex_x;
	int				tex_y;
	int				i;

	pixels = (unsigned int *)sdl->screen->pixels +
			sdl->render.draw_start_y * SCREEN_WIDTH + x;
	texture_pixels = texture->pixels;
	tex_x = (int)(256 * (x - (-abs((int)(SCREEN_HEIGHT / sdl->render.tr_y)) / 2
	+ (int)((SCREEN_WIDTH / 2) * (1 + sdl->render.tr_x / sdl->render.tr_y)))) *
	texture->w / fabs((SCREEN_HEIGHT / sdl->render.tr_y))) / 256;
	i = sdl->render.draw_start_y - 1;
	while (++i < sdl->render.draw_start_x)
	{
		tex_y = (((i * 2 - SCREEN_HEIGHT + sdl->render.sprite_height) *
					texture->h) / sdl->render.sprite_height) / 2;
		if (*pixels == 0x00FFFF && tex_x >= 0 && tex_y >= 0 &&
			tex_x < texture->w && tex_y < texture->w &&
			texture_pixels[texture->w * tex_y + tex_x] != 0x000000)
			*pixels = texture_pixels[texture->w * tex_y + tex_x];
		pixels += SCREEN_WIDTH;
	}
}

void	sprite_rend_utils(t_sdl *sdl)
{
	sdl->render.sprite_x = sdl->map.map[sdl->render.map_y]
	[sdl->render.map_x].sprite.x + 0.5 - sdl->map.player.pos_x;
	sdl->render.sprite_y = sdl->map.map[sdl->render.map_y]
	[sdl->render.map_x].sprite.y + 0.5 - sdl->map.player.pos_y;
	sdl->render.inv_det = 1.0 / (sdl->map.plane_x * sdl->map.player.dir_y
	- sdl->map.player.dir_x * sdl->map.plane_y);
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
}

void	sprite_rend(t_sdl *sdl, int j)
{
	sprite_rend_utils(sdl);
	if (sdl->map.map[sdl->render.map_y][sdl->render.map_x].sprite.type ==
		T_PICKABLE && !sdl->map.map[sdl->render.map_y]
	[sdl->render.map_x].sprite.picked)
		draw_sprite(sdl, sdl->map.map[sdl->render.map_y]
		[sdl->render.map_x].texture, j);
	else if (sdl->map.map[sdl->render.map_y][sdl->render.map_x].sprite.type
			!= T_PICKABLE)
		draw_sprite(sdl, sdl->map.map[sdl->render.map_y]
		[sdl->render.map_x].texture, j);
}
