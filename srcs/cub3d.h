/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:21:39 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/24 14:45:02 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <stdio.h>
# include "../MacroLibX/includes/mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		map_size;
}	t_game;

void	check_input_validity(int ac, char **av);
void	check_map_validity(t_game *game, char *map_path);
void	exit_game(t_game *game, int exitcode);
int		window_event(int value, void *game);
int		keydown_event(int keycode, void *game);

#endif
