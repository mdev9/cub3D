/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:31:23 by marde-vr          #+#    #+#             */
/*   Updated: 2024/04/10 17:07:51 by axdubois         ###   ########.fr       */
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

int	mousedown_event(int keycode, void *game_data)
{
	t_game	*game;

	game = (t_game *)game_data;
	// ft_printf("%d\n", keycode);
	if (keycode == 1)
		game->player->vect->use_mouse = !game->player->vect->use_mouse;
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
	mlx_clear_window(game->mlx, game->mlx_win);
	if (game->ray->is_d_map)
		display_large_map(game, 0, 0);
	else
		render_map(game);
}

void	change_player_pos(int keycode, t_game *game)
{
	double	speedx;
	double	speedy;
	
	if (keycode == 26)
	{
		speedx = SPEED * cos(game->player->vect->angle * PI / 180);
		speedy = SPEED * -sin(game->player->vect->angle * PI / 180);
	}
	else if (keycode == 22)
	{
		speedx = SPEED * -cos(game->player->vect->angle * PI / 180);
		speedy = SPEED * sin(game->player->vect->angle * PI / 180);
	}
	else if (keycode == 7)
	{
		speedx = SPEED * cos(game->player->vect->angle * PI / 180);
		speedy = SPEED * sin(game->player->vect->angle * PI / 180);
	}
	else
	{
		speedx = SPEED * -cos(game->player->vect->angle * PI / 180);
		speedy = SPEED * sin(game->player->vect->angle * PI / 180);
	}
	// printf ("speedx = %f\t speedy = %f\n", speedx, speedy);
	if (speedy >= game->map_size ||
		!game->map[(int)(game->player->y + speedy)][(int)(game->player->x + speedx)] ||
		game->map[(int)(game->player->y + speedy)][(int)(game->player->x + speedx)] == '1')
			return ;
	game->player->x += speedx;
	game->player->y += speedy;
	// printf ("posx = %f\t posy = %f\n", game->player->x, game->player->y);
	mlx_clear_window(game->mlx, game->mlx_win);
	if (game->ray->is_d_map)
		display_large_map(game, 0, 0);
	else
		render_map(game);
}
void	change_angle(int keycode, t_game *game)
{
	// printf ("angle = %d\n", game->player->vect->angle);
	if (keycode == 79)
		game->player->vect->angle = (game->player->vect->angle + 5) % 360;
	else if (keycode == 80)
		game->player->vect->angle -= 5;
	if (game->player->vect->angle < 0)
		game->player->vect->angle = 360 + game->player->vect->angle;
	mlx_clear_window(game->mlx, game->mlx_win);
	if (game->ray->is_d_map)
		display_large_map(game, 0, 0);
	else
		render_map(game);
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
	{
		// if (game->ray->is_d_map)
		// 	change_player_pos_in_map(keycode, game);
		// else
			change_player_pos(keycode, game);	
	}
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
