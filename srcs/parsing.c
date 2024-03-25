/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:11:52 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/25 11:17:31 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	expand_map_struct(t_game *game, char *line)
{
	char	**res_map;
	int		i;

	res_map = malloc(sizeof(char *) * (game->map_size + 1));
	if (!res_map)
		return (3);
	i = 0;
	while (i < game->map_size)
	{
		res_map[i] = game->map[i];
		i++;
	}
	res_map[i] = line;
	free(game->map);
	game->map = res_map;
	return (0);
}

int	load_map_data(t_game *game, int fd)
{
	char	*line;
	char	**map;

	line = get_next_line(fd);
	if (!line)
		return (8);
	map = malloc(sizeof(char *) * 2);
	if (!map)
		return (3);
	map[0] = line;
	game->map_size = 1;
	game->map = map;
	while (line)
	{
		line = get_next_line(fd);
		if (!line || !*line)
			break ;
		if (expand_map_struct(game, line))
			return (3);
		game->map_size++;
	}
	return (0);
}

int	is_whitespace(int c)
{
	if (c == ' ' || (c <= 9 && c >= 13))
		return (1);
	return (0);
}

int	check_texture_info(t_game *game, char *line, char *identifier)
{
	int i;

	i = 0;
	while (is_whitespace(line[i]))
		*line += 1;
	if (!ft_strncmp(line, identifier, 2))
	{	
		*line += 2;
		while (is_whitespace(line[i]))
			*line += 1;
		if (!ft_strlen(line + 3))
		{
			ft_printf("Error\nNo path specified after %s identifier!\n", identifier);
			exit_game(game, 1);
		}
		return (1);
	}
	return (0);
}

void	check_color(t_game *game, char *line)
{
	//check if valid RGB
	int i;
	int	R;
	int	G;
	int	B;

	i = 0;
	R = ft_atoi(line);
	while (ft_isdigit(line[i]))
		line += 1;
	while (is_whitespace(line[i]))
		*line += 1;
	G = ft_atoi(line);
	while (ft_isdigit(line[i]))
		line += 1;
	while (is_whitespace(line[i]))
		*line += 1;
	B = ft_atoi(line);

}

int	check_color_info(t_game *game, char *line, char identifier)
{
	int i;

	i = 0;
	while (is_whitespace(line[i]))
		*line += 1;
	if (line[i] == identifier)
	{
		*line += 1;
		while (is_whitespace(line[i]))
			*line += 1;
		check_color(game, line);
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
		ft_printf("Error\nInvalid line in map:\n%s", line);
		exit_game(game, 1);
	}
}

int	line_is_empty(char *line)
{
	int i;

	i = 0;
	while (is_whitespace(line[i]))
		i++;
	if (!line[i])
		return (1);
	return (0);
}

void	check_map_info(t_game *game)
{
	int i = 0;
	while (i < game->map_size)
	{
		while (line_is_empty(game->map[i]))
			i++;
		check_info(game, game->map[i]);
		/*
		int j = 0;
		while (game->map[i][j])
		{
			ft_printf("%c", game->map[i][j]);
			while(is_whitespace(game->map[i][j]))
				j++
			if ()
			j++;
		}
		i++;*/
	}
}

void	check_map(t_game *game)
{

}

void	check_if_map_valid(t_game *game)
{
	check_map_info(game);
	check_map(game);
}

void	check_map_validity(t_game *game, char *map_path)
{
	int		map_fd;
	
	map_fd = open_file(map_path);
	load_map_data(game, map_fd);
	check_if_map_valid(game);
}
