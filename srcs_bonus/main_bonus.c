/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:21:13 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/03 14:33:14 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	load_texture(t_game *game, void **textures)
{
	char	*texture_path;

	texture_path = ft_strdup(*textures);
	if (!texture_path)
		exit_game(game, 0);
	free(*textures);
	*textures = mlx_png_file_to_image(game->mlx,
			texture_path, game->textures->width, game->textures->height);
	free(texture_path);
	if (!*textures)
		exit_game(game, "Error\nInvalid or missing textures!\n");
}

void	load_textures(t_game *game)
{
	game->textures->width = ft_calloc(1, sizeof(int));
	game->textures->height = ft_calloc(1, sizeof(int));
	if (!game->textures->width || !game->textures->height)
		exit_game(game, 0);
	load_texture(game, &game->textures->no);
	load_texture(game, &game->textures->so);
	load_texture(game, &game->textures->we);
	load_texture(game, &game->textures->ea);
	load_texture(game, &game->textures->door);
	load_texture(game, &game->textures->a1);
	load_texture(game, &game->textures->a2);
	load_texture(game, &game->textures->a3);
}

void	check_input_touch(t_game *game)
{
	if (game->input[0])
		change_player_pos (26, game);
	if (game->input[1])
		change_player_pos(22, game);
	if (game->input[2])
		change_player_pos(7, game);
	if (game->input[3])
		change_player_pos(4, game);
	if (game->input[4])
		change_angle(79, game);
	if (game->input[5])
		change_angle(80, game);
}

void	render_by_view(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	set_img(game);
	if (game->minimap)
		set_minimap(game);
}

int	main(int ac, char **av)
{
	t_game	*game;

	check_input_validity(ac, av);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		exit(1);
	check_map_validity(game, av[1]);
	init_game(game);
}
