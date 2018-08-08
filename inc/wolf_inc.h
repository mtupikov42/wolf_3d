/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_inc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 14:56:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/11 14:56:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_INC_H
# define WOLF_INC_H

/*
**	INCLUDES
*/

# include <SDL.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <OpenCL/opencl.h>
# include "SDL_image.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"
# include "SDL_net.h"
# include <math.h>
# include <time.h>

/*
**	DEFINES
*/

# define UNIT_INTRO		"textures/menu/unit_intro.png"
# define MENU_BG		"textures/menu/menu_bg.png"
# define SELECT_BG		"textures/menu/select_map_bg.png"

# define BUSH_WALL		"textures/walls/bush_wall.png"
# define GRASS			"textures/walls/grass.png"
# define WALLS			"textures/walls/walls.png"
# define DOOM_WALLS		"textures/walls/doomwalls.png"
# define UNIT_WALLS		"textures/walls/unit_walls.png"

# define MAZE_BG		"textures/bg/labyrinth_bg.png"

# define BARREL			"textures/sprites/barrel.png"
# define PILLAR			"textures/sprites/pillar.png"
# define GLIGHT			"textures/sprites/greenlight.png"
# define MEDPACK		"textures/sprites/medpack.png"
# define AMMO			"textures/sprites/ammo.png"
# define TABLE			"textures/sprites/table.png"
# define TOILET			"textures/sprites/toilet.png"
# define D_BARREL		"textures/sprites/doom_barrel.png"
# define D_BOX			"textures/sprites/doom_box.png"
# define D_WTF			"textures/sprites/doom_wtf.png"
# define FLOOR_LIGHT	"textures/sprites/floor_light.png"
# define PORTAL			"textures/sprites/portal.png"
# define CHAIR			"textures/sprites/chair.png"
# define TIZH			"textures/sprites/tizh.png"

# define WOLF_ICON		"textures/icons/wolf_icon.png"
# define WOLF_ICON_P	"textures/icons/wolf_icon_p.png"
# define TEST_ICON		"textures/icons/test_icon.png"
# define TEST_ICON_P	"textures/icons/test_icon_p.png"
# define MAZE_ICON		"textures/icons/maze_icon.png"
# define MAZE_ICON_P	"textures/icons/maze_icon_p.png"
# define DOOM_ICON		"textures/icons/doom_icon.png"
# define DOOM_ICON_P	"textures/icons/doom_icon_p.png"
# define UNIT_ICON		"textures/icons/unit_icon.png"
# define UNIT_ICON_P	"textures/icons/unit_icon_p.png"

# define GUI_INTERFACE	"textures/gui/gui.png"
# define GUI_RIFLE		"textures/gui/rifle_gui.png"
# define GUI_PISTOL		"textures/gui/pistol_gui.png"
# define GUI_BJ			"textures/gui/bj_gui.png"

# define WOLF_SOLD		"textures/enemies/wolf_guard.png"
# define DOOM_SOLD		"textures/enemies/doom_guard.png"
# define UNIT_SOLD		"textures/enemies/unit_guard.png"

# define RIFLE			"textures/guns/rifle.png"
# define PISTOL			"textures/guns/pistol.png"

# define WOLF_C			"maps/wolf_classic"
# define TEST_C			"maps/test_map"
# define LABYRINTH_C	"maps/labyrinth"
# define DOOM_C			"maps/doom_map"
# define UNIT_C			"maps/unit_map"

# define WOLF_FONT		"fonts/return.ttf"

# define SCREEN_WIDTH	1920
# define SCREEN_HEIGHT	1080

# define TRUE			1
# define FALSE			0

# define T_INTER		1
# define T_NOINTER		2
# define T_PICKABLE		3

# define DEAD			0
# define ALIVE			1

# define KILL_ALL		1
# define FIND_EXIT		2
# define PICK_ALL		3

# define NOTHING		0
# define WALL			1
# define SPRITE			2
# define ENEMY			3
# define WALL4			4
# define WALL_SYMB		"|+-"
# define PLAYER_SYMB	'P'
# define SPRITE_SYMB	'S'
# define ENEMY_SYMB		'E'

# define G_NOTHING		0
# define G_PISTOL		1
# define G_RIFLE		3

# define S_MEDPACK		1
# define S_AMMO			2
# define S_PICK			3

/*
**	STRUCTS
*/

typedef struct			s_sprite
{
	int					type;
	int					sp_type;
	int					picked;
	int					x;
	int					y;
}						t_sprite;

typedef struct			s_map_cell
{
	int					type;
	SDL_Surface			*texture;
	t_sprite			sprite;
	int					len;
	int					end;
}						t_map_cell;

typedef struct			s_render
{
	double				old_dir_x;
	double				old_plane_x;
	double				move_speed;
	double				rot_speed;
	double				old_time;
	double				new_time;
	double				frame_time;
	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_wall_dist;
	double				wall_x;
	double				floor_x_wall;
	double				floor_y_wall;
	double				dist_wall;
	double				dist_player;
	double				current_dist;
	double				weight;
	double				current_floor_x;
	double				current_floor_y;
	double				sprite_x;
	double				sprite_y;
	double				inv_det;
	double				tr_x;
	double				tr_y;
	int					sprite_height;
	int					draw_start_y;
	int					draw_start_x;
	int					floor_tex_x;
	int					floor_tex_y;
	int					tex_x;
	int					line_height;
	int					draw_start;
	int					draw_end;
	int					side;
	int					step_x;
	int					step_y;
	int					map_x;
	int					map_y;
	int					j;
	int					i;
	int					t;
}						t_render;

typedef struct			s_enemy
{
	double				health;
	double				pos_x;
	double				pos_y;
	double				dx;
	double				dy;
	double				dist;
	double				damage;
	int					dist_radius;
	int					status;
	int					walking;
	int					fire;
	SDL_Surface			*texture;
	SDL_Rect			*walk_anim;
	SDL_Rect			*fire_anim;
	SDL_Rect			*stand_anim;
	SDL_Rect			*death_anim;
	Mix_Chunk			*fire_sound;
	Mix_Chunk			*s_sound;
	Mix_Chunk			*death_sound;
}						t_enemy;

typedef struct			s_player
{
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				health;
}						t_player;

typedef struct			s_map
{
	int					has_guns;
	int					map_height;
	int					enemy_count;
	int					has_ceiling;
	int					map_type;
	double				plane_x;
	double				plane_y;
	t_player			player;
	t_map_cell			**map;
	SDL_Surface			*ceiling;
	SDL_Surface			*floor;
	SDL_Surface			*bg;
	t_enemy				enemies[100];
}						t_map;

typedef struct			s_mouse
{
	int					new_x;
	int					new_y;
}						t_mouse;

typedef struct			s_gui
{
	int					gun_type;
	int					gr_r;
	int					fire;
	int					minimap;
	int					rifle_ammo;
	int					pistol_ammo;
	int					*ammo;
	int					x_draw;
	int					y_draw;
	int					x_draw_m;
	int					y_draw_m;
	int					x_go_to;
	int					y_go_to;
	double				fire_damage;
	Mix_Chunk			*fire_sound;
	SDL_Surface			*texture;
	SDL_Rect			*walk_anim;
	SDL_Rect			*fire_anim;
	SDL_Surface			*gui_interface;
	SDL_Surface			*rifle_gui;
	SDL_Surface			*pistol_gui;
	SDL_Surface			*blaz_face;
}						t_gui;

typedef struct			s_media
{
	Mix_Chunk			*wolf_s_death;
	Mix_Chunk			*wolf_s_fire;
	Mix_Chunk			*wolf_p_in_s;
	Mix_Chunk			*doom_g_death;
	Mix_Chunk			*doom_g_fire;
	Mix_Chunk			*doom_p_in_s;
	Mix_Music			*doom_map_music;
	Mix_Chunk			*rifle_fire;
	Mix_Chunk			*pistol_fire;
	Mix_Chunk			*pickup;
	Mix_Music			*wolf_map_music;
	Mix_Chunk			*menu_select;
	Mix_Music			*menu_music;
}						t_media;

typedef struct			s_textures
{
	SDL_Surface			*menu_bg;
	SDL_Surface			*unit_intro;
	SDL_Surface			*select_map_bg;
	SDL_Surface			*walls;
	SDL_Surface			*greystone;
	SDL_Surface			*wood;
	SDL_Surface			*hitler_wood;
	SDL_Surface			*bluestone;
	SDL_Surface			*prison_bluestone;
	SDL_Surface			*prison_f_bluestone;
	SDL_Surface			*purplestone;
	SDL_Surface			*eagle_w;
	SDL_Surface			*redbrick;
	SDL_Surface			*nazi_redbrick;
	SDL_Surface			*colorstone;
	SDL_Surface			*mossy_w;
	SDL_Surface			*gitler_greystone;
	SDL_Surface			*nazi_greystone;
	SDL_Surface			*doom_walls;
	SDL_Surface			*brick_wall;
	SDL_Surface			*metal_wall_1;
	SDL_Surface			*metal_wall_2;
	SDL_Surface			*metal_wall_3;
	SDL_Surface			*computer;
	SDL_Surface			*metal_wall_stripe;
	SDL_Surface			*pipe_wall;
	SDL_Surface			*unit_walls;
	SDL_Surface			*unit_wall;
	SDL_Surface			*unit_ceiling;
	SDL_Surface			*unit_floor;
	SDL_Surface			*tizh;
	SDL_Surface			*barrel;
	SDL_Surface			*pillar;
	SDL_Surface			*glight;
	SDL_Surface			*table;
	SDL_Surface			*toilet;
	SDL_Surface			*rifle;
	SDL_Surface			*wolf_sold;
	SDL_Surface			*test_icon[2];
	SDL_Surface			*wolf_icon[2];
	SDL_Surface			*maze_icon[2];
	SDL_Surface			*doom_icon[2];
	SDL_Surface			*unit_icon[2];
	SDL_Surface			*bush_wall;
	SDL_Surface			*grass;
	SDL_Surface			*maze_bg;
	SDL_Surface			*medpack;
	SDL_Surface			*ammo;
	SDL_Surface			*pistol;
	SDL_Surface			*chair;
	SDL_Surface			*doom_barrel;
	SDL_Surface			*doom_box;
	SDL_Surface			*doom_wtf;
	SDL_Surface			*floor_light;
	SDL_Surface			*portal;
	SDL_Surface			*doom_g;
	SDL_Surface			*unit_g;
	SDL_Rect			doom_g_s;
	SDL_Rect			doom_g_go[4];
	SDL_Rect			doom_g_fire[4];
	SDL_Rect			doom_g_dead;
	SDL_Rect			wolf_s_s;
	SDL_Rect			wolf_s_go[4];
	SDL_Rect			wolf_s_fire[4];
	SDL_Rect			wolf_s_dead;
	SDL_Rect			unit_g_s;
	SDL_Rect			unit_g_go[4];
	SDL_Rect			unit_g_fire[4];
	SDL_Rect			unit_g_dead;
	SDL_Rect			rifle_go;
	SDL_Rect			rifle_fire[2];
	SDL_Rect			pistol_go;
	SDL_Rect			pistol_fire[2];
}						t_textures;

typedef struct			s_sdl
{
	int					quit;
	SDL_Window			*window;
	SDL_Surface			*screen;
	SDL_Surface			*text;
	TTF_Font			*font;
	SDL_Event			event;
	int					keys[300];
	t_render			render;
	t_map				map;
	t_mouse				mouse;
	t_textures			textures;
	t_gui				gui;
	t_media				media;
}						t_sdl;

/*
**	PROTOTYPES
*/

/*
**	main.c
*/

void					error(const char *reason);
void					main_loop(t_sdl *sdl);

/*
**	main_utils_1.c
*/

void					check_cell(t_sdl *sdl, t_map_cell *cell);
void					enemy_ai(t_sdl *sdl);
int						check_enemy_minimap(t_sdl *sdl, int x, int y);

/*
**	main_utils_2.c
*/

void					draw_minimap(t_sdl *sdl);
void					check_mouse(t_sdl *sdl);
SDL_Surface				*create_surface(SDL_Surface	*walls, int i, int j);

/*
**	main_utils_3.c
*/

void					choose_gun(t_sdl *sdl, int n);
void					main_loop_events_util_1(t_sdl *sdl);
void					main_loop_events_util_2(t_sdl *sdl);
void					main_loop_events_util_3_1(t_sdl *sdl);

/*
**	main_utils_4.c
*/

void					main_loop_events_util_3(t_sdl *sdl);
void					main_loop_events_util_4(t_sdl *sdl);
void					draw_face(t_sdl *sdl, int j);
void					draw_gun(t_sdl *sdl);
int						all_enemies_are_dead(t_sdl *sdl);

/*
**	main_utils_5.c
*/

void					draw_gui(t_sdl *sdl);
void					you_died(t_sdl *sdl);
void					you_win(t_sdl *sdl);
int						check_picked_all(t_sdl *sdl);

/*
**	main_utils_6.c
*/

void					animate_gun(t_sdl *sdl);
void					animate_fade_out(t_sdl *sdl, SDL_Surface *s,
							int rate);
void					animate_fade_in(t_sdl *sdl, SDL_Surface *s,
										int rate);
int						check_exit(t_sdl *sdl);

/*
**	load_all.c
*/

void					load_all(t_sdl *sdl);

/*
**	load_utils_1.c
*/

void					load_doom_g_animations(t_textures *t);
void					load_icons(t_textures *textures);
void					load_unit_g_animations(t_textures *t);

/*
**	load_utils_2.c
*/

void					load_doom_walls(t_textures *t);
void					load_wolf_walls(t_textures *t);

/*
**	load_utils_3.c
*/

void					load_textures(t_textures *t);
void					load_media(t_media *media);
void					load_gui(t_gui *gui);

/*
**	parse_main.c
*/

void					parse_map(t_map *map, char *name);
void					parse_map_textures(t_sdl *sdl, char *name);

/*
**	parser_utils_1.c
*/

void					parse_map_textures_util_1(t_sdl *sdl, int i, int j,
													const char *line);
void					parse_map_textures_util_2(t_sdl *sdl, int i, int j,
													const char *line);
void					parse_map_textures_util_3(t_sdl *sdl, int i, int j,
													const char *line);
void					parse_map_textures_util_4(t_sdl *sdl, int i, int j,
													const char *line);
void					parse_map_textures_util_5(t_sdl *sdl, int i, int j,
													const char *line);

/*
**	parser_utils_2.c
*/

void					parse_map_textures_util_6(t_sdl *sdl, int i, int j,
													const char *line);
void					parse_map_textures_util_7(t_sdl *sdl, int i, int j,
													const char *line);
void					parse_map_textures_util_8(t_sdl *sdl, int i, int j,
													const char *line);
void					parse_map_textures_util_9(t_sdl *sdl, int i, int j,
													const char *line);
void					parse_map_textures_util_10(t_sdl *sdl, int i, int j,
													const char *line);

/*
**	parser_utils_3.c
*/

int						check_player(t_map *map);

/*
**	render_utils_1.c
*/

void					put_pixel(t_sdl *sdl, SDL_Surface *floor,
						SDL_Surface *ceiling, const int k[5]);
void					put_pixels_in_line(t_sdl *sdl, const int k[6],
						SDL_Surface *texture);
void					draw_sprite(t_sdl *sdl, SDL_Surface *texture, int x);
void					sprite_rend(t_sdl *sdl, int j);

/*
**	render_utils_2.c
*/

void					draw_enemy(t_sdl *sdl, t_enemy *enemy, int x);
void					draw_ceiling_floor(t_sdl *sdl);
SDL_Surface				*choose_wall(t_sdl *sdl);

/*
**	render_utils_3.c
*/

void					draw_walls(t_sdl *sdl);
void					draw_camera(t_sdl *sdl);
double					dot_prod(double x1, double y1, double x2, double y2);

/*
**	sdl_init.c
*/

int						init_sdl(t_sdl *sdl);

/*
**	sdl_utils.c
*/

void					put_info(t_sdl *sdl, char *font, char *text, int k[3]);

/*
**	main_render.c
*/

void					main_render(t_sdl *sdl);

/*
**	menu.c
*/

void					menu_loop(t_sdl *sdl);

/*
**	menu_utils_1.c
*/

void					default_player(t_sdl *sdl);
void					put_menu_info(t_sdl *sdl, int x, int y);
void					put_maps_info(t_sdl *sdl, int x, int y);
char					*select_map_events_util_1(t_sdl *sdl, int x, int y);

/*
**	menu_utils_2.c
*/

char					*main_menu_events(t_sdl *sdl);

#endif
