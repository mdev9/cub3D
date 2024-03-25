/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:21:13 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:56 by marde-vr         ###   ########.fr       */
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

void	load_textures(t_game *game)
{
	char *texture_path;

	game->width = ft_calloc(1, sizeof(int));
	game->height = ft_calloc(1, sizeof(int));
	ft_printf("load_texture: %s\n", game->texture->no);
	texture_path = game->texture->no;
	free(game->texture->no);
	game->texture->no = mlx_png_file_to_image(game->mlx,
		texture_path, game->width, game->height);
	game->texture->so = mlx_png_file_to_image(game->mlx,
		game->texture->so, game->width, game->height);
	game->texture->we = mlx_png_file_to_image(game->mlx,
		game->texture->we, game->width, game->height);
	game->texture->ea = mlx_png_file_to_image(game->mlx,
		game->texture->ea, game->width, game->height);
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	load_textures(game);
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
	init_game(game);
}
