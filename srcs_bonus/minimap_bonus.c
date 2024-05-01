/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:27:46 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/01 15:50:29 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
			mlx_pixel_put(game->mlx, game->mlx_win,
				x * 32 + j, y * 32 + i, color);
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
			mlx_pixel_put(game->mlx, game->mlx_win,
				x * 32 + j, y * 32 + i, 0xFF34D5EB);
			j++;
		}
		i++;
	}
}

void	set_minimap_tile(t_game *game, char c, int j, int i)
{
	if (c == '0' || char_is_spawn_pos(c))
		put_tile(game, j, i, 0x22FFFFFF);
	else if (c == 'D')
		put_tile(game, j, i, 0xffe88300);
	else if (c == 'O')
		put_tile(game, j, i, 0x66e88300);
	else
		put_tile(game, j, i, 0xFF00A300);
}

void	set_minimap(t_game *game)
{
	double	x;
	double	y;
	int		i;
	int		j;

	i = -1;
	y = game->player->y - 5;
	while (++y < game->map_size && ++i < 9)
	{
		j = -1;
		x = game->player->x - 5;
		while (++j < 9)
		{
			if (++x >= 0 && y >= 0 && game->map[(int)y]
				&& x < (double)ft_strlen(game->map[(int)y]))
				set_minimap_tile(game, game->map[(int)y][(int)x], j, i);
			else
				put_tile(game, j, i, 0xFF00A300);
		}
	}
	put_mini_player(game, 4, 4);
}
