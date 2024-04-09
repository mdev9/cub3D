/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_large_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:13:07 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/09 14:18:12 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_player(t_game *game, int playerx, int playery)
{
	int	x;
	int	y;

	x = -1;
	while (++x < 5)
	{
		y = -1;
		while (++y < 5)
			mlx_pixel_put(game->mlx, game->mlx_win, playerx * 32 + x + 16
				+ WIDTH / 4, playery * 32 + y + 16 + HEIGHT / 4, 0xFF0000FF);
	}
}

void	put_mapwall(t_game *game, int wall_x, int wall_y)
{
	int	x;
	int	y;

	x = -1;
	while (++x < 32)
	{
		y = -1;
		while (++y < 32)
			mlx_pixel_put(game->mlx, game->mlx_win, wall_x * 32 + x + WIDTH / 4,
				wall_y * 32 + y + HEIGHT / 4, 0xFF00A300);
	}
}

int	display_large_map(t_game *game, int x, int y)
{
	if (y >= game->map_size)
		return (1);
	if (game->map[y][x] == '1')
		put_mapwall(game, x, y);
	else if (y == (int) game->player->y && x == (int) game->player->x)
		put_player(game, x, y);
	if (!game->map[y][x])
		display_large_map(game, 0, y + 1);
	else
		display_large_map(game, x + 1, y);
	return (0);
}
