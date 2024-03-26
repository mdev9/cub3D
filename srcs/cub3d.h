/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:21:39 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/26 14:01:49 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <stdio.h>
# include "../MacroLibX/includes/mlx.h"

typedef struct s_vect
{
	double	x;
	double	y;
}	t_vect;

typedef struct s_player
{
	double	x;
	double	y;
	t_vect				*vect;
}	t_player;

typedef struct s_texture
{
	int		*width;
	int		*height;
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
}	t_texture;

typedef struct s_game
{
	void				*mlx;
	void				*mlx_win;
	t_player			*player;
	char				**map;
	int					map_size;
	int					floor_color;
	int					ceilling_color;
	struct s_texture	*texture;
	int					win_width;
	int					win_height;
}	t_game;

void	check_map_validity(t_game *game, char *map_path);
void	check_input_validity(int ac, char **av);
void	exit_game(t_game *game, char *error_message);
void	render_map(t_game *game);
int		window_event(int value, void *game);
int		keydown_event(int keycode, void *game);
int		open_file(char *map_path);
int		check_color_info(t_game *game, char *line, char identifier);
int		is_whitespace(int c);
int		char_is_valid(int c);
int		line_is_only_char(char *line, int c);
void	put_path_in_struct(t_game *game, char *line, char *identifier);
int		line_is_empty(char *line);
void	resize_map(t_game *game, int new_size);
int		load_map_data(t_game *game, int fd);
int		rgb(int r, int g, int b);

#endif
