/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:04:09 by axdubois          #+#    #+#             */
/*   Updated: 2024/03/26 17:27:56 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_map(t_game *game)
{
	int	i;
	int	j;
	
	i = -1;
	while (++i < game->win_width)
	{
		j = -1;
		while (++j < game->win_height)
		{
			if (i == game->player->vect->x)
				mlx_pixel_put(game->mlx, game->mlx_win, game->player->vect->x, game->player->vect->y, 0);
			else if (j < game->win_height / 2)
				mlx_pixel_put(game->mlx, game->mlx_win, i, j, game->ceilling_color);
			else
				mlx_pixel_put(game->mlx, game->mlx_win, i, j, game->floor_color);
		}
	}
		
}
