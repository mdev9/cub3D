/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:14:08 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/09 10:22:31 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raysendmapp(t_game *game)
{
	game->ray->deltax = game->player->x;
	game->ray->deltay = game->player->y;
	while (game->map[(int)(game->ray->deltay)][(int)(game->ray->deltax)]
		&& game->map[(int)(game->ray->deltay)][(int)(game->ray->deltax)] != '1')
	{
		game->ray->deltax += sin(game->ray->ray) / (FOV + 10);
		game->ray->deltay += cos(game->ray->ray) / (FOV + 10);
	}
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
