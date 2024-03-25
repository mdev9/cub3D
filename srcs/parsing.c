/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:11:52 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/25 16:30:31 by marde-vr         ###   ########.fr       */
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
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

char	*get_path(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (!is_whitespace(line[i]))
	{
		len++;
		i++;
	}
	return (ft_substr(line, 0, len));
}

void	put_path_in_struct(t_game *game, char *line, char *identifier)
{
	if (identifier[0] == 'N' && identifier[1] == 'O')
		game->texture->no = get_path(line);
	if (identifier[0] == 'S' && identifier[1] == 'O')
		game->texture->so = get_path(line);
	if (identifier[0] == 'W' && identifier[1] == 'E')
		game->texture->we = get_path(line);
	if (identifier[0] == 'E' && identifier[1] == 'A')
		game->texture->ea = get_path(line);
}

int	check_texture_info(t_game *game, char *line, char *identifier)
{
	int	i;

	i = 0;
	game->texture = ft_calloc(1, sizeof(t_texture));
	if (!game->texture)
		exit_game(game, 0);
	while (is_whitespace(line[i]))
		*line += 1;
	if (!ft_strncmp(line, identifier, 2))
	{
		*line += 2;
		while (is_whitespace(line[i]))
			*line += 1;
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

int	ft_power(int n, int power)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (n);
	return (n * ft_power(n, power - 1));
}

int	rgb(int r, int g, int b)
{
    g = ((g / 16) * ft_power(16, 3)) + (g % 16) * ft_power(16, 2);
    r = ((r / 16) * ft_power(16, 5)) + (r % 16) * ft_power(16, 4);
    return (r + g + b);
}

void	check_color(t_game *game, char *line, char identifier)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	r = ft_atoi(line);
	if (!(r >= 0 && r <= 255))
		exit_game(game, "Error\nInvalid or missing red color value!\n");
	while (ft_isdigit(line[i]))
		line += 1;
	while (is_whitespace(line[i]))
		*line += 1;
	g = ft_atoi(line);
	if (!(g >= 0 && g <= 255))
		exit_game(game, "Error\nInvalid or missing green color value!\n");
	while (ft_isdigit(line[i]))
		line += 1;
	while (is_whitespace(line[i]))
		*line += 1;
	b = ft_atoi(line);
	if (!(b >= 0 && b <= 255))
		exit_game(game, "Error\nInvalid or missing blue color value!\n");
	if (identifier == 'F')
	{
		game->floor_color = ft_calloc(1, sizeof(int));
		if (!game->floor_color)
			exit_game(game, 0);
		*game->floor_color = rgb(r, g, b);
	}
	if (identifier == 'C')
	{
		game->ceilling_color = ft_calloc(1, sizeof(int));
		if (!game->ceilling_color)
			exit_game(game, 0);
		*game->ceilling_color = rgb(r, g, b);
	}
}

int	check_color_info(t_game *game, char *line, char identifier)
{
	int	i;

	i = 0;
	while (is_whitespace(line[i]))
		*line += 1;
	if (line[i] == identifier)
	{
		*line += 1;
		while (is_whitespace(line[i]))
			*line += 1;
		check_color(game, line, identifier);
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
		ft_printf("Error\nInvalid line in map:\n%s", line); //remove line?
		exit_game(game, 0);
	}
}

int	line_is_empty(char *line)
{
	int	i;

	i = 0;
	while (is_whitespace(line[i]))
		i++;
	if (!line[i])
		return (1);
	return (0);
}

int	check_map_info(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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

int	char_is_valid(int c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	line_is_only_char(char *line, int c)
{
	int i;

	i = 0;
	while (is_whitespace(line[i]))
		i++;
	while (line[i])
	{
		if (line[i] != c && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	check_map(t_game *game, int i)
{
	int j;

	j = 0;
	while (is_whitespace(game->map[i][j]))
		j++;
	if (!char_is_valid(game->map[i][j]))
		exit_game(game, "Error\nInvalid character found in map!\n");
	if (!line_is_only_char(game->map[i], '1'))
		exit_game(game, "Error\nThe map isn't surrounded by walls!\n");
	i++;
	ft_printf("map_size: %d\n", game->map_size);
	while (i < game->map_size - 1)
	{
		ft_printf("i: %d\n", i);
		ft_printf("line: %s", game->map[i]);
		ft_printf("first_char %d\n", game->map[i][j]);
		ft_printf("last_char: %d\n", game->map[i][ft_strlen(game->map[i]) - 2]);
		j = 0;
		while (is_whitespace(game->map[i][j]))
			j++;
		if (game->map[i][j] != '1' || game->map[i][ft_strlen(game->map[i]) - 2] != '1')
		{
			ft_printf("line: %s", game->map[i]);
			exit_game(game, "Error\nThe map isn't surrounded by walls!\n");
		}
		i++;
	}
	ft_printf("finished while loop\n");
	if (!line_is_only_char(game->map[i], '1'))
		exit_game(game, "Error\nThe map isn't surrounded by walls!\n");
}

void	check_if_map_valid(t_game *game)
{
	int i;

	i = check_map_info(game);
	check_map(game, i);
}

void	check_map_validity(t_game *game, char *map_path)
{
	int		map_fd;
	
	map_fd = open_file(map_path);
	load_map_data(game, map_fd);
	check_if_map_valid(game);
}
