/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:41:57 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/03 17:13:37 by marde-vr         ###   ########.fr       */
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

void	free_texture(t_game *game, t_texture *texture)
{
	if (texture->width)
		free(texture->width);
	if (texture->height)
		free(texture->height);
	if (texture->value)
	{
		if (ft_strnstr(texture->value, ".png", ft_strlen(texture->value)))
			free(texture->value);
		else if (game->mlx)
			mlx_destroy_image(game->mlx, texture->value);
	}
	free(texture);
}

void	free_textures(t_game *game)
{
	if (game->textures)
	{
		free_texture(game, game->textures->no);
		free_texture(game, game->textures->so);
		free_texture(game, game->textures->we);
		free_texture(game, game->textures->ea);
		free(game->textures);
	}
}

void	free_player(t_game *game)
{
	if (game->player->vect)
		free(game->player->vect);
	if (game->player)
		free(game->player);
}

void	exit_game(t_game *game, char *error_message)
{
	if (game)
	{
		if (game->ray)
			free(game->ray);
		free_textures(game);
		if (game->player)
			free_player(game);
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
