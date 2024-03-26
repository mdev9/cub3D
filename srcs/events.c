/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:31:23 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/26 17:22:41 by axdubois         ###   ########.fr       */
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
	ft_printf("%d\n", keycode);
	if (keycode == 41)
		exit_game(game, 0);
	else if (keycode == 79)
		((t_game *)game)->player->vect->x += 10;
	else if (keycode == 80)
		((t_game *)game)->player->vect->x -= 10;
	else if (keycode == 81)
		((t_game *)game)->player->vect->y += 10;
	else if (keycode == 82)
		((t_game *)game)->player->vect->y -= 10;
	ft_printf("x\ty\n%i\t%i\n",((t_game *)game)->player->vect->y, ((t_game *)game)->player->vect->x);
	return (0);
}
