/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:21:13 by marde-vr          #+#    #+#             */
/*   Updated: 2024/04/17 16:02:43 by axdubois         ###   ########.fr       */
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

void	check_input_touch(t_game *game)
{
		// if (game->ray->is_d_map)
		// 	change_player_pos_in_map(keycode, game);
		// else
		// 	change_player_pos(keycode, game);
	if (game->input[0])
		change_player_pos(26 ,game);
	else if (game->input[1])
		change_player_pos(22, game);
	else if (game->input[2])
		change_player_pos(7, game);
	else if (game->input[3])
		change_player_pos(4, game);
	else if (game->input[4])
		change_angle(79, game);
	else if (game->input[5])
		change_angle(80, game);
}

int	game_loop(void *s_game)
{
	t_game	*game;

	game = (t_game *) s_game;
	if (game->player->vect->use_mouse && !game->ray->is_d_map)
		change_by_mouse(game);
	check_input_touch(game);
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
		render_map(game);
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
