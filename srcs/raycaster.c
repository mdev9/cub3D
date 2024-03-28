/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:14:08 by axdubois          #+#    #+#             */
/*   Updated: 2024/03/28 10:29:37 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_raycaster(t_game *game)
{
	int	i;
	double camx;
	double raydirx;
	double raydiry;

	i = -1;
	while (++i < game->win_width)
	{
		camx = 2 * i / (double)game->win_width - 1;
		raydirx = game->player->vect->x + game->player->planex * camx;
		raydiry = game->player->vect->y + game->player->planey * camx;
	}
}