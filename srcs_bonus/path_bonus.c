/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:45:57 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/01 14:20:42 by marde-vr         ###   ########.fr       */
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
		game->texture->no = get_path(game, line);
	if (identifier[0] == 'S' && identifier[1] == 'O')
		game->texture->so = get_path(game, line);
	if (identifier[0] == 'W' && identifier[1] == 'E')
		game->texture->we = get_path(game, line);
	if (identifier[0] == 'E' && identifier[1] == 'A')
		game->texture->ea = get_path(game, line);
	if (identifier[0] == 'D' && identifier[1] == 'O')
		game->texture->door = get_path(game, line);
}
