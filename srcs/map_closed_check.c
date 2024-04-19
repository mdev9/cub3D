/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:26:55 by marde-vr          #+#    #+#             */
/*   Updated: 2024/04/19 10:32:57 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//todo put info in struct and add a recursion depth variable to throw an error if too deep to avoid segfaults with too big maps

int	recursive_check(char **map, int map_size, t_pos *pos, int depth)
{
	if (pos->x < 0 || pos->y < 0 || pos->y >= map_size || !map[pos->y] || !map[pos->y][pos->x])
		return (1);
	if (!char_is_valid(map[pos->y][pos->x]))
		return (1);
	if (map[pos->y][pos->x] == '1')
		return (0);
	map[pos->y][pos->x] = '1';
	return (recursive_check(map, map_size, pos->x + 1, pos->y)
		|| recursive_check(map, map_size, pos->x - 1, pos->y)
		|| recursive_check(map, map_size, pos->x, pos->y + 1)
		|| recursive_check(map, map_size, pos->x, pos->y - 1));
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

int	check_if_closed(t_game *game, t_pos *starting_pos)
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
	if (recursive_check(map_copy, game->map_size, pos->x, pos->y))
	{
		free(*map_copy);
		free(map_copy);
		exit_game(game,
			"Error\nThe map contains an invalid character or isn't closed!\n");
	}
	//check if there are any 0's left in the map, if it's the case, run check again
	return (0);
}
