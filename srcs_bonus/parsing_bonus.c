/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:11:52 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/03 10:30:14 by axdubois         ###   ########.fr       */
/*   Updated: 2024/05/03 14:33:14 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	line_is_valid += check_texture_info(game, line, "DO");
	line_is_valid += check_texture_info(game, line, "A1");
	line_is_valid += check_texture_info(game, line, "A2");
	line_is_valid += check_texture_info(game, line, "A3");
	line_is_valid += check_color_info(game, line, 'F');
	line_is_valid += check_color_info(game, line, 'C');
	if (!line_is_valid)
	{
		if (line_is_only_char(line, '1'))
			exit_game(game, "Error\nMissing textures or color info in map!\n");
		ft_printf("Error\nInvalid line in map:\n%s", line);
		exit_game(game, 0);
	}
}

void	check_player(t_game *game)
{
	int	i;
	int	j;
	int	player_nb;

	i = 0;
	player_nb = 0;
	while (i < game->map_size)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (char_is_spawn_pos(game->map[i][j]))
				player_nb++;
			j++;
		}
		i++;
	}
	if (player_nb > 1)
		exit_game(game, "Error\nToo many player spawning positions!\n");
	else if (!player_nb)
		exit_game(game, "Error\nNo player spawning position!\n");
}

void	check_if_png(t_game *game, t_texture **texture)
{
	if (!ft_strnstr((*texture)->value, ".png", ft_strlen((*texture)->value)))
	{
		free((*texture)->value);
		(*texture)->value = 0;
		free(*texture);
		*texture = 0;
		exit_game(game, "Error\nCan't open file\n");
	}
}

void	get_orientation(t_game **game, int orientation)
{
	if (orientation == 'N')
		(*game)->player->vect->angle = 90;
	else if (orientation == 'S')
		(*game)->player->vect->angle = 270;
	else if (orientation == 'W')
		(*game)->player->vect->angle = 0;
	else if (orientation == 'E')
		(*game)->player->vect->angle = 180;
}
