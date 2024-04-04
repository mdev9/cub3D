/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:14:08 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/04 19:52:20 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	dabs(double n)
{
	if (n < 0.0)
		return (n * -1.0);
	return (n);
}

void	raysendmapp(t_game *game)
{
	double x;
	double y;
	
	x = game->player->x;
	y = game->player->y;
	// printf("angle %d\n", game->ray->ray);
	// printf("cos angle %f\n", cos(game->ray->ray * 3.141592 / 180));
	// printf("sin angle %f\n", sin(game->ray->ray * 3.141592 / 180));
	while (game->map[(int) y][(int) x] && game->map[(int) y][(int) x] != '1')
	{
		if ((cos(game->ray->ray)) == 1)
			x += 0.1;
		else if ((cos(game->ray->ray)) == -1)
			x -= 0.1;
		else
			x += cos(game->ray->ray);
		if ((sin(game->ray->ray)) == 1)
			y -= 0.1;
		else if ((sin(game->ray->ray)) == -1)
			y += 0.1;
		else
			y += sin(game->ray->ray);
		// printf("x =%f\ty =%f\n", x, y);
	}
	game->ray->dist = sqrt(x * x + y * y);
	if (game->ray->dist < 1)
		game->ray->dist = 1;
	// printf("%f\n", game->ray->dist);
	// printf("dist =%f\n", game->ray->distx, game->ray->disty);
}

void	set_raycaster(t_game *game)
{
	game->ray->ray += STEP;
	raysendmapp(game);
}
