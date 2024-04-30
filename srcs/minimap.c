/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:27:46 by marde-vr          #+#    #+#             */
/*   Updated: 2024/04/30 17:20:12 by marde-vr         ###   ########.fr       */
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
	ft_printf("%d:%d\n", x, y);
	int	i;
	int	j;

	i = 8;
	while (i < 24)
	{
		j = 8;
		while (j < 24)
		{
			mlx_pixel_put(game->mlx, game->mlx_win, x * 32 + j, y * 32 + i, 0xFF00FF00);
			j++;
		}
		i++;
	}
}

void	set_minimap(t_game *game)
{
	int i;
	int y;
	int	x;
	int	j;

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

		while (x < (int)ft_strlen(game->map[y]) && j < 9)
		{
			if (x >= 0 && y >= 0)
			{
				if (game->map[y][x] == '0' || char_is_spawn_pos(game->map[y][x]))
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

/*void	set_minimap(t_game *game)
{
	int x;
	int	y;
	int i;
	int j;

	i = 0;
	y = game->player->y - 4;
	//if (y < 0)
	//	y = 0;
	while (y < game->map_size && game->map[y] && i < 9)
	{
		j = 0;
		x = game->player->x - 4;
		//if (x < 0)
		//	x = 0;
		while (x >= 0 && y >= 0 && x < (int)ft_strlen(game->map[y]) && j < 9)
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
	put_mini_player(game, 4, 4);
}*/
