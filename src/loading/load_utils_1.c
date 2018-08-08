/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:36:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 10:36:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wolf_inc.h"

void	load_doom_g_animations_utils_1(t_textures *t)
{
	t->doom_g_fire[1].x = 767;
	t->doom_g_fire[1].y = 0;
	t->doom_g_fire[1].h = 64;
	t->doom_g_fire[1].w = 64;
	t->doom_g_fire[2].x = 767;
	t->doom_g_fire[2].y = 0;
	t->doom_g_fire[2].h = 64;
	t->doom_g_fire[2].w = 64;
	t->doom_g_fire[3].x = 767;
	t->doom_g_fire[3].y = 0;
	t->doom_g_fire[3].h = 64;
	t->doom_g_fire[3].w = 64;
	t->doom_g_dead.x = 648;
	t->doom_g_dead.y = 0;
	t->doom_g_dead.h = 64;
	t->doom_g_dead.w = 64;
}

void	load_doom_g_animations(t_textures *t)
{
	t->doom_g_s.x = 0;
	t->doom_g_s.y = 0;
	t->doom_g_s.h = 64;
	t->doom_g_s.w = 64;
	t->doom_g_go[0].x = 68;
	t->doom_g_go[0].y = 0;
	t->doom_g_go[0].h = 64;
	t->doom_g_go[0].w = 64;
	t->doom_g_go[1].x = 128;
	t->doom_g_go[1].y = 0;
	t->doom_g_go[1].h = 64;
	t->doom_g_go[1].w = 64;
	t->doom_g_go[2].x = 68;
	t->doom_g_go[2].y = 0;
	t->doom_g_go[2].h = 64;
	t->doom_g_go[2].w = 64;
	t->doom_g_go[3].x = 128;
	t->doom_g_go[3].y = 0;
	t->doom_g_go[3].h = 64;
	t->doom_g_go[3].w = 64;
	t->doom_g_fire[0].x = 767;
	t->doom_g_fire[0].y = 0;
	t->doom_g_fire[0].h = 64;
	t->doom_g_fire[0].w = 64;
	load_doom_g_animations_utils_1(t);
}

void	load_unit_g_animations_utils_1(t_textures *t)
{
	t->unit_g_fire[1].x = 320;
	t->unit_g_fire[1].y = 0;
	t->unit_g_fire[1].h = 64;
	t->unit_g_fire[1].w = 64;
	t->unit_g_fire[2].x = 320;
	t->unit_g_fire[2].y = 0;
	t->unit_g_fire[2].h = 64;
	t->unit_g_fire[2].w = 64;
	t->unit_g_fire[3].x = 320;
	t->unit_g_fire[3].y = 0;
	t->unit_g_fire[3].h = 64;
	t->unit_g_fire[3].w = 64;
	t->unit_g_dead.x = 0;
	t->unit_g_dead.y = 0;
	t->unit_g_dead.h = 64;
	t->unit_g_dead.w = 64;
}

void	load_unit_g_animations(t_textures *t)
{
	t->unit_g_s.x = 0;
	t->unit_g_s.y = 0;
	t->unit_g_s.h = 64;
	t->unit_g_s.w = 64;
	t->unit_g_go[0].x = 64;
	t->unit_g_go[0].y = 0;
	t->unit_g_go[0].h = 64;
	t->unit_g_go[0].w = 64;
	t->unit_g_go[1].x = 128;
	t->unit_g_go[1].y = 0;
	t->unit_g_go[1].h = 64;
	t->unit_g_go[1].w = 64;
	t->unit_g_go[2].x = 192;
	t->unit_g_go[2].y = 0;
	t->unit_g_go[2].h = 64;
	t->unit_g_go[2].w = 64;
	t->unit_g_go[3].x = 256;
	t->unit_g_go[3].y = 0;
	t->unit_g_go[3].h = 64;
	t->unit_g_go[3].w = 64;
	t->unit_g_fire[0].x = 320;
	t->unit_g_fire[0].y = 0;
	t->unit_g_fire[0].h = 64;
	t->unit_g_fire[0].w = 64;
	load_unit_g_animations_utils_1(t);
}

void	load_icons(t_textures *textures)
{
	if (!(textures->wolf_icon[0] = IMG_Load(WOLF_ICON)) ||
		!(textures->wolf_icon[1] = IMG_Load(WOLF_ICON_P)) ||
		!(textures->test_icon[0] = IMG_Load(TEST_ICON)) ||
		!(textures->test_icon[1] = IMG_Load(TEST_ICON_P)) ||
		!(textures->maze_icon[0] = IMG_Load(MAZE_ICON)) ||
		!(textures->maze_icon[1] = IMG_Load(MAZE_ICON_P)) ||
		!(textures->doom_icon[0] = IMG_Load(DOOM_ICON)) ||
		!(textures->doom_icon[1] = IMG_Load(DOOM_ICON_P)) ||
		!(textures->unit_icon[0] = IMG_Load(UNIT_ICON)) ||
		!(textures->maze_bg = IMG_Load(MAZE_BG)) ||
		!(textures->unit_icon[1] = IMG_Load(UNIT_ICON_P)))
		error("Can't load icons.");
}
