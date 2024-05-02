/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:41:57 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/02 10:31:17 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

void	free_texture(t_game *game, void *texture)
{
	if (texture)
	{
		if (ft_strnstr(texture, ".png", ft_strlen(texture)))
			free(texture);
		else if (game->mlx)
			mlx_destroy_image(game->mlx, texture);
	}
}

void	free_textures(t_game *game)
{
	if (game->texture)
	{
		free_texture(game, game->texture->no);
		free_texture(game, game->texture->so);
		free_texture(game, game->texture->we);
		free_texture(game, game->texture->ea);
		free_texture(game, game->texture->door);
		free_texture(game, game->texture->a1);
		free_texture(game, game->texture->a2);
		free_texture(game, game->texture->a3);
		if (game->texture->width)
			free(game->texture->width);
		if (game->texture->height)
			free(game->texture->height);
		free(game->texture);
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
		if (game->mouse)
			free(game->mouse);
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
