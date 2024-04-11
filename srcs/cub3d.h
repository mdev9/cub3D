/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:21:39 by marde-vr          #+#    #+#             */
/*   Updated: 2024/04/11 10:07:00 by axdubois         ###   ########.fr       */
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

//MOUSE//
void	change_by_mouse(t_game *game);
void	init_mouse(t_game *game);

//CHECK//
void	check_map_validity(t_game *game, char *map_path);
void	check_input_validity(int ac, char **av);

int		check_color_info(t_game *game, char *line, char identifier);
int		check_if_closed(t_game *game, int x, int y);
int		line_is_only_char(char *line, int c);
int		line_is_empty(char *line);
int		char_is_valid(int c);
int		is_whitespace(int c);

//EVENT//
int		mousedown_event(int keycode, void *game_data);
int		keydown_event(int keycode, void *game);
int		window_event(int value, void *game);

//RENDER//
void	render_map(t_game *game);

int		display_large_map(t_game *game, int x, int y);

//SET && INIT//
void	set_raycaster(t_game *game);
void	set_wall(t_game *game);
void	set_img(t_game *game);

int		load_map_data(t_game *game, int fd);

//EXIT && FREE//
void	exit_game(t_game *game, char *error_message);
void	free_map(t_game *game, char **map);

//OTHER//
void	put_path_in_struct(t_game *game, char *line, char *identifier);
void	resize_map(t_game *game, int new_size);

int		open_file(char *map_path);
int		rgb(int r, int g, int b);

#endif
