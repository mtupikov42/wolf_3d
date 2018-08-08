/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:44:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 10:44:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_inc.h"

void	animate_fade_in(t_sdl *sdl, SDL_Surface *s, int rate)
{
	Uint8 alpha;

	alpha = SDL_ALPHA_TRANSPARENT;
	while (++alpha < SDL_ALPHA_OPAQUE / rate)
	{
		SDL_SetSurfaceAlphaMod(s, alpha);
		SDL_BlitSurface(s, NULL, sdl->screen, NULL);
		SDL_UpdateWindowSurface(sdl->window);
		SDL_FillRect(sdl->screen, NULL, 0x000000);
		SDL_Delay(16);
	}
}

void	animate_fade_out(t_sdl *sdl, SDL_Surface *s, int rate)
{
	Uint8 alpha;

	alpha = (Uint8)(SDL_ALPHA_OPAQUE / rate);
	while (--alpha > SDL_ALPHA_TRANSPARENT)
	{
		SDL_SetSurfaceAlphaMod(s, alpha);
		SDL_BlitSurface(s, NULL, sdl->screen, NULL);
		SDL_UpdateWindowSurface(sdl->window);
		SDL_FillRect(sdl->screen, NULL, 0x000000);
		SDL_Delay(16);
	}
}

void	animate_gun(t_sdl *sdl)
{
	if (sdl->gui.gun_type != G_NOTHING && sdl->map.has_guns)
	{
		if (!sdl->gui.fire)
		{
			SDL_BlitScaled(sdl->gui.texture, sdl->gui.walk_anim, sdl->screen,
			&(SDL_Rect) {sdl->gui.x_draw, sdl->gui.y_draw + sdl->gui.gr_r,
			sdl->gui.x_draw_m, sdl->gui.y_draw_m});
		}
		else
		{
			Mix_PlayChannel(-1, sdl->gui.fire_sound, 0);
			SDL_BlitScaled(sdl->gui.texture,
			&sdl->gui.fire_anim[(SDL_GetTicks() / 100) % 2], sdl->screen,
			&(SDL_Rect) {sdl->gui.x_draw, sdl->gui.y_draw + sdl->gui.gr_r,
			sdl->gui.x_draw_m, sdl->gui.y_draw_m});
			sdl->gui.fire = 0;
		}
	}
}

int		check_exit(t_sdl *sdl)
{
	return ((int)sdl->map.player.pos_x == sdl->gui.x_go_to &&
			(int)sdl->map.player.pos_y == sdl->gui.y_go_to);
}
