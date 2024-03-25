/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:21:39 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/25 13:32:16 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <stdio.h>
# include "../MacroLibX/includes/mlx.h"

typedef struct s_vect
{
	int	x;
	int	y;
}	t_vect;

typedef struct s_texture
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
}	t_texture;

typedef struct s_game
{	
	void				*mlx;
	void				*mlx_win;
	t_vect				*vect;
	char				**map;
	int					map_size;
	int					*width;
	int					*height;
	struct s_texture	*texture;
}	t_game;

void	check_map_validity(t_game *game, char *map_path);
void	check_input_validity(int ac, char **av);
void	exit_game(t_game *game, int exitcode);
void	render_map(t_game *game);
int		window_event(int value, void *game);
int		keydown_event(int keycode, void *game);
int		open_file(char *map_path);

#endif
