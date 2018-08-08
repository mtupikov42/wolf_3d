/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:57:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/05/28 17:57:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wolf_inc.h"

void	put_text_to_font(t_sdl *sdl, TTF_Font *font, char *line, Uint8 k[3])
{
	sdl->text = TTF_RenderText_Solid(font, line,
	(SDL_Color){k[0], k[1], k[2], 255});
}

void	put_info(t_sdl *sdl, char *font, char *text, int k[6])
{
	if (!(sdl->font = TTF_OpenFont(font, k[2])))
		error((char *)TTF_GetError());
	put_text_to_font(sdl, sdl->font, text, (Uint8[]){k[3], k[4], k[5]});
	SDL_BlitSurface(sdl->text, NULL, sdl->screen,
					&(SDL_Rect){k[0], k[1], 20, 20});
	TTF_CloseFont(sdl->font);
	SDL_FreeSurface(sdl->text);
}
