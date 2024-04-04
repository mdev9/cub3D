/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:31:23 by marde-vr          #+#    #+#             */
/*   Updated: 2024/04/04 19:52:06 by axdubois         ###   ########.fr       */
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
void	change_player_pos(int keycode,t_game *game)
{
	if (keycode == 22)
	{
		if (game->map[(int)game->player->y][(int)(game->player->x + 0.3)] != '1')
			game->player->x += 0.3;
	}
	else if (keycode == 26)
	{
		if (game->map[(int)game->player->y][(int)(game->player->x - 0.3)] != '1')
			game->player->x -= 0.3;
	}
	else if (keycode == 7)
	{
		if (game->map[(int)(game->player->y + 0.3)][(int)game->player->x] != '1')
			game->player->y += 0.3;
	}
	else if (keycode == 4)
	{
		if (game->map[(int)(game->player->y - 0.3)][(int)game->player->x] != '1')
			game->player->y -= 0.3;
	}
	render_map(game);
}
void	change_angle(int keycode,t_game *game)
{
	if (keycode == 79)
		game->player->vect->angle =( game->player->vect->angle + 10) % 360;
	else if (keycode == 80)
		game->player->vect->angle -= 10;
	if (game->player->vect->angle < 0)
		game->player->vect->angle = 360 + game->player->vect->angle;
	if (keycode == 16)
	render_map(game);
}

int	keydown_event(int keycode, void *game_data)
{
	t_game	*game;

	game = (t_game *)game_data;
	ft_printf("%d\n", keycode);
	if (keycode == 41)
		exit_game(game, 0);
	if (keycode == 79 || keycode == 80)
		change_angle(keycode, game);
	if (keycode == 26 || keycode == 4 || keycode == 22 || keycode == 7)
		change_player_pos(keycode, game);
	return (0);
}
