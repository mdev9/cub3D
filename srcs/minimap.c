/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:27:46 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/01 11:05:41 by marde-vr         ###   ########.fr       */
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

void	put_mini_player(t_game *game, int x, int y)
{
	int	i;
	int	j;

	i = 8;
	while (i < 24)
	{
		j = 8;
		while (j < 24)
		{
			mlx_pixel_put(game->mlx, game->mlx_win, x * 32 + j, y * 32 + i, 0xFF34D5EB);
			j++;
		}
		i++;
	}
}

void	set_minimap(t_game *game)
{
	double	x;
	double	y;
	double	i;
	double	j;

	i = 0;
	y = game->player->y - 4;
	while (y < game->map_size && i < 9)
	{
		j = 0;
		x = game->player->x - 4;
		while (j < 9)
		{
			if (x >= 0 && y >= 0 && game->map[(int)y] && x < (double)ft_strlen(game->map[(int)y]))
			{
				ft_printf("%d\n", (int)i);
				if (game->map[(int)y][(int)x] == '0'
					|| char_is_spawn_pos(game->map[(int)y][(int)x]))
					put_tile(game, j, i, 0x22FFFFFF);
				else 
					put_tile(game, j, i, 0xFF00A300);
			}
			x++;
			j++;
		}
		y++;
		i++;
	}
	put_mini_player(game, 4, 4);
}
