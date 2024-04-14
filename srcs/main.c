/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:21:13 by marde-vr          #+#    #+#             */
/*   Updated: 2024/04/14 11:50:32 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(t_game *game, void **texture)
{
	char	*texture_path;

	texture_path = ft_strdup(*texture);
	if (!texture_path)
		exit_game(game, 0);
	free(*texture);
	*texture = mlx_png_file_to_image(game->mlx,
			texture_path, game->texture->width, game->texture->height);
	free(texture_path);
	if (!*texture)
		exit_game(game, "Error\nInvalid or missing texture!\n");
}

void	load_textures(t_game *game)
{
	game->texture->width = ft_calloc(1, sizeof(int));
	game->texture->height = ft_calloc(1, sizeof(int));
	if (!game->texture->width || !game->texture->height)
		exit_game(game, 0);
	load_texture(game, &game->texture->no);
	load_texture(game, &game->texture->so);
	load_texture(game, &game->texture->we);
	load_texture(game, &game->texture->ea);
}

int	game_loop(void *s_game)
{
	t_game	*game;

	game = (t_game *) s_game;
	if (game->player->vect->use_mouse && !game->ray->is_d_map)
		change_by_mouse(game);
	return (0);
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	load_textures(game);
	game->mlx_win = mlx_new_window(game->mlx, WIDTH,
			HEIGHT, "cub3D");
	mlx_mouse_hide();
	init_mouse(game);
	if (!game->player->vect->use_mouse)
		render_map(game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_on_event(game->mlx, game->mlx_win, MLX_KEYDOWN, keydown_event, game);
	mlx_on_event(game->mlx, game->mlx_win, MLX_MOUSEDOWN,
		mousedown_event, game);
	mlx_on_event(game->mlx, game->mlx_win,
		MLX_WINDOW_EVENT, window_event, game);
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
