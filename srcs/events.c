/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:31:23 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/27 10:03:44 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	window_event(int value, void *game)
{
	t_game *s_game;

	s_game = (t_game *)game;
	if (value == 0)
		exit_game(s_game, 0);
	return (0);
}

int	keydown_event(int keycode, void *game_data)
{
	t_game *game;

	game = (t_game *)game_data;
	// ft_printf("%d\n", keycode);
	if (keycode == 41)
		exit_game(game, 0);
	else if (keycode == 79)
		game->player->vect->x += 10.0;
	else if (keycode == 80)
		game->player->vect->x -= 10.0;
	else if (keycode == 81)
		game->player->vect->y += 10.0;
	else if (keycode == 82)
		game->player->vect->y -= 10.0;
	render_map(game);
	// ft_printf("x\ty\n%i\t%i\n",game->player->vect->y, game->player->vect->x);
	return (0);
}
