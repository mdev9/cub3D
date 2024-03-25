/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:04:09 by axdubois          #+#    #+#             */
/*   Updated: 2024/03/25 20:28:45 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_map(t_game *game)
{
	(void) game;
	mlx_set_font_scale(game->mlx, game->mlx_win, "default", 42);
	ft_printf("%X\n", 0xFFFFFFFF); //0xAARRGGBB
	ft_printf("rgb: %X\n", rgb(0, 255, 0));
	ft_printf("floor: %X\n", game->floor_color);
	ft_printf("ceilling: %X\n", game->ceilling_color);
	mlx_string_put(game->mlx, game->mlx_win, 11, 60, 0xFFFFFFFF, "Hello World");
	mlx_string_put(game->mlx, game->mlx_win, 11, 120, game->floor_color, "FLOOR");
	mlx_string_put(game->mlx, game->mlx_win, 11, 180, game->ceilling_color, "CEIILING");
}
