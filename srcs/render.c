/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:04:09 by axdubois          #+#    #+#             */
/*   Updated: 2024/03/26 16:54:47 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_map(t_game *game)
{
	int	i;
	int	j;
	
	i = -1;
	game->player = ft_calloc(sizeof(t_player), 1);
	if (!game->player)
		exit_game(game, "lol");
	game->player->vect = ft_calloc(sizeof(t_vect),1);
	game->player->vect->y = 1980 / 2;
	while (++i < game->win_width)
	{
		j = -1;
		while (++j < game->win_height)
		{
			if (j == game->player->vect->y)
			{
				mlx_pixel_put(game->mlx, game->mlx_win, i, j, 0);
				printf("vbngfd\n");	
			}
			else if (j < game->win_height / 2)
				mlx_pixel_put(game->mlx, game->mlx_win, i, j, game->ceilling_color);
			else
				mlx_pixel_put(game->mlx, game->mlx_win, i, j, game->floor_color);
		}
	}
		
}
