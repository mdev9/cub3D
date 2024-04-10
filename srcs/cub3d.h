/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:21:39 by marde-vr          #+#    #+#             */
/*   Updated: 2024/04/10 14:01:58 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <stdio.h>
# include "../MacroLibX/includes/mlx.h"
# include "raycaster.h"
# include <stdbool.h>
# include <math.h>

# define N -1
# define S 1
# define W -1
# define E 1
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_vect
{
	int	angle;
	int	use_mouse;
}	t_vect;

typedef struct s_player
{
	t_vect		*vect;
	double		x;
	double		y;
}	t_player;

typedef struct s_mouse
{
	double		x;
	double		y;
}	t_mouse;

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
	t_player	*player;
	t_texture	*texture;
	t_raycaster	*ray;
	t_mouse		*mouse;
	void		*mlx;
	void		*mlx_win;
	char		**map;
	int			map_size;
	int			floor_color;
	int			ceilling_color;
}	t_game;

void	put_path_in_struct(t_game *game, char *line, char *identifier);
void	check_map_validity(t_game *game, char *map_path);
void	exit_game(t_game *game, char *error_message);
void	check_input_validity(int ac, char **av);
void	resize_map(t_game *game, int new_size);
void	free_map(t_game *game, char **map);
void	set_raycaster(t_game *game);
void	render_map(t_game *game);
void	set_wall(t_game *game);
void	set_img(t_game *game);
void	put_ray(t_game *game);

int		check_color_info(t_game *game, char *line, char identifier);
int		mousedown_event(int keycode, void *game_data);
int		check_if_closed(t_game *game, int x, int y);
int		display_large_map(t_game *game, int x, int y);
int		keydown_event(int keycode, void *game);
int		line_is_only_char(char *line, int c);
int		window_event(int value, void *game);
int		load_map_data(t_game *game, int fd);
int		open_file(char *map_path);
int		line_is_empty(char *line);
int		rgb(int r, int g, int b);
int		is_whitespace(int c);
int		char_is_valid(int c);

#endif
