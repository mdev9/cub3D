/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:42:36 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/25 19:42:42 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	return (r + g + b);
}

void	check_color(t_game *game, char *line, char identifier)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	r = ft_atoi(line);
	if (!(r >= 0 && r <= 255))
		exit_game(game, "Error\nInvalid or missing red color value!\n");
	while (ft_isdigit(line[i]))
		line += 1;
	while (is_whitespace(line[i]))
		*line += 1;
	g = ft_atoi(line);
	if (!(g >= 0 && g <= 255))
		exit_game(game, "Error\nInvalid or missing green color value!\n");
	while (ft_isdigit(line[i]))
		line += 1;
	while (is_whitespace(line[i]))
		*line += 1;
	b = ft_atoi(line);
	if (!(b >= 0 && b <= 255))
		exit_game(game, "Error\nInvalid or missing blue color value!\n");
	if (identifier == 'F')
	{
		game->floor_color = ft_calloc(1, sizeof(int));
		if (!game->floor_color)
			exit_game(game, 0);
		*game->floor_color = rgb(r, g, b);
	}
	if (identifier == 'C')
	{
		game->ceilling_color = ft_calloc(1, sizeof(int));
		if (!game->ceilling_color)
			exit_game(game, 0);
		*game->ceilling_color = rgb(r, g, b);
	}
}

int	check_color_info(t_game *game, char *line, char identifier)
{
	int	i;

	i = 0;
	while (is_whitespace(line[i]))
		*line += 1;
	if (line[i] == identifier)
	{
		*line += 1;
		while (is_whitespace(line[i]))
			*line += 1;
		check_color(game, line, identifier);
		return (1);
	}
	return (0);
}
