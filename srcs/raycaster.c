/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:14:08 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/14 16:40:13 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_wall_dir(t_game *game,int x, int y)
{
	if (y >= game->map_size && !game->map[y][x])
		return ;
	if (game->map[y + 1][x] && game->map[y + 1][x] == '0')
		game->ray->color = 0xFFFF0000;
	else if (y > 0 && game->map[y - 1][x] && game->map[y - 1][x] == '0')
		game->ray->color = 0xFF0000FF;
	else if (game->map[y][x + 1] && game->map[y][x + 1] == '0')
		game->ray->color = 0xFF00FF00;
	else if (x > 0 && game->map[y + 1][x - 1] && game->map[y][x - 1] == '0')
		game->ray->color = 0xFFFF00FF;
}

void	raysendmapp(t_game *game)
{
	game->ray->deltax = game->player->x;
	game->ray->deltay = game->player->y;
	while (game->map[(int)(game->ray->deltay)][(int)(game->ray->deltax)]
		&& game->map[(int)(game->ray->deltay)][(int)(game->ray->deltax)] != '1')
	{
		game->ray->deltax += sin(game->ray->ray) / (QUALITY);
		game->ray->deltay += cos(game->ray->ray) / (QUALITY);
	}
	game->ray->poswx = game->ray->deltax;
	game->ray->poswy = game->ray->deltay;
	set_wall_dir(game, (int)floor(game->ray->poswx), (int)floor(game->ray->poswy));
	// printf("dx = %d\t dy = %d\n", (int)floor(game->ray->deltax), (int)floor(game->ray->deltay));
	game->ray->deltax = (game->ray->deltax - game->player->x);
	game->ray->deltay = (game->ray->deltay - game->player->y);
	game->ray->dist = sqrt(game->ray->deltax * game->ray->deltax
			+ game->ray->deltay * game->ray->deltay);
	if (game->ray->dist < 1)
		game->ray->dist = 1;
}

void	set_raycaster(t_game *game)
{
	raysendmapp(game);
}
