/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:09:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 10:09:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wolf_inc.h"

char	*select_map_events(t_sdl *sdl)
{
	int		x;
	int		y;
	char	*t;

	SDL_GetMouseState(&x, &y);
	put_maps_info(sdl, x, y);
	if ((sdl->event.type == SDL_QUIT) || (sdl->event.type == SDL_KEYDOWN
		&& sdl->event.key.keysym.sym == SDLK_ESCAPE))
		return (NULL);
	if ((t = select_map_events_util_1(sdl, x, y)) != NULL)
		return (t);
	if (x > 900 && x < 1100 && y > 100 && y < 300 &&
		sdl->event.type == SDL_MOUSEBUTTONDOWN)
		return (LABYRINTH_C);
	if (x > 1300 && x < 1500 && y > 100 && y < 300 &&
		sdl->event.type == SDL_MOUSEBUTTONDOWN)
		return (DOOM_C);
	if (x > 100 && x < 300 && y > 500 && y < 700 &&
		sdl->event.type == SDL_MOUSEBUTTONDOWN)
		return (UNIT_C);
	return (NULL + 1);
}

char	*select_map_menu(t_sdl *sdl)
{
	char *map;

	map = NULL + 1;
	SDL_BlitSurface(sdl->textures.select_map_bg, NULL, sdl->screen, NULL);
	while (1)
	{
		while (SDL_PollEvent(&sdl->event))
			map = select_map_events(sdl);
		if (map != NULL && map != NULL + 1 && map != NULL + 2)
			return (map);
		else if (map == NULL + 2)
		{
			Mix_PlayChannel(-1, sdl->media.menu_select, 0);
			SDL_BlitSurface(sdl->textures.menu_bg, NULL, sdl->screen, NULL);
			break ;
		}
		else if (map == NULL)
			return (NULL);
		SDL_UpdateWindowSurface(sdl->window);
	}
	return (NULL + 1);
}

char	*main_menu_events(t_sdl *sdl)
{
	int		x;
	int		y;

	SDL_GetMouseState(&x, &y);
	put_menu_info(sdl, x, y);
	if ((x > 1700 && x < 1770 && y > 1030 && y < 1070 &&
		sdl->event.type == SDL_MOUSEBUTTONDOWN) ||
		(sdl->event.type == SDL_QUIT) || (sdl->event.type == SDL_KEYDOWN
		&& sdl->event.key.keysym.sym == SDLK_ESCAPE))
		return (NULL);
	if ((x > 1700 && x < 1860 && y > 950 && y < 980 &&
		sdl->event.type == SDL_MOUSEBUTTONDOWN))
	{
		Mix_PlayChannel(-1, sdl->media.menu_select, 0);
		return (select_map_menu(sdl));
	}
	return (NULL + 1);
}
