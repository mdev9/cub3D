/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:21:55 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/03 15:54:36 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	color_is_from_wall(int color)
{
	if (color == 0x00000000 || color == 0x00111111)
		return (0);
	return (1);
}

void	*get_current_texture(t_game *game)
{
	int	seed;

	seed = (get_current_time() - game->start_time) % 900;
	if (seed > 300 && seed < 600)
		return (game->textures->a2);
	if (seed > 600 && seed <= 900)
		return (game->textures->a3);
	else
		return (game->textures->a1);
}
