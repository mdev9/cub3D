/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:27:46 by marde-vr          #+#    #+#             */
/*   Updated: 2024/04/29 17:22:24 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_tile(t_game *game, int x, int y, unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			mlx_pixel_put(game->mlx, game->mlx_win, x * 32 + j, y * 32 + i, color);
			j++;
		}
		i++;
	}
}

void	set_minimap(t_game *game)
{
	int x;
	int	y;
	int i;
	int j;

	x = game->player->x - 4;
	y = game->player->y - 4;
	i = 0;
	while (game->map[y] && i < 9)
	{
		j = 0;
		x = 0;
		while (game->map[y][x] && j < 9)
		{
			if (game->map[y][x] == '0'
					|| char_is_spawn_pos(game->map[y][x]))
				put_tile(game, j, i, 0x22FFFFFF);
			else 
				put_tile(game, j, i, 0xFF00A300);
			x++;
			j++;
		}
		y++;
		i++;
	}
	put_tile(game, 4, 4, 0xFF00FF00);
}
