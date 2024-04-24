/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:21:13 by marde-vr          #+#    #+#             */
/*   Updated: 2024/04/24 13:01:16 by axdubois         ###   ########.fr       */
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

void	move_by_render(int keycode, t_game *game)
{
	if (game->ray->is_d_map)
		change_player_pos_in_map(keycode, game);
	else
		change_player_pos(keycode, game);
}

void	check_input_touch(t_game *game)
{
	if (game->input[0])
		move_by_render (26, game);
	if (game->input[1])
		move_by_render(22, game);
	if (game->input[2])
		move_by_render(7, game);
	if (game->input[3])
		move_by_render(4, game);
	if (game->input[4])
		change_angle(79, game);
	if (game->input[5])
		change_angle(80, game);
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
