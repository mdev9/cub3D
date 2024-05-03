/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:04:09 by axdubois          #+#    #+#             */
/*   Updated: 2024/05/03 15:31:28 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_wall(t_game *game)
{
	game->ray->wall_size = (int){HEIGHT / (game->ray->dist)};
	game->ray->wall_start = (HEIGHT - game->ray->wall_size) / 2;
	if (game->ray->wall_start < 0)
		game->ray->wall_start = 0;
	game->ray->wall_end = (game->ray->wall_size + HEIGHT) / 2;
	if (game->ray->wall_end >= HEIGHT)
		game->ray->wall_end = HEIGHT - 1;
}

void	put_pixel_on_wall(t_game *game, int i, int *j, t_texture *texture)
{
	double	px;
	double	py;

	if ((game->ray->color == 0x55FF0000 || game->ray->color == 0x5500FF00)
		|| (!color_is_from_wall(game->ray->color) && game->ray->side))
		px = game->player->x + game->ray->dist * game->ray->rayx;
	else
		px = game->player->y + game->ray->dist * game->ray->rayy;
	px -= floor(px);
	if ((game->ray->color == 0x55FF0000 || game->ray->color == 0x55FF00FF)
		|| (!color_is_from_wall(game->ray->color) && game->ray->side))
		px = 1.0 - px;
	while (++*j < game->ray->wall_end)
	{
		py = ((*j - (HEIGHT - game->ray->wall_size) / 2)
				* (*texture->height / (HEIGHT / game->ray->dist)));
		game->ray->color = mlx_get_image_pixel(game->mlx, texture->value,
				px * *texture->width, py);
		if (!game->minimap || (game->minimap && (i > 288 || *j > 288)))
			mlx_pixel_put(game->mlx, \
				game->mlx_win, i, *j, game->ray->color);
	}
}

void	display_wall(t_game *game, int i, int *j)
{
	if (game->ray->color == 0x55FF0000)
		put_pixel_on_wall (game, i, j, game->textures->no);
	else if (game->ray->color == 0x5500FF00)
		put_pixel_on_wall (game, i, j, game->textures->so);
	else if (game->ray->color == 0x550000FF)
		put_pixel_on_wall (game, i, j, game->textures->we);
	else if (game->ray->color == 0x55FF00FF)
		put_pixel_on_wall (game, i, j, game->textures->ea);
	else if (game->ray->color == 0x00000000)
		put_pixel_on_wall(game, i, j, game->textures->door);
	else if (game->ray->color == 0x00111111)
	{
		put_pixel_on_wall(game, i, j, get_current_texture(game));
	}
}

void	display_img(t_game *game, int i, int *j)
{
	while (++*j < game->ray->wall_start)
	{
		if (!game->minimap || (game->minimap && (i > 288 || *j > 288)))
			mlx_pixel_put(game->mlx, \
				game->mlx_win, i, *j, game->ceilling_color);
	}
	(*j)--;
	display_wall(game, i, j);
	(*j)--;
	while (++*j < HEIGHT)
	{
		if (!game->minimap || (game->minimap && (i > 288 || *j > 288)))
			mlx_pixel_put(game->mlx, \
				game->mlx_win, i, *j, game->floor_color);
	}
}

void	set_img(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < WIDTH)
	{
		game->ray->rayx = cos(((game->player->vect->angle + 90) * PI / 180)
				+ 0.8 + i / ((double)HEIGHT - 1));
		game->ray->rayy = sin(((game->player->vect->angle + 90) * PI / 180)
				+ 0.8 + i / ((double)HEIGHT - 1));
		set_raycaster(game);
		set_wall(game);
		j = -1;
		display_img(game, i, &j);
	}
}
