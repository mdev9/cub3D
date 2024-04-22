/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:03:07 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/22 10:41:58 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall_touch(t_game *game, double x, double y)
{
	return (!game->map[(int)(game->player->y + y)]
		[(int)(game->player->x + x)]
		|| game->map[(int)(game->player->y + y)]
		[(int)(game->player->x + x)] == '1');
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
			if (is_wall_touch(game, x, y))
				return ;
		}
		if (is_wall_touch(game, x, y))
			return ;
	}
	game->player->x += x;
	game->player->y += y;
}

void	change_player_pos(int keycode, t_game *game)
{
	double	speedx;
	double	speedy;

	if (keycode == 7)
	{
		speedx = SPEED * cos((game->player->vect->angle + 90) * PI / 180);
		speedy = SPEED * sin((game->player->vect->angle + 90) * PI / 180);
	}
	else if (keycode == 4)
	{
		speedx = SPEED * -cos((game->player->vect->angle + 90) * PI / 180);
		speedy = SPEED * -sin((game->player->vect->angle + 90) * PI / 180);
	}
	else if (keycode == 26)
	{
		speedx = SPEED * sin((game->player->vect->angle + 90) * PI / 180);
		speedy = SPEED * -cos((game->player->vect->angle + 90) * PI / 180);
	}
	else
	{
		speedx = SPEED * -sin((game->player->vect->angle + 90) * PI / 180);
		speedy = SPEED * cos((game->player->vect->angle + 90) * PI / 180);
	}
	is_wall_in_way(game, speedx, speedy);
}

void	change_player_pos_in_map(int keycode, t_game *game)
{
	if (keycode == 7 && game->map[(int)game->player->y]
		[(int)(game->player->x + SPEED / 5)] != '1')
		game->player->x += SPEED / 5;
	else if (keycode == 4 && game->map[(int)game->player->y]
		[(int)(game->player->x - SPEED / 5)] != '1')
		game->player->x -= SPEED / 5;
	else if (keycode == 22 && game->map[(int)(game->player->y + SPEED / 5)]
		[(int)game->player->x] != '1')
		game->player->y += SPEED / 5;
	else if (keycode == 26 && game->map[(int)(game->player->y - SPEED / 5)]
		[(int)game->player->x] != '1')
		game->player->y -= SPEED / 5;
}
