/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:14:08 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/17 17:37:19 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
	// 	game->ray->color = 0xFFFF0000;n
	// 	game->ray->color = 0xFF0000FF;s
	// 	game->ray->color = 0xFF00FF00;e
	// 	game->ray->color = 0xFFFF00FF;w

void	set_wall_color(t_game *game, int side)
{
	if (side)
	{
		if (game->ray->rayy > 0 &&  game->ray->rayy < PI)
			game->ray->color = 0x55FF0000;//
		else
			game->ray->color = 0x5500FF00;//

	}
	else
	{
		if (game->ray->rayx + PI > PI && game->ray->rayx + PI < 3 * PI / 2)
			game->ray->color = 0x550000FF;//
		else
			game->ray->color = 0x55FF00FF;//
	}
}

void	raysendmapp(t_game *game)
{
	int	side;
	
	while (1)
	{
		// printf("sdistx %f\t sdisty %f\n", game->ray->sidedistx, game->ray->sidedisty);
		// printf("dx %f\t dy %f\n", game->ray->deltax, game->ray->deltay);
		// printf("px %f\t py %f\n", game->player->x, game->player->y);
		if(game->ray->sidedistx < game->ray->sidedisty)
        {
        	game->ray->sidedistx = game->ray->sidedistx + game->ray->deltax;
			game->ray->mapx += game->ray->stepx;
			side = 0;
		}
		else
		{
			game->ray->sidedisty = game->ray->sidedisty + game->ray->deltay;
			game->ray->mapy += game->ray->stepy;
			side = 1;
		}
		if (game->map[game->ray->mapy][game->ray->mapx] == '1')
			break ;
	}
	if (side == 0)
		game->ray->dist = game->ray->sidedistx - game->ray->deltax;
	else
		game->ray->dist = game->ray->sidedisty - game->ray->deltay;
	// printf("============\n");
	set_wall_color(game, side);
}

void	set_raycaster(t_game *game)
{
	game->ray->mapx = (int)(game->player->x);
	game->ray->mapy = (int)(game->player->y);
	if (game->ray->rayx == 0.00000)
		game->ray->deltax = 1e30;
	else
		game->ray->deltax = fabs(1 / game->ray->rayx);
	if (game->ray->rayy == 0.0000000)
		game->ray->deltay = 1e30;
	else
		game->ray->deltay = fabs(1 / game->ray->rayy);
	if (game->ray->rayx < 0)
	{
		game->ray->stepx = -1;
		game->ray->sidedistx = (game->player->x - (double)game->ray->mapx) * game->ray->deltax;
	}
	else
	{
		game->ray->stepx = 1;
		game->ray->sidedistx = ((double)game->ray->mapx + 1.0 - game->player->x) * game->ray->deltax;
	}
	if (game->ray->rayy < 0)
	{
		game->ray->stepy = -1;
		game->ray->sidedisty = (game->player->y - (double)game->ray->mapy) * game->ray->deltay;
	}
	else
	{
		game->ray->stepy = 1;
		game->ray->sidedisty = ((double)game->ray->mapy + 1.0 - game->player->y) * game->ray->deltay;
	}
	// printf("sdx %f\t sdy %f\n", (game->player->y - (double)game->ray->mapy) * game->ray->deltay, (game->player->x - (double)game->ray->mapx) * game->ray->deltax);
	// printf("sdx %f\t sdy %f\n", ((double)game->ray->mapx + 1.0 - game->player->x) * game->ray->deltax, ((double)game->ray->mapy + 1.0 - game->player->y) * game->ray->deltay);
	raysendmapp(game);
}
