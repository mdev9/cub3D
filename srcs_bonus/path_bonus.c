/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:45:57 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/03 15:33:35 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	*get_path(t_game *game, char *line)
{
	char	*path;
	int		len;
	int		i;

	i = 0;
	len = 0;
	line += 2;
	while (is_whitespace(line[i]))
		line += 1;
	while (!is_whitespace(line[i]))
	{
		len++;
		i++;
	}
	path = ft_substr(line, 0, len);
	if (!path)
		exit_game(game, 0);
	return (path);
}

void	put_path_in_struct(t_game *game, char *line, char *identifier)
{
	if (identifier[0] == 'N' && identifier[1] == 'O')
		game->textures->no->value = get_path(game, line);
	if (identifier[0] == 'S' && identifier[1] == 'O')
		game->textures->so->value = get_path(game, line);
	if (identifier[0] == 'W' && identifier[1] == 'E')
		game->textures->we->value = get_path(game, line);
	if (identifier[0] == 'E' && identifier[1] == 'A')
		game->textures->ea->value = get_path(game, line);
	if (identifier[0] == 'D' && identifier[1] == 'O')
		game->textures->door->value = get_path(game, line);
	if (identifier[0] == 'A' && identifier[1] == '1')
		game->textures->a1->value = get_path(game, line);
	if (identifier[0] == 'A' && identifier[1] == '2')
		game->textures->a2->value = get_path(game, line);
	if (identifier[0] == 'A' && identifier[1] == '3')
		game->textures->a3->value = get_path(game, line);
}
