/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:33:46 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/01 15:50:51 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	toogle_door(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'D')
		game->map[y][x] = 'O';
	else
		game->map[y][x] = 'D';
}

void	toogle_doors(t_game *game)
{
	double	x;
	double	y;
	int		i;
	int		j;

	i = -1;
	y = game->player->y - 3;
	while (++y < game->map_size && ++i < 5)
	{
		j = -1;
		x = game->player->x - 3;
		while (++j < 5)
		{
			if (++x >= 0 && y >= 0 && game->map[(int)y]
				&& x < (double)ft_strlen(game->map[(int)y]))
			{
				if (game->map[(int)game->player->y][(int)game->player->x]
					== 'O')
					continue ;
				if (game->map[(int)y][(int)x] == 'D'
					|| game->map[(int)y][(int)x] == 'O')
					toogle_door(game, x, y);
			}
		}
	}
}
