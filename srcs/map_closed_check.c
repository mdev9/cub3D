/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:26:55 by marde-vr          #+#    #+#             */
/*   Updated: 2024/04/24 13:23:45 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//todo put info in struct and add a recursion depth variable to throw an error if too deep to avoid segfaults with too big maps

int	recursive_check(char **map, int *check, int x, int y)
{
	if (check[1] > 130000)
		return (1);
	if (x < 0 || y < 0 || y >= check[0] || !map[y] || !map[y][x])
		return (1);
	if (!char_is_valid(map[y][x]))
		return (1);
	if (map[y][x] == '1')
		return (0);
	map[y][x] = '1';
	check[1]++;
	return (recursive_check(map, check, x + 1, y)
		|| recursive_check(map, check, x - 1, y)
		|| recursive_check(map, check, x, y + 1)
		|| recursive_check(map, check, x, y - 1));
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
		free_map(game, map_copy);
		exit_game(game, 0);
	}
	int check[2];
	check[0] = game->map_size;
	check[1] = 0;
	//todo calculate map size more acurately to account for any empty lines at end of file
	if (recursive_check(map_copy, check, x, y))
	{
		free_map(game, map_copy);
		exit_game(game,
			"Error\nThe map contains an invalid character, isn't closed or is too big!\n");
	}
	free_map(game, map_copy);
	//check if there are any 0's left in the map, if it's the case, run check again
	return (0);
}
