/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:04:09 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/17 16:52:17 by axdubois         ###   ########.fr       */
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
	game->ray->wall_size = (int){HEIGHT / game->ray->dist};
	game->ray->wall_start = (HEIGHT - game->ray->wall_size) / 2;
	if (game->ray->wall_start < 0)
		game->ray->wall_start = 0;
	game->ray->wall_end = (game->ray->wall_size + HEIGHT) / 2;
	if (game->ray->wall_end >= HEIGHT)
		game->ray->wall_end = HEIGHT - 1;
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
	int		i;
	int		j;

	i = -1;
	while (++i < WIDTH)
	{
		game->ray->rayx = cos((game->player->vect->angle * PI / 180 - 0.8) + i / ((double)HEIGHT));
		game->ray->rayy = sin((game->player->vect->angle * PI / 180 - 0.8) + i / ((double)HEIGHT));
		// printf("rax %f\t ray %f\n", game->ray->rayx, game->ray->rayy);
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
