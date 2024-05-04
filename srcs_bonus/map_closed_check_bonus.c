/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed_check_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:26:55 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/04 16:30:41 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

void	check_map_flooded(t_game *game, char **map_copy, int *i, int *j)
{
	if (char_is_valid(map_copy[*i][*j])
		&& map_copy[*i][*j] != '1' && map_copy[*i][*j] != '\n')
	{
		if (recursive_check(map_copy,
				(int [2]){game->map_size, 0}, *j, *i))
		{
			free_map(game, map_copy);
			exit_game(game, \
"Error\nThe map contains an invalid character, isn't closed or is too big!\n");
		}
		*i = 0;
		*j = 0;
	}
}

void	flood_fill_map(t_game *game, char **map_copy)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map_size)
	{
		j = 0;
		while (map_copy[i][j] == ' ')
			j++;
		while (map_copy[i][j])
		{
			check_map_flooded(game, map_copy, &i, &j);
			j++;
		}
		i++;
	}
}

int	check_if_closed(t_game *game)
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
	if (recursive_check(map_copy,
			(int [2]){game->map_size, 0}, game->player->x, game->player->y))
	{
		free_map(game, map_copy);
		exit_game(game, \
"Error\nThe map contains an invalid character, isn't closed or is too big!\n");
	}
	flood_fill_map(game, map_copy);
	free_map(game, map_copy);
	return (0);
}
