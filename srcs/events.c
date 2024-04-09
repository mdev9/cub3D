/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:31:23 by marde-vr          #+#    #+#             */
/*   Updated: 2024/04/09 17:38:23 by axdubois         ###   ########.fr       */
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
// double	speedtoangle(int keycode, t_game *game, int axe)
// {
	
// 	return (radian);
// }

void	change_player_pos(int keycode, t_game *game)
{
	double	speedx;
	double	speedy;
	
	(void) keycode;
	speedx = SPEED * cos(game->player->vect->angle);// speedtoangle(keycode, game, 1);
	speedy = SPEED * sin(game->player->vect->angle);// speedtoangle(keycode, game, 0);
	printf ("speedx = %f\t speedy = %f\n", speedx, speedy);
	// printf ("speedx = %d\t speedy = %f\n", speedx, speedy);
	if (speedy > game->map_size ||
		!game->map[(int)(game->player->y + speedx)][(int)(game->player->x + speedy)] ||
		game->map[(int)(game->player->y + speedx)][(int)(game->player->x + speedy)] == '1')
		return ;
	game->player->y += speedx;
	game->player->y += speedy;
	mlx_clear_window(game->mlx, game->mlx_win);
	if (game->ray->is_d_map)
		display_large_map(game, 0, 0);
	else
		render_map(game);
}
void	change_angle(int keycode, t_game *game)
{
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
		if (game->ray->is_d_map)
			change_player_pos_in_map(keycode, game);
		else
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
