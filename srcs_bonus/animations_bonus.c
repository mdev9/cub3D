/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:21:55 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/02 13:47:43 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	color_is_from_wall(int color)
{
	if (color == 0x00000000 || color == 0x00110000
		|| color == 0x00112200 || color == 0x00112233)
		return (0);
	return (1);
}

int	get_current_animation_color(t_game *game)
{
	if (!(game->loop_nb % 30))
	{
		if (game->current_animation_color == 0x00110000)
			game->current_animation_color = 0x00112200;
		else if (game->current_animation_color == 0x00112200)
			game->current_animation_color = 0x00112233;
		else if (game->current_animation_color == 0x00112233)
			game->current_animation_color = 0x00110000;
	}
	return (game->current_animation_color);
}
