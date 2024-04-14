/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:04:09 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/14 16:24:34 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void    put_fps(t_game *game, int need_free);

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
long long    get_now_time(void)
{
    struct timeval    tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000 + tv.tv_usec);
}
void    put_fps(t_game *game, int need_free)
{
    static long long    last_time = 0;
    static int            change = 0;
    long long            now;
    float                fps;
    static char            tmp[4];

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

void	set_wall(t_game *game)
{
	game->ray->wall_size = (double)HEIGHT / game->ray->dist;
	game->ray->wall_start = ((double)HEIGHT - game->ray->wall_size) / 2;
	game->ray->wall_end = ((double)HEIGHT + game->ray->wall_size) / 2;
}
void	display_wall(t_game * game, int i, int *j)
{
	while (++*j < game->ray->wall_end)
			mlx_pixel_put(game->mlx, \
				game->mlx_win, i, *j, game->ray->color);
}

void	display_img(t_game *game, int i, int *j)
{
	while (++*j < game->ray->wall_start)
		mlx_pixel_put(game->mlx, \
			game->mlx_win, i, *j, game->ceilling_color);
	(*j)--;
	display_wall(game, i, j);
	(*j)--;
	while (++*j < HEIGHT)
		mlx_pixel_put(game->mlx, \
			game->mlx_win, i, *j, game->floor_color);
}
void	set_img(t_game *game)
{
	int	i;
	int	j;

	game->ray = ft_calloc(sizeof(t_raycaster), 1);
	if (!game->ray)
		exit_game(game, 0);
	i = -1;
	while (++i < WIDTH)
	{
		game->ray->ray = ((double)game->player->vect->angle * PI / 180)
			+ i / ((double)HEIGHT) + 0.8;
		// printf("ray = %f\n", game->ray->ray);
		set_raycaster(game);
		set_wall(game);
		j = -1;
		display_img(game, i, &j);
	}
}

void	render_map(t_game *game)
{
	// put_fps(game, 0);
	set_img(game);
}
