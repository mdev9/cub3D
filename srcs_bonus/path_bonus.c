/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:45:57 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/03 17:33:13 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	get_path(t_game *game, char *line, void **texture)
{
	char	*path;
	int		len;
	int		i;

	if (ft_strnstr(*texture, ".png", ft_strlen(*texture)))
		exit_game(game, "Error\nDuplicate texture identifier!\n");
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
	*texture = path;
}

void	put_path_in_struct(t_game *game, char *line, char *identifier)
{
	if (identifier[0] == 'N' && identifier[1] == 'O')
		get_path(game, line, &game->textures->no->value);
	if (identifier[0] == 'S' && identifier[1] == 'O')
		get_path(game, line, &game->textures->so->value);
	if (identifier[0] == 'W' && identifier[1] == 'E')
		get_path(game, line, &game->textures->we->value);
	if (identifier[0] == 'E' && identifier[1] == 'A')
		get_path(game, line, &game->textures->ea->value);
	if (identifier[0] == 'D' && identifier[1] == 'O')
		get_path(game, line, &game->textures->door->value);
	if (identifier[0] == 'A' && identifier[1] == '1')
		get_path(game, line, &game->textures->a1->value);
	if (identifier[0] == 'A' && identifier[1] == '2')
		get_path(game, line, &game->textures->a2->value);
	if (identifier[0] == 'A' && identifier[1] == '3')
		get_path(game, line, &game->textures->a3->value);
}
