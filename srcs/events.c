/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:31:23 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/01 13:56:32 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	window_event(int value, void *game)
{
	t_game	*s_game;

	s_game = (t_game *)game;
	if (value == 0)
		exit_game(s_game, 0);
	return (0);
}

void	change_angle(int keycode, t_game *game)
{
	if (keycode == 79)
		game->player->vect->angle = (game->player->vect->angle + ROTPSEED)
			% 360;
	else if (keycode == 80)
		game->player->vect->angle -= ROTPSEED;
	if (game->player->vect->angle < 0)
		game->player->vect->angle = 360 + game->player->vect->angle;
}

int	keydown_event(int keycode, void *game_data)
{
	t_game	*game;

	game = (t_game *)game_data;
	if (keycode == 41)
		exit_game(game, 0);
	else if (keycode == 79)
		game->input[4] = 1;
	else if (keycode == 80)
		game->input[5] = 1;
	else if (keycode == 26)
		game->input[0] = 1;
	else if (keycode == 22)
		game->input[1] = 1;
	else if (keycode == 7)
		game->input[2] = 1;
	else if (keycode == 4)
		game->input[3] = 1;
	return (0);
}

int	keydown_eventup(int keycode, void *game_data)
{
	t_game	*game;

	game = (t_game *)game_data;
	if (keycode == 41)
		exit_game(game, 0);
	else if (keycode == 79)
		game->input[4] = 0;
	else if (keycode == 80)
		game->input[5] = 0;
	else if (keycode == 26)
		game->input[0] = 0;
	else if (keycode == 22)
		game->input[1] = 0;
	else if (keycode == 7)
		game->input[2] = 0;
	else if (keycode == 4)
		game->input[3] = 0;
	return (0);
}
