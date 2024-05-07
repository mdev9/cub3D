/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:44:12 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/07 10:44:21 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_info(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	init_textures(game);
	while (i < game->map_size && j < 6)
	{
		while (line_is_empty(game->map[i]))
			i++;
		check_info(game, game->map[i]);
		i++;
		j++;
	}
	check_texture_files(game);
	while (line_is_empty(game->map[i]))
		i++;
	return (i);
}

void	check_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_size)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!char_is_valid(game->map[i][j]) && game->map[i][j] != ' ')
				exit_game(game, "Error\nInvalid character found in map!\n");
			j++;
		}
		i++;
	}
}

void	check_if_map_valid(t_game *game)
{
	int	i;

	i = check_map_info(game);
	resize_map(game, i);
	check_map(game);
	check_player(game);
	get_player_spawn_pos(&game);
	check_if_closed(game);
}

void	check_map_validity(t_game *game, char *map_path)
{
	int	map_fd;

	map_fd = open_file(game, map_path);
	load_map_data(game, map_fd);
	check_if_map_valid(game);
}
