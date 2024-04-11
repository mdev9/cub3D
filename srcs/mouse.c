/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:55:01 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/11 09:59:15 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mouse(t_game *game)
{
	int	x;
	int	y;

	game->mouse = ft_calloc(1, sizeof(t_mouse));
	if (!game->mouse)
		exit_game(game, 0);
	mlx_mouse_get_pos(game->mlx, &x, &y);
	game->mouse->x = x;
	game->mouse->y = y;
}

void	change_by_mouse(t_game *game)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(game->mlx, &x, &y);
	if (game->mouse->x == x)
		return ;
	game->mouse->x = x;
	game->mouse->y = y;
	game->player->vect->angle += (int)((game->mouse->x - WIDTH / 2)) % 360 / 15;
	if (game->player->vect->angle < 0)
		game->player->vect->angle = 360 + game->player->vect->angle;
	else
		game->player->vect->angle %= 360;
	mlx_mouse_move(game->mlx, game->mlx_win, WIDTH / 2, HEIGHT / 2);
	render_map(game);
}

int	mousedown_event(int keycode, void *game_data)
{
	t_game	*game;

	game = (t_game *)game_data;
	// ft_printf("%d\n", keycode);
	if (keycode == 1)
		game->player->vect->use_mouse = !game->player->vect->use_mouse;
	return (0);
}
