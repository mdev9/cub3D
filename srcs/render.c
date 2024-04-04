/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:04:09 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/04 19:46:01 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_wall(t_game *game)
{
	game->ray->wall_sizey = game->win_height / game->ray->dist;
	// if (game->ray->wall_sizey > game->win_height || game->ray->dist == 0.0)
	// 	game->ray->wall_sizey = game->win_height;
	game->ray->wall_starty = (game->win_height - game->ray->wall_sizey) / 2;
	game->ray->wall_endy = (game->win_height + game->ray->wall_sizey) / 2;
	// printf("dist =%f\n", game->ray->dist);
	// printf("wall =%d\n", game->ray->wall_size);
	// printf("start wall =%d\n", game->ray->wall_start);
	// printf("end wall =%d\n", game->ray->wall_end);
}

void	set_img(t_game *game)
{
	int	i;
	int	j;

	game->ray = ft_calloc(sizeof(t_raycaster), 1);
	if (!game->ray)
		exit_game(game, 0);
	game->ray->ray = (game->player->vect->angle - FOV / 2) * PI / 180;
	// printf("ray =%f\n", game->ray->ray);
	i = -1;
	while (++i < game->win_width)
	{
		set_raycaster(game);
		set_wall(game);
		j = 0;
		while (j < game->ray->wall_starty)
		{
			mlx_pixel_put(game->mlx,
				game->mlx_win, i, j, game->ceilling_color);
				j++;
		}
		while (j < game->ray->wall_endy)
		{
			mlx_pixel_put(game->mlx,
				game->mlx_win, i, j, 0xFF000033);
				j++;
		}
		while (j < game->win_height)
		{
			mlx_pixel_put(game->mlx,
				game->mlx_win, i, j, game->floor_color);
			j++;
		}
	}
}

void	render_map(t_game *game)
{
		set_img(game);
}
