/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_spawn_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:20:34 by marde-vr          #+#    #+#             */
/*   Updated: 2024/04/29 14:25:37 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_line_for_spawn(t_game **game, int *i)
{
	int	j;

	j = 0;
	while ((*game)->map[*i][++j])
	{
		if (char_is_spawn_pos((*game)->map[*i][j]))
		{
			(*game)->player->x = j + 0.5;
			(*game)->player->y = *i + 0.5;
			(*game)->player->vect = ft_calloc(1, sizeof(t_vect));
			if (!(*game)->player->vect)
				exit_game(*game, 0);
			get_orientation(game, (*game)->map[*i][j]);
			break ;
		}
		j++;
	}
}

void	get_player_spawn_pos(t_game **game)
{
	int	i;

	i = 0;
	(*game)->player = ft_calloc(1, sizeof(t_player));
	if (!(*game)->player)
		exit_game((*game), 0);
	while (i < (*game)->map_size)
	{
		check_line_for_spawn(game, &i);
		i++;
	}
	if (!(*game)->player->x || !(*game)->player->y)
		exit_game(*game, "Error\nNo player spawning position!");
}
