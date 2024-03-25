/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:41:57 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/25 20:26:48 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_game *game, char **map)
{
	int	i;	

	i = 0;
	while (i < game->map_size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_textures(t_game *game)
{
	if (game->texture)
	{
		if (game->texture->no)
			mlx_destroy_image(game->mlx, game->texture->no);
		if (game->texture->so)
			mlx_destroy_image(game->mlx, game->texture->so);
		if (game->texture->we)
			mlx_destroy_image(game->mlx, game->texture->we);
		if (game->texture->ea)
			mlx_destroy_image(game->mlx, game->texture->ea);
		if (game->texture->width)
			free(game->texture->width);
		if (game->texture->height)
			free(game->texture->height);
		free(game->texture);
	}
}

void	exit_game(t_game *game, char *error_message)
{
	if (game)
	{
		free_textures(game);
		if (game->map)
			free_map(game, game->map);
		if (game->mlx_win)
			mlx_destroy_window(game->mlx, game->mlx_win);
		if (game->mlx)
			mlx_destroy_display(game->mlx);
		free(game);
	}
	if (error_message)
	{
		ft_printf(error_message);
		exit(1);
	}
	exit(0);
}
