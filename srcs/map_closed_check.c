/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:26:55 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/26 15:07:19 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_display_map(t_game *game, char **map) // to remove
{
	int i = 0;
	while (i < game->map_size)
	{
		ft_printf("%s", map[i]);
		i++;
	}
}

int	recursive_check(t_game *game, char **map, int x, int y)
{
	if (!char_is_valid(map[y][x]))
	{
		debug_display_map(game, map);
		free_map(game, map);
		return (1);
	}
	map[y][x] = '1';
	if (game->map_size > y + 1 && (map[y + 1][x] != '1'))
		if (!recursive_check(game, map, x, y + 1))
			return (0);
	if (y > 1 && (map[y - 1][x] != '1'))
		if (!recursive_check(game, map, x, y - 1))
			return (0);
	if ((int)ft_strlen(game->map[y]) > x + 1	&& (map[y][x + 1] != '1'))
		if (!recursive_check(game, map, x + 1, y))
			return (0);
	if (x > 1 && (map[y][x - 1] != '1'))
		if (!recursive_check(game, map, x - 1, y))
			return (0);
	return (0);
}

int	make_map_copy(t_game *game, char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_size)
	{
		j = 0;
		map_copy[i] = malloc(sizeof(char *) * ft_strlen(game->map[i]));
		if (!map_copy[i])
			return (3);
		while (game->map[i][j])
		{
			map_copy[i][j] = game->map[i][j];
			j++;
		}
		i++;
	}
	return (0);
}

int	check_if_closed(t_game *game, int x, int y)
{
	char	**map_copy;

	map_copy = malloc(sizeof(char *) * game->map_size);
	if (!map_copy)
		exit_game(game, 0);
	if (make_map_copy(game, map_copy) == 3)
	{
		free(*map_copy);
		free(map_copy);
		exit_game(game, 0);
	}
	if (recursive_check(game, map_copy, x, y))
	{
		debug_display_map(game, map_copy);
		free(*map_copy);
		free(map_copy);
		exit_game(game, "Error\nThe map isn't closed!");
	}
	return (0);
}
