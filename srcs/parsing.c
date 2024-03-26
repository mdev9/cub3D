/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:11:52 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/26 14:57:20 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_texture_info(t_game *game, char *line, char *identifier)
{
	int	i;

	i = 0;
	while (is_whitespace(line[i]))
		line += 1;
	if (!ft_strncmp(line, identifier, 2))
	{
		line += 2;
		while (is_whitespace(line[i]))
			line += 1;
		if (!ft_strlen(line + 3))
		{
			ft_printf("Error\nNo path specified after %s identifier!\n",
				identifier);
			exit_game(game, 0);
		}
		put_path_in_struct(game, line, identifier);
		return (1);
	}
	return (0);
}

void	check_info(t_game *game, char *line)
{
	int	line_is_valid;

	line_is_valid = 0;
	line_is_valid += check_texture_info(game, line, "NO");
	line_is_valid += check_texture_info(game, line, "SO");
	line_is_valid += check_texture_info(game, line, "WE");
	line_is_valid += check_texture_info(game, line, "EA");
	line_is_valid += check_color_info(game, line, 'F');
	line_is_valid += check_color_info(game, line, 'C');
	if (!line_is_valid)
	{
		if (line_is_only_char(line, '1'))
			exit_game(game, "Error\nMissing texture or color info in map!\n");
		ft_printf("Error\nInvalid line in map:\n%s", line); //remove line?
		exit_game(game, 0);
	}
}

int	check_map_info(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->texture = ft_calloc(1, sizeof(t_texture));
	if (!game->texture)
		exit_game(game, 0);
	while (i < game->map_size && j < 6)
	{
		while (line_is_empty(game->map[i]))
			i++;
		check_info(game, game->map[i]);
		i++;
		j++;
	}
	while (line_is_empty(game->map[i]))
		i++;
	return (i);
}

void	check_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (is_whitespace(game->map[i][j]))
		j++;
	if (!char_is_valid(game->map[i][j]))
		exit_game(game, "Error\nInvalid character found in map!\n");
	if (!line_is_only_char(game->map[i], '1'))
		exit_game(game, "Error\nThe map isn't surrounded by walls!\n");
	i++;
	while (i < game->map_size)
	{
		j = 0;
		while (is_whitespace(game->map[i][j]))
			j++;
		if (!char_is_valid(game->map[i][j]))
			exit_game(game, "Error\nInvalid character found in map!\n");
		if (game->map[i][j] != '1' || game->map[i][ft_strlen(game->map[i])
			- 2] != '1')
		{
			exit_game(game, "Error\nThe map isn't surrounded by walls!\n");
		}
		i++;
	}
	if (!line_is_only_char(game->map[i - 1], '1'))
		exit_game(game, "Error\nThe map isn't surrounded by walls!\n");
}

int	char_is_spawn_pos(int c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	get_player_spawn_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->player)
		exit_game(game, 0);
	while (i < game->map_size)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (char_is_spawn_pos(game->map[i][j]))
			{
				game->player->x = j;
				game->player->y = i;
				//axel todo: save start player orientation
				//game->player->orientation = game->map[i][j];
			}
			j++;
		}
		i++;
	}
	if (!game->player->x || !game->player->y)
		exit_game(game, "Error\nNo player spawning position!");
}

void	check_if_map_valid(t_game *game)
{
	int	i;

	i = check_map_info(game);
	resize_map(game, i);
	check_map(game);
	get_player_spawn_pos(game);
	check_if_closed(game, game->player->x, game->player->y);
}

void	check_map_validity(t_game *game, char *map_path)
{
	int	map_fd;

	map_fd = open_file(map_path);
	load_map_data(game, map_fd);
	check_if_map_valid(game);
}
