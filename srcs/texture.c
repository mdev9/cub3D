/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:03:14 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/07 10:17:28 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(t_game *game, t_texture *texture)
{
	char	*texture_path;

	texture->width = ft_calloc(1, sizeof(int));
	texture->height = ft_calloc(1, sizeof(int));
	if (!texture->width || !texture->height)
		exit_game(game, 0);
	texture_path = ft_strdup(texture->value);
	if (!texture_path)
		exit_game(game, 0);
	free(texture->value);
	texture->value = mlx_png_file_to_image(game->mlx,
			texture_path, texture->width, texture->height);
	free(texture_path);
	if (!texture->value)
		exit_game(game, "Error\nInvalid or missing textures!\n");
}

void	init_textures(t_game *game)
{
	game->textures = ft_calloc(1, sizeof(t_textures));
	if (!game->textures)
		exit_game(game, 0);
	game->textures->no = ft_calloc(1, sizeof(t_texture));
	game->textures->so = ft_calloc(1, sizeof(t_texture));
	game->textures->we = ft_calloc(1, sizeof(t_texture));
	game->textures->ea = ft_calloc(1, sizeof(t_texture));
	if (!game->textures->no || !game->textures->so
		|| !game->textures->we || !game->textures->ea)
		exit_game(game, 0);
}

void	load_textures(t_game *game)
{
	load_texture(game, game->textures->no);
	load_texture(game, game->textures->so);
	load_texture(game, game->textures->we);
	load_texture(game, game->textures->ea);
}

void	check_texture_file(t_game *game, t_texture **texture)
{
	int	fd;

	check_if_png(game, texture);
	fd = open((*texture)->value, O_RDONLY);
	if (fd == -1)
	{
		if (errno == ENOENT)
			printf("Error\nFile '%s' does not exist.\n",
				(char *)(*texture)->value);
		else if (errno == EACCES)
			printf("Error\nNo permission to read file '%s'.\n",
				(char *)(*texture)->value);
		else
			printf("Error\nCan't open file '%s': %s\n",
				(char *)(*texture)->value, strerror(errno));
	}
	else
	{
		close(fd);
		return ;
	}
	exit_game(game, 0);
}

void	check_texture_files(t_game *game)
{
	check_texture_file(game, &game->textures->ea);
	check_texture_file(game, &game->textures->no);
	check_texture_file(game, &game->textures->so);
	check_texture_file(game, &game->textures->we);
}
