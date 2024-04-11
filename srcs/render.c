/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:04:09 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/11 15:17:12 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_by_view(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	if (game->ray->is_d_map)
		display_large_map(game, 0, 0);
	else
		render_map(game);
}

void	set_wall(t_game *game)
{
	game->ray->wall_size = (double)HEIGHT / game->ray->dist;
	game->ray->wall_start = ((double)HEIGHT - game->ray->wall_size) / 2;
	game->ray->wall_end = ((double)HEIGHT + game->ray->wall_size) / 2;
}
void	display_wall(t_game * game, int i, int *j)
{
	while (++*j < game->ray->wall_end)
	{
		if (sin(game->ray->deltax ) < 0 && cos(game->ray->deltax) > 0)
			mlx_pixel_put(game->mlx, \
				game->mlx_win, i, *j, 0x55FF00FF + (int) cos(PI * game->ray->ray) * *j);
		else if (sin(game->ray->deltax ) > 0 && cos(game->ray->deltax ) > 0)
			mlx_pixel_put(game->mlx, \
				game->mlx_win, i, *j, 0xAA0000FF * *j - HEIGHT - i);
		else if (sin(game->ray->deltax ) < 0 && cos(game->ray->deltax ) < 0)
			mlx_pixel_put(game->mlx, \
				game->mlx_win, i, *j, 0x55FFFF00  * *j / 9 - i);
		else
			mlx_pixel_put(game->mlx, \
				game->mlx_win, i, *j, 0x550000FF * i - (i + game->floor_color));
	}
}

void	display_img(t_game *game, int i, int *j)
{
	while (++*j < game->ray->wall_start)
		mlx_pixel_put(game->mlx, \
			game->mlx_win, i, *j, game->ceilling_color - (i * PI) - (int)*j + 1 * PI / WIDTH);
	(*j)--;
	display_wall(game, i, j);
	(*j)--;
	while (++*j < HEIGHT)
		mlx_pixel_put(game->mlx, \
			game->mlx_win, i, *j, game->floor_color + tanf(*j) - PI);
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
		display_img(game, i, &j);
	}
}

void	render_map(t_game *game)
{
	set_img(game);
}
