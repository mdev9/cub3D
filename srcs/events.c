/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:31:23 by marde-vr          #+#    #+#             */
/*   Updated: 2024/04/09 13:47:06 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	display_large_map(t_game *game, int x, int y);

int	window_event(int value, void *game)
{
	t_game	*s_game;

	s_game = (t_game *)game;
	if (value == 0)
		exit_game(s_game, 0);
	return (0);
}

void	change_player_pos_in_map(int keycode, t_game *game)
{
	if (keycode == 7)
	{
		if (game->map[(int)game->player->y][(int)(game->player->x + SPEED)]
			!= '1')
			game->player->x += SPEED;
	}
	else if (keycode == 4)
	{
		if (game->map[(int)game->player->y][(int)(game->player->x - SPEED)]
			!= '1')
			game->player->x -= SPEED;
	}
	else if (keycode == 22)
	{
		if (game->map[(int)(game->player->y + SPEED)][(int)game->player->x]
			!= '1')
			game->player->y += SPEED;
	}
	else if (keycode == 26)
	{
		if (game->map[(int)(game->player->y - SPEED)][(int)game->player->x]
			!= '1')
			game->player->y -= SPEED;
	}
	if (game->ray->is_d_map)
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		display_large_map(game, 0, 0);
	}
	else
		render_map(game);
}

void	put_player(t_game *game, int playerx, int playery)
{
	int	x;
	int	y;

	x = -1;
	while (++x < 5)
	{
		y = -1;
		while (++y < 5)
			mlx_pixel_put(game->mlx, game->mlx_win, playerx * 32 + x + 16
				+ WIDTH / 4, playery * 32 + y + 16 + HEIGHT / 4, 0xFF0000FF);
	}
}

void	put_mapwall(t_game *game, int wall_x, int wall_y)
{
	int	x;
	int	y;

	x = -1;
	while (++x < 32)
	{
		y = -1;
		while (++y < 32)
			mlx_pixel_put(game->mlx, game->mlx_win, wall_x * 32 + x + WIDTH / 4,
				wall_y * 32 + y + HEIGHT / 4, 0xFF00A300);
	}
}

int	display_large_map(t_game *game, int x, int y)
{
	if (y >= game->map_size)
		return (1);
	if (game->map[y][x] == '1')
		put_mapwall(game, x, y);
	else if (y == (int) game->player->y && x == (int) game->player->x)
		put_player(game, x, y);
	if (!game->map[y][x])
		display_large_map(game, 0, y + 1);
	else
		display_large_map(game, x + 1, y);
	return (0);
}


void	change_angle(int keycode, t_game *game)
{
	if (keycode == 79)
		game->player->vect->angle = (game->player->vect->angle + 5) % 360;
	else if (keycode == 80)
		game->player->vect->angle -= 5;
	if (game->player->vect->angle < 0)
		game->player->vect->angle = 360 + game->player->vect->angle;
	if (game->ray->is_d_map)
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		display_large_map(game, 0, 0);
	}
	else
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

int	keydown_event(int keycode, void *game_data)
{
	t_game	*game;

	game = (t_game *)game_data;
	// ft_printf("%d\n", keycode);
	if (keycode == 41)
		exit_game(game, 0);
	else if (keycode == 79 || keycode == 80)
		change_angle(keycode, game);
	else if (keycode == 26 || keycode == 4 || keycode == 22 || keycode == 7)
		change_player_pos_in_map(keycode, game);
	else if (keycode == 16)
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		game->ray->is_d_map = !game->ray->is_d_map;
		if (game->ray->is_d_map)
			display_large_map(game, 0, 0);
		else
			render_map(game);
	}
	return (0);
}
