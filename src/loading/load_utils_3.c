/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:39:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 10:39:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wolf_inc.h"

void	load_textures(t_textures *t)
{
	if (!(t->unit_intro = IMG_Load(UNIT_INTRO)) ||
		!(t->menu_bg = IMG_Load(MENU_BG)) ||
		!(t->select_map_bg = IMG_Load(SELECT_BG)) ||
		!(t->barrel = IMG_Load(BARREL)) ||
		!(t->glight = IMG_Load(GLIGHT)) ||
		!(t->pillar = IMG_Load(PILLAR)) ||
		!(t->rifle = IMG_Load(RIFLE)) ||
		!(t->pistol = IMG_Load(PISTOL)) ||
		!(t->wolf_sold = IMG_Load(WOLF_SOLD)) ||
		!(t->bush_wall = IMG_Load(BUSH_WALL)) ||
		!(t->grass = IMG_Load(GRASS)) ||
		!(t->medpack = IMG_Load(MEDPACK)) ||
		!(t->ammo = IMG_Load(AMMO)) ||
		!(t->table = IMG_Load(TABLE)) ||
		!(t->toilet = IMG_Load(TOILET)) ||
		!(t->chair = IMG_Load(CHAIR)) ||
		!(t->doom_barrel = IMG_Load(D_BARREL)) ||
		!(t->doom_box = IMG_Load(D_BOX)) ||
		!(t->doom_wtf = IMG_Load(D_WTF)) ||
		!(t->floor_light = IMG_Load(FLOOR_LIGHT)) ||
		!(t->portal = IMG_Load(PORTAL)) ||
		!(t->doom_g = IMG_Load(DOOM_SOLD)) ||
		!(t->tizh = IMG_Load(TIZH)) ||
		!(t->unit_g = IMG_Load(UNIT_SOLD)))
		error("Can't load sprites.");
}

void	load_media(t_media *media)
{
	if (!(media->wolf_s_death = Mix_LoadWAV("media/wolf_s_death.wav")) ||
		!(media->wolf_p_in_s = Mix_LoadWAV("media/wolf_p_in_s.wav")) ||
		!(media->pistol_fire = Mix_LoadWAV("media/pistol_fire.wav")) ||
		!(media->wolf_s_fire = Mix_LoadWAV("media/pistol_fire.wav")) ||
		!(media->rifle_fire = Mix_LoadWAV("media/rifle_fire.wav")) ||
		!(media->pickup = Mix_LoadWAV("media/pickup.wav")) ||
		!(media->wolf_map_music = Mix_LoadMUS("media/wolf_map_music.wav")) ||
		!(media->menu_music = Mix_LoadMUS("media/menu_music.wav")) ||
		!(media->menu_select = Mix_LoadWAV("media/menu_select.wav")) ||
		!(media->doom_g_fire = Mix_LoadWAV("media/doom_g_attack.wav")) ||
		!(media->doom_g_death = Mix_LoadWAV("media/doom_g_death.wav")) ||
		!(media->doom_p_in_s = Mix_LoadWAV("media/doom_p_in_s.wav")) ||
		!(media->doom_map_music = Mix_LoadMUS("media/doom_map_music.wav")))
		error("Can't load media.");
}

void	load_gui(t_gui *gui)
{
	if (!(gui->blaz_face = IMG_Load(GUI_BJ)) ||
		!(gui->gui_interface = IMG_Load(GUI_INTERFACE)) ||
		!(gui->rifle_gui = IMG_Load(GUI_RIFLE)) ||
		!(gui->pistol_gui = IMG_Load(GUI_PISTOL)))
		error("Can't load gui.");
}
