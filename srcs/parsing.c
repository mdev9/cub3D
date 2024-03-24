/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:11:52 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/24 15:54:55 by marde-vr         ###   ########.fr       */
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

void	check_if_map_valid(t_game *game)
{
	int i = 0;
	while (i < game->map_size)
	{
		int j = 0;
		while (game->map[i][j])
		{
			ft_printf("%c", game->map[i][j]);
			j++;
		}
		i++;
	}
	//check if map valid
}

void	check_map_validity(t_game *game, char *map_path)
{
	int		map_fd;
	
	map_fd = open_file(map_path);
	load_map_data(game, map_fd);
	check_if_map_valid(game);
}
