/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:42:36 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/04 16:57:22 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_power(int n, int power)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (n);
	return (n * ft_power(n, power - 1));
}

int	rgb(int r, int g, int b)
{
	g = ((g / 16) * ft_power(16, 3)) + (g % 16) * ft_power(16, 2);
	r = ((r / 16) * ft_power(16, 5)) + (r % 16) * ft_power(16, 4);
	return (0xFF000000 + r + g + b);
}

void	go_to_next_color(t_game *game, char **line, char color)
{
	while (ft_isdigit(*line[0]))
		*line += 1;
	if (*line[0] == ',')
		*line += 1;
	else if (color == 'g')
		exit_game(game, "Error\nInvalid or missing green color value!\n");
	else
		exit_game(game, "Error\nInvalid or missing blue color value!\n");
	if (!ft_isdigit(*line[0]))
		exit_game(game, "Error\nInvalid or missing color value!\n");
}

void	check_color(t_game *game, char *line, char identifier)
{
	int	r;
	int	g;
	int	b;

	if (!ft_isdigit(line[0]))
		exit_game(game, "Error\nInvalid or missing red color value!\n");
	r = ft_atoi(line);
	if (!(r >= 0 && r <= 255))
		exit_game(game, "Error\nInvalid or missing red color value!\n");
	go_to_next_color(game, &line, 'g');
	g = ft_atoi(line);
	if (!(g >= 0 && g <= 255))
		exit_game(game, "Error\nInvalid or missing green color value!\n");
	go_to_next_color(game, &line, 'b');
	b = ft_atoi(line);
	if (!(b >= 0 && b <= 255))
		exit_game(game, "Error\nInvalid or missing blue color value!\n");
	while (ft_isdigit(*line))
		line++;
	if (*line != '\n')
		exit_game(game, "Error\nInvalid character(s) after color\n");
	if (identifier == 'F')
		game->floor_color = rgb(r, g, b);
	if (identifier == 'C')
		game->ceilling_color = rgb(r, g, b);
}

int	check_color_info(t_game *game, char *line, char identifier)
{
	int	i;

	i = 0;
	while (is_whitespace(line[i]))
		line += 1;
	if (line[i] == identifier)
	{
		line += 1;
		while (is_whitespace(line[i]))
			line += 1;
		check_color(game, line, identifier);
		return (1);
	}
	return (0);
}
