/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:38:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 10:38:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wolf_inc.h"

void	load_doom_walls_utils_1(t_textures *t, int i, int j)
{
	if (i == 0 && j == 4)
		t->metal_wall_1 = create_surface(t->doom_walls, i, j);
	if (i == 6 && j == 1)
		t->metal_wall_3 = create_surface(t->doom_walls, i, j);
	else if (i == 2 && j == 4)
		t->computer = create_surface(t->doom_walls, i, j);
	else if (i == 3 && j == 6)
		t->metal_wall_stripe = create_surface(t->doom_walls, i, j);
	else if (i == 4 && j == 3)
		t->brick_wall = create_surface(t->doom_walls, i, j);
	else if (i == 4 && j == 5)
		t->pipe_wall = create_surface(t->doom_walls, i, j);
	else if (i == 6 && j == 4)
		t->metal_wall_2 = create_surface(t->doom_walls, i, j);
}

void	load_doom_walls(t_textures *t)
{
	int			i;
	int			j;

	if (!(t->doom_walls = IMG_Load(DOOM_WALLS)))
		error("Can't load doom walls textures.");
	i = -1;
	while (++i < 7)
	{
		j = -1;
		while (++j < 8)
			load_doom_walls_utils_1(t, i, j);
	}
}

void	load_wolf_walls_utils_1(t_textures *t, int i, int j)
{
	if (i == 0 && j == 0)
		t->greystone = create_surface(t->walls, i, j);
	else if (i == 2 && j == 4)
		t->bluestone = create_surface(t->walls, i, j);
	else if (i == 2 && j == 0)
		t->prison_f_bluestone = create_surface(t->walls, i, j);
	else if (i == 1 && j == 2)
		t->prison_bluestone = create_surface(t->walls, i, j);
	else if (i == 3 && j == 4)
		t->wood = create_surface(t->walls, i, j);
	else if (i == 3 && j == 2)
		t->hitler_wood = create_surface(t->walls, i, j);
	else if (i == 5 && j == 2)
		t->redbrick = create_surface(t->walls, i, j);
}

void	load_wolf_walls_utils_2(t_textures *t, int i, int j)
{
	if (i == 5 && j == 4)
		t->nazi_redbrick = create_surface(t->walls, i, j);
	else if (i == 6 && j == 2)
		t->eagle_w = create_surface(t->walls, i, j);
	else if (i == 6 && j == 0)
		t->purplestone = create_surface(t->walls, i, j);
	else if (i == 8 && j == 2)
		t->mossy_w = create_surface(t->walls, i, j);
	else if (i == 12 && j == 2)
		t->colorstone = create_surface(t->walls, i, j);
	else if (i == 1 && j == 0)
		t->gitler_greystone = create_surface(t->walls, i, j);
	else if (i == 0 && j == 4)
		t->nazi_greystone = create_surface(t->walls, i, j);
}

void	load_wolf_walls(t_textures *t)
{
	int			i;
	int			j;

	if (!(t->walls = IMG_Load(WALLS)))
		error("Can't load wolf walls textures.");
	i = -1;
	while (++i < 19)
	{
		j = -1;
		while (++j < 6)
		{
			load_wolf_walls_utils_1(t, i, j);
			load_wolf_walls_utils_2(t, i, j);
		}
	}
}
