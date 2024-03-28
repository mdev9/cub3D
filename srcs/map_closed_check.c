/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:26:55 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/28 10:35:38 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//todo put info in struct and add a recursion depth variable to throw an error if too deep to avoid segfaults with too big maps

int	recursive_check(char **map, int map_size, int x, int y)
{
	if (x < 0 || y < 0 || y >= map_size || !map[y] || !map[y][x])
		return (1);
	if (!char_is_valid(map[y][x]))
		return (1);
	if (map[y][x] == '1')
		return (0);
	map[y][x] = '1';
	return (recursive_check(map, map_size, x + 1, y)
		|| recursive_check(map, map_size, x - 1, y)
		|| recursive_check(map, map_size, x, y + 1)
		|| recursive_check(map, map_size, x, y - 1));
}

int	make_map_copy(t_game *game, char **map_copy)
{
	int	i;

	i = 0;
	while (i < game->map_size)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_if_closed(t_game *game, int x, int y)
{
	char	**map_copy;

	map_copy = ft_calloc(game->map_size, sizeof(char *));
	if (!map_copy)
		exit_game(game, 0);
	if (make_map_copy(game, map_copy))
	{
		free(*map_copy);
		free(map_copy);
		exit_game(game, 0);
	}
	//todo calculate map size more acurately to account for any empty lines at end of file
	if (recursive_check(map_copy, game->map_size, x, y))
	{
		free(*map_copy);
		free(map_copy);
		exit_game(game,
			"Error\nThe map contains an invalid character or isn't closed!\n");
	}
	//check if there are any 0's left in the map, if it's the case, run check again
	return (0);
}
