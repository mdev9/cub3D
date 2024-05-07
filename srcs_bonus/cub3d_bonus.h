/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:21:39 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/07 10:48:45 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../libft/libft.h"
# include <stdio.h>
# include "../MacroLibX/includes/mlx.h"
# include "raycaster_bonus.h"
# include <stdbool.h>
# include <math.h>
# include <sys/time.h>
# include <errno.h>
# include <string.h>

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
	void	*value;
}	t_texture;

typedef struct s_textures
{
	t_texture	*no;
	t_texture	*so;
	t_texture	*we;
	t_texture	*ea;
	t_texture	*door;
	t_texture	*a1;
	t_texture	*a2;
	t_texture	*a3;
}	t_textures;

typedef struct s_game
{
	t_player		*player;
	t_textures		*textures;
	t_raycaster		*ray;
	t_mouse			*mouse;
	void			*mlx;
	void			*mlx_win;
	char			**map;
	int				minimap;
	size_t			start_time;
	int				current_animation_color;
	int				map_size;
	int				floor_color;
	int				ceilling_color;
	int				input[7];
}	t_game;

//MOUSE//
void	change_by_mouse(t_game *game);
void	init_mouse(t_game *game);

//CHECK//
void	check_map_validity(t_game *game, char *map_path);
void	check_input_validity(int ac, char **av);
void	check_input_touch(t_game *game);
void	check_player(t_game *game);

int		check_color_info(t_game *game, char *line, char identifier);
int		check_if_closed(t_game *game);
int		line_is_only_char(char *line, int c);
int		line_is_empty(char *line);
int		char_is_spawn_pos(int c);
int		char_is_valid(int c);
int		is_whitespace(int c);

int		check_texture_info(t_game *game, char *line, char *identifier);
void	check_if_png(t_game *game, t_texture **texture);
void	check_info(t_game *game, char *line);
void	check_texture_files(t_game *game);

//EVENT//
int		mousedown_event(int keycode, void *game_data);
int		keydown_event(int keycode, void *game);
int		window_event(int value, void *game);
int		keydown_eventup(int keycode, void *game_data);

//RENDER//

void	render_by_view(t_game *game);
int		display_large_map(t_game *game, int x, int y);

//SET && INIT//
void	set_raycaster(t_game *game);
void	load_textures(t_game *game);
void	set_wall(t_game *game);
void	set_img(t_game *game);

int		load_map_data(t_game *game, int fd);
int		init_game(t_game *game);
void	init_textures(t_game *game);

//EXIT && FREE//
void	exit_game(t_game *game, char *error_message);
void	free_map(t_game *game, char **map);

//OTHER//
void	get_orientation(t_game **game, int orientation);
void	get_player_spawn_pos(t_game **game);

void	put_path_in_struct(t_game *game, char *line, char *identifier);
void	change_player_pos(int keycode, t_game *game);
void	change_angle(int keycode, t_game *game);
void	resize_map(t_game *game, int new_size);

void	set_minimap(t_game *game);
void	toogle_doors(t_game *game);
int		color_is_from_wall(int color);
int		get_current_animation_color(t_game *game);
void	*get_current_texture(t_game *game);
size_t	get_current_time(void);

int		open_file(t_game *game, char *map_path);
int		rgb(int r, int g, int b);

#endif
