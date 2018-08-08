/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:03:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/11 16:03:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_inc.h"

void	error(const char *reason)
{
	ft_printf("%s\n", reason);
	exit(2);
}

void	main_loop_events(t_sdl *sdl)
{
	if (sdl->event.type == SDL_KEYDOWN)
		sdl->event.key.keysym.sym < 300 ?
		sdl->keys[sdl->event.key.keysym.sym] = 1 : 0;
	if (sdl->event.type == SDL_KEYUP)
		sdl->event.key.keysym.sym < 300 ?
		sdl->keys[sdl->event.key.keysym.sym] = 0 : 0;
	if (sdl->event.type == SDL_QUIT || sdl->keys[SDLK_ESCAPE])
		sdl->quit = 1;
	if (sdl->event.type == SDL_MOUSEMOTION)
		check_mouse(sdl);
	if (sdl->keys[SDLK_c] && sdl->event.type != SDL_MOUSEMOTION)
		sdl->render.move_speed = sdl->render.frame_time * 5.0;
	else
		sdl->render.move_speed = sdl->render.frame_time * 3.0;
	main_loop_events_util_1(sdl);
	main_loop_events_util_2(sdl);
	main_loop_events_util_3(sdl);
	main_loop_events_util_4(sdl);
}

void	main_loop_util(t_sdl *sdl)
{
	if (sdl->map.player.health <= 0)
		you_died(sdl);
	if ((sdl->map.map_type == KILL_ALL && all_enemies_are_dead(sdl)) ||
		(sdl->map.map_type == FIND_EXIT && check_exit(sdl)) ||
		(sdl->map.map_type == PICK_ALL && check_picked_all(sdl)))
		you_win(sdl);
}

void	main_loop(t_sdl *sdl)
{
	sdl->render.old_time = sdl->render.new_time;
	sdl->render.new_time = SDL_GetTicks();
	sdl->render.frame_time =
	(sdl->render.new_time - sdl->render.old_time) / 1000.0;
	sdl->render.rot_speed = sdl->render.frame_time / 1.1;
	while (SDL_PollEvent(&sdl->event))
		main_loop_events(sdl);
	enemy_ai(sdl);
	SDL_FillRect(sdl->screen,
	&(SDL_Rect){0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}, 0x00FFFF);
	main_render(sdl);
	animate_gun(sdl);
	if (sdl->map.map_type == KILL_ALL)
	{
		draw_gui(sdl);
		SDL_FillRect(sdl->screen, &(SDL_Rect) {SCREEN_WIDTH / 2,
		SCREEN_HEIGHT / 2 - 10, 1, 20}, 0xFF0000);
		SDL_FillRect(sdl->screen, &(SDL_Rect) {SCREEN_WIDTH / 2 - 10,
		SCREEN_HEIGHT / 2, 20, 1}, 0xFF0000);
	}
	if (sdl->gui.minimap)
		draw_minimap(sdl);
	SDL_UpdateWindowSurface(sdl->window);
	main_loop_util(sdl);
}

int		main(int argc, char **argv)
{
	t_sdl sdl;

	init_sdl(&sdl);
	load_all(&sdl);
	if (argc == 1 || (argc >= 2 && ft_strcmp(argv[1], "-skip")))
	{
		animate_fade_in(&sdl, sdl.textures.unit_intro, 3);
		animate_fade_out(&sdl, sdl.textures.unit_intro, 3);
		animate_fade_in(&sdl, sdl.textures.menu_bg, 1);
	}
	ft_bzero(sdl.keys, sizeof(int) * 300);
	sdl.quit = 0;
	menu_loop(&sdl);
	return (0);
}
