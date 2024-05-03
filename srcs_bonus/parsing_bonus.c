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

void	check_texture_file(t_game *game, char *textures)
{
	int	fd;

	fd = open(textures, O_RDONLY);
	if (fd == -1)
	{
		if (errno == ENOENT)
			printf("Error\nFile '%s' does not exist.\n", textures);
		else if (errno == EACCES)
			printf("Error\nNo permission to read file '%s'.\n",
				textures);
		else
			printf("Error\nCan't open file '%s': %s\n",
				textures, strerror(errno));
	}
	else
	{
		close(fd);
		return ;
	}
	exit_game(game, 0);
}

void	check_texture_files(t_game *game)
{
	check_texture_file(game, game->textures->ea);
	check_texture_file(game, game->textures->no);
	check_texture_file(game, game->textures->so);
	check_texture_file(game, game->textures->we);
	check_texture_file(game, game->textures->door);
	check_texture_file(game, game->textures->a1);
	check_texture_file(game, game->textures->a2);
	check_texture_file(game, game->textures->a3);
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
