/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:04:22 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/18 11:06:52 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long long	get_now_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

void	put_fps(t_game *game, int need_free)
{
	static long long	last_time = 0;
	static int			change = 0;
	long long			now;
	float				fps;
	static char			tmp[4];

	if (need_free)
		return ;
	now = get_now_time();
	fps = 1000000 / (now - last_time);
	last_time = now;
	if (change % 10 == 0)
	{
		tmp[0] = (int)fps / 100 + '0';
		tmp[1] = (int)fps / 10 + '0';
		tmp[2] = (int)fps % 10 + '0';
		tmp[3] = '\0';
		mlx_string_put(game->mlx, game->mlx_win, 10, 10, 0xFFFF0000, tmp);
		change = 0;
	}
	else
		mlx_string_put(game->mlx, game->mlx_win, 10, 10, 0xFFFF0000, tmp);
	change++;
}

void	render_by_view(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	if (game->ray->is_d_map)
	{
		put_fps(game, 0);
		display_large_map(game, 0, 0);
	}
	else
		render_map(game);
}
