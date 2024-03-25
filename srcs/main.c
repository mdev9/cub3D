/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:21:13 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/25 13:26:55 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(void *s_game)
{
	t_game	*game;

	game = (t_game *) s_game;
	(void)game;
	return (0);
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 1920, 1080, "cub3D");
	render_map(game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_on_event(game->mlx, game->mlx_win, MLX_KEYDOWN, keydown_event, game);
	mlx_on_event(game->mlx, game->mlx_win, MLX_WINDOW_EVENT, window_event,
		game);
	mlx_loop(game->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		exit(1);
	check_input_validity(ac, av);
	check_map_validity(game, av[1]);
	game->vect = ft_calloc(sizeof(t_vect),1);
	if (game->vect);
		return (1);
	init_game(game);
}
