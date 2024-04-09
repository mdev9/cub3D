/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:04:09 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/09 17:37:30 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_wall(t_game *game)
{
	game->ray->wall_size = (double)HEIGHT / game->ray->dist;
	game->ray->wall_start = ((double)HEIGHT - game->ray->wall_size) / 2;
	game->ray->wall_end = ((double)HEIGHT + game->ray->wall_size) / 2;
}

void	set_img(t_game *game)
{
	int	i;
	int	j;

	game->ray = ft_calloc(sizeof(t_raycaster), 1);
	if (!game->ray)
		exit_game(game, 0);
	i = -1;
	while (++i < WIDTH)
	{
		game->ray->ray = ((double)game->player->vect->angle * PI / 180)
			+ i / ((double)HEIGHT) + 0.5;
		set_raycaster(game);
		set_wall(game);
		j = -1;
		while (++j < game->ray->wall_start)
			mlx_pixel_put(game->mlx, \
				game->mlx_win, i, j, game->ceilling_color);
		while (++j < game->ray->wall_end)
			mlx_pixel_put(game->mlx, \
				game->mlx_win, i, j, 0x550000FF);
		while (++j < HEIGHT)
			mlx_pixel_put(game->mlx, \
				game->mlx_win, i, j, game->floor_color);
	}
}

void	render_map(t_game *game)
{
	set_img(game);
}
