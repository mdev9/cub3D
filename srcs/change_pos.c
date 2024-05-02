/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:03:07 by axdubois          #+#    #+#             */
/*   Updated: 2024/05/02 14:25:36 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall_touch(t_game *game, double x, double y, double speed[2])
{
	return (!game->map[(int)(game->player->y + y + speed[1] / 100)]
		[(int)(game->player->x + x + speed[0] / 100)]
		|| game->map[(int)(game->player->y + y + speed[1] / 100)]
		[(int)(game->player->x + x + speed[0] / 100)] == '1'
		|| game->map[(int)(game->player->y + y + speed[1] / 100)]
		[(int)(game->player->x + x + speed[0] / 100)] == 'D'
		|| game->map[(int)(game->player->y + y + speed[1] / 100)]
		[(int)(game->player->x + x + speed[0] / 100)] == 'A');
}

void	is_wall_in_way(t_game *game, double speedx, double speedy)
{
	double	x;
	double	y;

	if (game->player->y + speedy <= 0
		|| game->player->y + speedy <= 0 || (int)speedy >= game->map_size
		|| (size_t)speedx >= ft_strlen(game->map[(int)game->player->y]))
		return ;
	x = 0;
	y = 0;
	while (fabs(x) < fabs(speedx))
	{
		x += speedx / 100;
		while (fabs(y) < fabs(speedy))
		{
			y += speedy / 100;
			if (is_wall_touch(game, x, y, (double [2]){speedx, speedy}))
				return ;
		}
		if (is_wall_touch(game, x, y, (double [2]){speedx, speedy}))
			return ;
	}
	game->player->x += x;
	game->player->y += y;
}

void	change_player_pos(int keycode, t_game *game)
{
	double	spdx;
	double	spdy;

	if (keycode == 4)
	{
		spdx = SPEED * cos((game->player->vect->angle + 90) * PI / 180) / 1.5;
		spdy = SPEED * sin((game->player->vect->angle + 90) * PI / 180) / 1.5;
	}
	else if (keycode == 7)
	{
		spdx = SPEED * -cos((game->player->vect->angle + 90) * PI / 180) / 1.5;
		spdy = SPEED * -sin((game->player->vect->angle + 90) * PI / 180) / 1.5;
	}
	else if (keycode == 22)
	{
		spdx = SPEED * sin((game->player->vect->angle + 90) * PI / 180);
		spdy = SPEED * -cos((game->player->vect->angle + 90) * PI / 180);
	}
	else
	{
		spdx = SPEED * -sin((game->player->vect->angle + 90) * PI / 180);
		spdy = SPEED * cos((game->player->vect->angle + 90) * PI / 180);
	}
	is_wall_in_way(game, spdx, spdy);
}
