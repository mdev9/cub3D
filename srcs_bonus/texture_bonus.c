/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:25:54 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/07 10:15:58 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_textures(t_game *game)
{
	game->textures = ft_calloc(1, sizeof(t_textures));
	if (!game->textures)
		exit_game(game, 0);
	game->textures->no = ft_calloc(1, sizeof(t_texture));
	game->textures->so = ft_calloc(1, sizeof(t_texture));
	game->textures->we = ft_calloc(1, sizeof(t_texture));
	game->textures->ea = ft_calloc(1, sizeof(t_texture));
	game->textures->door = ft_calloc(1, sizeof(t_texture));
	game->textures->a1 = ft_calloc(1, sizeof(t_texture));
	game->textures->a2 = ft_calloc(1, sizeof(t_texture));
	game->textures->a3 = ft_calloc(1, sizeof(t_texture));
	if (!game->textures->no || !game->textures->so
		|| !game->textures->we || !game->textures->ea
		|| !game->textures->door || !game->textures->a1
		|| !game->textures->a2 || !game->textures->a3)
		exit_game(game, 0);
}

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

void	load_textures(t_game *game)
{
	load_texture(game, game->textures->no);
	load_texture(game, game->textures->so);
	load_texture(game, game->textures->we);
	load_texture(game, game->textures->ea);
	load_texture(game, game->textures->door);
	load_texture(game, game->textures->a1);
	load_texture(game, game->textures->a2);
	load_texture(game, game->textures->a3);
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
	check_texture_file(game, &game->textures->door);
	check_texture_file(game, &game->textures->a1);
	check_texture_file(game, &game->textures->a2);
	check_texture_file(game, &game->textures->a3);
}
