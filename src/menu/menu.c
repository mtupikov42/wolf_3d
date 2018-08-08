/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 00:05:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/12 00:05:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wolf_inc.h"

void	menu_loop_util_1(t_sdl *sdl, char *map)
{
	if (!ft_strcmp(map, TEST_C))
	{
		sdl->map.map_type = NOTHING;
		sdl->map.has_ceiling = TRUE;
		sdl->map.has_guns = FALSE;
		sdl->map.ceiling = sdl->textures.bluestone;
		sdl->map.floor = sdl->textures.wood;
		parse_map(&sdl->map, map);
		parse_map_textures(sdl, TEST_C"_textures");
	}
	else if (!ft_strcmp(map, WOLF_C))
	{
		sdl->map.map_type = KILL_ALL;
		sdl->map.has_ceiling = TRUE;
		sdl->map.has_guns = TRUE;
		sdl->map.ceiling = sdl->textures.bluestone;
		sdl->map.floor = sdl->textures.wood;
		parse_map(&sdl->map, map);
		parse_map_textures(sdl, WOLF_C"_textures");
		Mix_PlayMusic(sdl->media.wolf_map_music, -1);
	}
}

void	menu_loop_util_2(t_sdl *sdl, char *map)
{
	if (!ft_strcmp(map, LABYRINTH_C))
	{
		sdl->map.map_type = FIND_EXIT;
		sdl->map.has_ceiling = FALSE;
		sdl->map.has_guns = FALSE;
		sdl->map.floor = sdl->textures.grass;
		sdl->map.bg = sdl->textures.maze_bg;
		sdl->gui.x_go_to = 1;
		sdl->gui.y_go_to = 1;
		parse_map(&sdl->map, map);
		parse_map_textures(sdl, LABYRINTH_C"_textures");
	}
	else if (!ft_strcmp(map, DOOM_C))
	{
		sdl->map.map_type = KILL_ALL;
		sdl->map.has_ceiling = TRUE;
		sdl->map.has_guns = TRUE;
		sdl->map.floor = sdl->textures.metal_wall_3;
		sdl->map.ceiling = sdl->textures.metal_wall_3;
		parse_map(&sdl->map, map);
		parse_map_textures(sdl, DOOM_C"_textures");
		Mix_PlayMusic(sdl->media.doom_map_music, -1);
	}
}

void	menu_loop_util_3(t_sdl *sdl, char *map)
{
	if (!ft_strcmp(map, UNIT_C))
	{
		sdl->map.map_type = PICK_ALL;
		sdl->map.has_ceiling = TRUE;
		sdl->map.has_guns = FALSE;
		sdl->map.floor = sdl->textures.unit_floor;
		sdl->map.ceiling = sdl->textures.unit_ceiling;
		parse_map(&sdl->map, map);
		parse_map_textures(sdl, UNIT_C"_textures");
	}
}

void	menu_loop(t_sdl *sdl)
{
	char	*map;

	default_player(sdl);
	Mix_PlayMusic(sdl->media.menu_music, -1);
	map = NULL;
	SDL_BlitSurface(sdl->textures.menu_bg, NULL, sdl->screen, NULL);
	while (1)
	{
		while (SDL_PollEvent(&sdl->event))
			map = main_menu_events(sdl);
		if (map == NULL)
			return ;
		else if (map != NULL + 1)
			break ;
		SDL_UpdateWindowSurface(sdl->window);
	}
	Mix_HaltMusic();
	menu_loop_util_1(sdl, map);
	menu_loop_util_2(sdl, map);
	menu_loop_util_3(sdl, map);
	SDL_SetRelativeMouseMode(SDL_TRUE);
	while (!sdl->quit)
		main_loop(sdl);
}
