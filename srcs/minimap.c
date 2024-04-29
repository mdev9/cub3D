/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:27:46 by marde-vr          #+#    #+#             */
/*   Updated: 2024/04/29 18:38:04 by marde-vr         ###   ########.fr       */
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

	i = 0;
	y = game->player->y - 4;
	if (y < 0)
		y = 0;
	while (y < game->map_size && game->map[y] && i < 9)
	{
		j = 0;
		x = game->player->x - 4;
		if (x < 0)
			x = 0;
		while (x < (int)ft_strlen(game->map[y]) && game->map[y][x] && j < 9)
		{
			if (game->map[y][x] == '0'
					|| char_is_spawn_pos(game->map[y][x]))
				put_tile(game, j, i, 0x22FFFFFF);
			else if (j == game->player->x && i == game->player->y)
				put_tile(game, j, i, 0xFF00FF00);
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
