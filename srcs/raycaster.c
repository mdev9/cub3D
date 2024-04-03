/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:14:08 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/03 14:59:07 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void printmap(char **map)
{
	int i;
	
	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}
double	dabs(double n)
{
	if (n < 0.0)
		return (n * -1.0);
	return (n);
}

void	calangle(t_game *game)
{
	game->ray->angle = game->player->vect->x * 45 + game->player->vect->y * 45 - 45;
	game->ray->angle %= 360;
	// printf("angle %i\n", game->ray->angle);
	// printf("%f\t%f\n", game->player->vect->x, game->player->vect->y);
}

void	raysendmapp(t_game *game)
{
	double i;
	double j;
	
	j = game->player->x;
	i = game->player->y;
	// printf("px =%f\tpy =%f\n", game->player->x, game->player->y);
	// printf("bloc %c\n", game->map[(int) j][(int) i]);
	// printmap(game->map);
	while (game->map[(int) i][(int) j] && game->map[(int) i][(int) j] != '1')
	{
		if (sin(game->ray->angle) >= 0)
			i += 0.1;
		else
			i -= 0.1;
		if (cos(game->ray->angle) >= 0)
			j += 0.1;
		else
			j -= 0.1;
	// printf("i =%f\tj =%f\n", i,j);
	}
	game->ray->deltax = i; 
	game->ray->deltay = j; 
	game->ray->distx = dabs(i - game->player->x); 
	game->ray->disty = dabs(j - game->player->y);
	printf("distx =%f\tdisty =%f\n", game->ray->distx, game->ray->disty);
}

void	set_raycaster(t_game *game)
{
	game->ray = ft_calloc(sizeof(t_raycaster), 1);
	if (!game->ray)
		exit_game(game, 0);
	calangle(game);
	raysendmapp(game);
}
