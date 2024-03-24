/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:11:52 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/24 15:18:45 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_arg_count(int ac)
{
	if (ac < 2)
		ft_printf("Error\nNo map give as a parameter!\n");
	else if (ac > 2)
		ft_printf("Error\nToo many arguments!\n");
	if (ac != 2)
		exit(1);
}

int	is_cub_file(char *path)
{
	int	cub_extension;
	int i;
	int j;

	cub_extension = 0;
	i = 0;
	j = 0;
	while (path[i] && j < 4)
	{
		if (path[i] == '.')
		{
			j = 0;
			while (path[i] == ".cub"[j] && j < 4)
			{
				i++;
				j++;
				if (j == 4)
				cub_extension = 1;
			}
			if (path[i] != '\0')
				cub_extension = 0;
		}
		i++;
	}
	return (cub_extension);
}

void	check_file_extension(char *path)
{
	if (!is_cub_file(path))
	{
		ft_printf("Error\nThe map must be a .cub file!\n");
		exit(1);
	}
}

int	open_file(char *map_path)
{
	int fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit(1);
	}
	return (fd);
}

int	expand_map_struct(t_game *game, char *line)
{
	char	**res_map;
	int		i;

	res_map = malloc(sizeof(char *) * (game->map_size + 1));
	if (!res_map)
		return (3);
	i = 0;
	while (i < game->map_size)
	{
		res_map[i] = game->map[i];
		i++;
	}
	res_map[i] = line;
	free(game->map);
	game->map = res_map;
	return (0);
}

int	load_map_data(t_game *game, int fd)
{
	char	*line;
	char	**map;

	line = get_next_line(fd);
	if (!line)
		return (8);
	map = malloc(sizeof(char *) * 2);
	if (!map)
		return (3);
	map[0] = line;
	game->map_size = 1;
	game->map = map;
	while (line)
	{
		line = get_next_line(fd);
		if (!line || !*line)
		{
			break ;
		}
		if (expand_map_struct(game, line))
			return (3);
		game->map_size++;
	}
	return (0);
}

void	check_input_validity(int ac, char **av)
{
	check_arg_count(ac);
	check_file_extension(av[1]);
}

void	check_if_map_valid(t_game *game)
{
	(void) game;
	//check if map valid
}

void	check_map_validity(t_game *game, char *map_path)
{
	int		map_fd;
	
	map_fd = open_file(map_path);
	load_map_data(game, map_fd);
	check_if_map_valid(game);
}
