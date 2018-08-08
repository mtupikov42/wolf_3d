/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:33:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 10:33:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wolf_inc.h"

void	load_unit_walls(t_textures *t)
{
	int			i;
	int			j;

	if (!(t->unit_walls = IMG_Load(UNIT_WALLS)))
		error("Can't load unit walls textures.");
	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 3)
		{
			if (i == 0 && j == 0)
				t->unit_wall = create_surface(t->unit_walls, i, j);
			else if (i == 0 && j == 1)
				t->unit_ceiling = create_surface(t->unit_walls, i, j);
			else if (i == 0 && j == 2)
				t->unit_floor = create_surface(t->unit_walls, i, j);
		}
	}
}

void	load_guns_animations(t_textures *textures)
{
	textures->pistol_go.x = 0;
	textures->pistol_go.y = 0;
	textures->pistol_go.h = 100;
	textures->pistol_go.w = 80;
	textures->pistol_fire[0].x = 80;
	textures->pistol_fire[0].y = 0;
	textures->pistol_fire[0].h = 100;
	textures->pistol_fire[0].w = 80;
	textures->pistol_fire[1].x = 80;
	textures->pistol_fire[1].y = 0;
	textures->pistol_fire[1].h = 100;
	textures->pistol_fire[1].w = 80;
	textures->rifle_go.x = 0;
	textures->rifle_go.y = 0;
	textures->rifle_go.h = 140;
	textures->rifle_go.w = 175;
	textures->rifle_fire[0].x = 180;
	textures->rifle_fire[0].y = 0;
	textures->rifle_fire[0].h = 140;
	textures->rifle_fire[0].w = 170;
	textures->rifle_fire[1].x = 345;
	textures->rifle_fire[1].y = 0;
	textures->rifle_fire[1].h = 140;
	textures->rifle_fire[1].w = 165;
}

void	load_wolf_sold_animations_utils_1(t_textures *textures)
{
	textures->wolf_s_fire[0].x = 722;
	textures->wolf_s_fire[0].y = 0;
	textures->wolf_s_fire[0].h = 65;
	textures->wolf_s_fire[0].w = 28;
	textures->wolf_s_fire[1].x = 785;
	textures->wolf_s_fire[1].y = 0;
	textures->wolf_s_fire[1].h = 65;
	textures->wolf_s_fire[1].w = 28;
	textures->wolf_s_fire[2].x = 785;
	textures->wolf_s_fire[2].y = 0;
	textures->wolf_s_fire[2].h = 65;
	textures->wolf_s_fire[2].w = 28;
	textures->wolf_s_fire[3].x = 785;
	textures->wolf_s_fire[3].y = 0;
	textures->wolf_s_fire[3].h = 65;
	textures->wolf_s_fire[3].w = 28;
	textures->wolf_s_dead.x = 655;
	textures->wolf_s_dead.y = 0;
	textures->wolf_s_dead.h = 65;
	textures->wolf_s_dead.w = 50;
}

void	load_wolf_sold_animations(t_textures *textures)
{
	textures->wolf_s_s.x = 19;
	textures->wolf_s_s.y = 0;
	textures->wolf_s_s.h = 65;
	textures->wolf_s_s.w = 28;
	textures->wolf_s_go[0].x = 84;
	textures->wolf_s_go[0].y = 0;
	textures->wolf_s_go[0].h = 65;
	textures->wolf_s_go[0].w = 28;
	textures->wolf_s_go[1].x = 147;
	textures->wolf_s_go[1].y = 0;
	textures->wolf_s_go[1].h = 65;
	textures->wolf_s_go[1].w = 28;
	textures->wolf_s_go[2].x = 210;
	textures->wolf_s_go[2].y = 0;
	textures->wolf_s_go[2].h = 65;
	textures->wolf_s_go[2].w = 28;
	textures->wolf_s_go[3].x = 275;
	textures->wolf_s_go[3].y = 0;
	textures->wolf_s_go[3].h = 65;
	textures->wolf_s_go[3].w = 28;
	load_wolf_sold_animations_utils_1(textures);
}

void	load_all(t_sdl *sdl)
{
	load_textures(&sdl->textures);
	load_guns_animations(&sdl->textures);
	load_wolf_sold_animations(&sdl->textures);
	load_icons(&sdl->textures);
	load_media(&sdl->media);
	load_gui(&sdl->gui);
	load_wolf_walls(&sdl->textures);
	load_doom_walls(&sdl->textures);
	load_doom_g_animations(&sdl->textures);
	load_unit_walls(&sdl->textures);
	load_unit_g_animations(&sdl->textures);
}
