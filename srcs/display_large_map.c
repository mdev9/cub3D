/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_large_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:13:07 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/10 13:11:29 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
			// mlx_pixel_put(game->mlx, game->mlx_win, game->player->x * 32 + floor(sin(game->ray->ray)) + (game->player->x - floor(game->player->x)) * 27 + WIDTH / 4,
				// game->player->y * 32 + floor(cos(game->ray->ray)) + (game->player->y - floor(game->player->y)) * 27 + HEIGHT / 4, 0x99FF0000);

// void	put_ray(t_game *game)
// {
// 	int	x;
// 	int	y;
// 	int i;

// 	x = 0;
// 	y = 0;
// 	while (game->map[y][x])
// 	{
// 		while (y < 10)
// 		{
// 			i = 0;
// 			while (i < 10)
// 			{
// 				if (game->map[y][x] == '1')
// 					break ;
// 				mlx_pixel_put(game->mlx, game->mlx_win, game->player->x * 32 + (game->player->x - floor(game->player->x)) * 27 + WIDTH / 4 + i * sin(game->ray->ray), 
// 					game->player->y * 32 + (game->player->y - floor(game->player->y)) * 27 + HEIGHT / 4 + i * cos(game->ray->ray),0x99FF0000);
// 				i++;
// 			}
			
// 			y++;
// 		}
// 		x++;
// 	}
// }

void	put_player(t_game *game, int playerx, int playery)
{
	int	x;
	int	y;

	x = -1;
	while (++x < 5)
	{
		y = -1;
		while (++y < 5)
			mlx_pixel_put(game->mlx, game->mlx_win, playerx * 32 + x + (game->player->x - floor(game->player->x)) * 27
				+ WIDTH / 4, playery * 32 + y + (game->player->y - floor(game->player->y)) * 27 + HEIGHT / 4, 0xFF0000FF);
	}
}
void	put_floor(t_game *game, int floorx, int floory)
{
	int	x;
	int	y;

	x = -1;
	while (++x < 32)
	{
		y = -1;
		while (++y < 32)
			mlx_pixel_put(game->mlx, game->mlx_win, floorx * 32 + x + WIDTH / 4,
				floory * 32 + y + HEIGHT / 4, 0x22FFFFFF);
	}
}
void	put_mapwall(t_game *game, int wall_x, int wall_y)
{
	int	x;
	int	y;

	x = -1;
	while (++x < 32)
	{
		y = -1;
		while (++y < 32)
			mlx_pixel_put(game->mlx, game->mlx_win, wall_x * 32 + x + WIDTH / 4,
				wall_y * 32 + y + HEIGHT / 4, 0xFF00A300);
	}
}

int	display_large_map(t_game *game, int x, int y)
{
	if (y >= game->map_size)
		return (1);
	if (game->map[y][x] == '1')
		put_mapwall(game, x, y);
	else if (y == (int) game->player->y && x == (int) game->player->x)
	{
		put_floor(game, x, y);
		put_player(game, game->player->x, game->player->y);
	}
	else if (game->map[y][x] != '1' &&
		!is_whitespace(game->map[y][x]) && game->map[y][x] != '\0')
		put_floor(game, x, y);
	// put_ray(game);
	if (!game->map[y][x])
		display_large_map(game, 0, y + 1);
	else
		display_large_map(game, x + 1, y);
	return (0);
}
