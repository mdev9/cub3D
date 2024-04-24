/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:59:36 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/24 13:01:05 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(void *s_game)
{
	t_game	*game;

	game = (t_game *) s_game;
	if (game->player->vect->use_mouse && !game->ray->is_d_map)
		change_by_mouse(game);
	check_input_touch(game);
	render_by_view(game);
	return (0);
}

void	init_ray(t_game *game)
{
	game->ray = ft_calloc(sizeof(t_raycaster), 1);
	if (!game->ray)
		exit_game(game, 0);
	game->ray->planex = 0;
	game->ray->planey = 0.66;
}

void	init_input(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < 6)
		game->input[i] = 0;
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	load_textures(game);
	game->mlx_win = mlx_new_window(game->mlx, WIDTH,
			HEIGHT, "cub3D");
	mlx_mouse_hide();
	init_ray(game);
	init_mouse(game);
	init_input(game);
	if (!game->player->vect->use_mouse)
		set_img(game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_on_event(game->mlx, game->mlx_win, MLX_KEYDOWN, keydown_event, game);
	mlx_on_event(game->mlx, game->mlx_win, MLX_KEYUP, keydown_eventup, game);
	mlx_on_event(game->mlx, game->mlx_win, MLX_MOUSEDOWN,
		mousedown_event, game);
	mlx_on_event(game->mlx, game->mlx_win,
		MLX_WINDOW_EVENT, window_event, game);
	mlx_loop(game->mlx);
	return (0);
}
