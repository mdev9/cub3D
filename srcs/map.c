/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:41:56 by marde-vr          #+#    #+#             */
/*   Updated: 2024/04/05 10:05:02 by axdubois         ###   ########.fr       */
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

void	resize_map(t_game *game, int new_size)
{
	int	i;

	i = 0;
	while (i < game->map_size)
	{
		if (i < new_size)
		{
			free(game->map[i]);
		}
		i++;
	}
	ft_memmove(game->map, game->map + new_size, (game->map_size - new_size)
		* sizeof(char *));
	game->map_size -= new_size;
}
