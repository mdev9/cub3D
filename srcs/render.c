/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:04:09 by axdubois          #+#    #+#             */
/*   Updated: 2024/03/27 10:44:07 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_all_image(t_game *game)
{
	int	i;
	int	j;
	
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->texture->ea,  i, j);
			else
			{
				if (j < game->win_height / 2)
					mlx_pixel_put(game->mlx, game->mlx_win, i, j, game->ceilling_color);
				else
					mlx_pixel_put(game->mlx, game->mlx_win, i, j, game->floor_color);
			}
		}
	}
	
}

void	render_map(t_game *game)
{
	int	i;
	int	j;
	
	i = -1;
	mlx_clear_window(game->mlx, game->mlx_win);
	while (++i < game->win_width)
	{
		j = -1;
		while (++j < game->win_height)
		{
			if (i >=  game->win_width / 2 + game->player->vect->x && i <=  game->win_width / 2 + game->player->vect->x + 64 && j >=  game->win_height / 2 + game->player->vect->y && j <=  game->win_height / 2 + game->player->vect->y + 64)
				continue;
			if (j < game->win_height / 2)
				mlx_pixel_put(game->mlx, game->mlx_win, i, j, game->ceilling_color);
			else
				mlx_pixel_put(game->mlx, game->mlx_win, i, j, game->floor_color);
		}
	}
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->texture->ea,  game->win_width / 2 + game->player->vect->x, game->win_height / 2 + game->player->vect->y);
	// put_all_image(game);
}
