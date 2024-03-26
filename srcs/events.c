/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:31:23 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/26 18:06:52 by axdubois         ###   ########.fr       */
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

int	keydown_event(int keycode, void *game)
{
	t_game *s_game;

	s_game = (t_game *)game;
	ft_printf("%d\n", keycode);
	if (keycode == 41)
		exit_game(s_game, 0);
	else if (keycode == 79)
		s_game->player->vect->x += 10.0;
	else if (keycode == 80)
		s_game->player->vect->x -= 10.0;
	else if (keycode == 81)
		s_game->player->vect->y += 10.0;
	else if (keycode == 82)
		s_game->player->vect->y -= 10.0;
	ft_printf("x\ty\n%i\t%i\n",s_game->player->vect->y, s_game->player->vect->x);
	return (0);
}
