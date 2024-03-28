/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:04:09 by axdubois          #+#    #+#             */
/*   Updated: 2024/03/28 17:23:56 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_img(t_game *game, void	**img)
{
	int	i;
	int	j;

	*img = mlx_new_image(game->mlx, game->win_width, game->win_height);
	i = -1;
	while (++i < game->win_width)
	{
		j = -1;
		while (++j < game->win_height)
		{
			if (j < game->win_height / 2 - game->player->vect->y)
				mlx_set_image_pixel(game->mlx,
					*img, i, j, game->ceilling_color);
			else
				mlx_set_image_pixel(game->mlx,
					*img, i, j, game->floor_color);
		}
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, *img, 0, 0);
}

void	render_map(t_game *game, int isfree)
{
	static void	*img = NULL;

	if ((img && game->calimg) || isfree)
	{
		mlx_destroy_image(game->mlx, img);
	}
	if (isfree)
		return ;
	if (game->calimg)
	{
		set_img(game, &img);
		game->calimg = 0;
	}
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->texture->ea,
		game->win_width / 2 - 32,
		game->win_height / 2 - 32);
}
