/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:31:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 10:31:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_inc.h"

void	draw_gui_util(t_sdl *sdl)
{
	if (sdl->map.player.health > 85)
		draw_face(sdl, 0);
	else if (sdl->map.player.health <= 85 && sdl->map.player.health > 70)
		draw_face(sdl, 1);
	else if (sdl->map.player.health <= 70 && sdl->map.player.health > 55)
		draw_face(sdl, 2);
	else if (sdl->map.player.health <= 55 && sdl->map.player.health > 40)
		draw_face(sdl, 3);
	else if (sdl->map.player.health <= 40 && sdl->map.player.health > 25)
		draw_face(sdl, 4);
	else if (sdl->map.player.health <= 25 && sdl->map.player.health > 10)
		draw_face(sdl, 5);
	else if (sdl->map.player.health <= 10 && sdl->map.player.health > 0)
		draw_face(sdl, 6);
}

void	draw_gui(t_sdl *sdl)
{
	char *num;

	SDL_BlitScaled(sdl->gui.gui_interface, NULL, sdl->screen,
	&(SDL_Rect){1200, 950, SCREEN_WIDTH - 1200, SCREEN_HEIGHT - 950});
	draw_gui_util(sdl);
	num = ft_itoa((int)sdl->map.player.health);
	put_info(sdl, WOLF_FONT, num, (int[]){1350, 1000, 90, 0xFF, 0xFF, 0xFF});
	ft_strdel(&num);
	if (sdl->gui.gun_type != G_NOTHING)
	{
		draw_gun(sdl);
		num = ft_itoa(*sdl->gui.ammo);
		put_info(sdl, WOLF_FONT, num,
				(int[]){1500, 1000, 90, 0xFF, 0xFF, 0xFF});
	}
	ft_strdel(&num);
}

void	you_died(t_sdl *sdl)
{
	SDL_Delay(1000);
	while (!sdl->quit)
	{
		while (SDL_PollEvent(&sdl->event))
			if (sdl->event.type == SDL_KEYDOWN || sdl->event.type == SDL_QUIT)
				sdl->quit = 1;
		SDL_FillRect(sdl->screen,
		&(SDL_Rect) {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}, 0x000000);
		put_info(sdl, WOLF_FONT, "YOU DIED",
				(int[]){400, 400, 300, 0xFF, 0x00, 0x00});
		put_info(sdl, WOLF_FONT, "Press any key to exit.",
				(int[]){250, 700, 150, 0xFF, 0x00, 0x00});
		SDL_UpdateWindowSurface(sdl->window);
	}
}

void	you_win(t_sdl *sdl)
{
	SDL_Delay(1000);
	while (!sdl->quit)
	{
		while (SDL_PollEvent(&sdl->event))
			if (sdl->event.type == SDL_KEYDOWN || sdl->event.type == SDL_QUIT)
				sdl->quit = 1;
		SDL_FillRect(sdl->screen,
		&(SDL_Rect) {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}, 0x000000);
		put_info(sdl, WOLF_FONT, "YOU WIN",
				(int[]){400, 400, 300, 0x00, 0xFF, 0x00});
		put_info(sdl, WOLF_FONT, "Press any key to exit.",
				(int[]){250, 700, 150, 0x00, 0xFF, 0x00});
		SDL_UpdateWindowSurface(sdl->window);
	}
}

int		check_picked_all(t_sdl *sdl)
{
	int i;
	int j;

	i = -1;
	while (++i < sdl->map.map_height)
	{
		j = -1;
		while (++j < sdl->map.map[i][0].len)
			if (sdl->map.map[i][j].type == SPRITE &&
				sdl->map.map[i][j].sprite.picked == FALSE)
				return (FALSE);
	}
	return (TRUE);
}
