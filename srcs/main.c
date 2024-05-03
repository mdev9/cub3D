/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:21:13 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/03 15:03:21 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_input_touch(t_game *game)
{
	if (game->input[0])
		change_player_pos (26, game);
	if (game->input[1])
		change_player_pos(22, game);
	if (game->input[2])
		change_player_pos(7, game);
	if (game->input[3])
		change_player_pos(4, game);
	if (game->input[4])
		change_angle(79, game);
	if (game->input[5])
		change_angle(80, game);
}

void	render_by_view(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	set_img(game);
}

int	main(int ac, char **av)
{
	t_game	*game;

	check_input_validity(ac, av);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		exit(1);
	check_map_validity(game, av[1]);
	init_game(game);
}
