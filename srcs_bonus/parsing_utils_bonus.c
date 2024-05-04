/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:44:54 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/04 16:24:28 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	char_is_valid(int c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == '\n' || c == 'A' || c == 'D')
		return (1);
	return (0);
}

int	is_whitespace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	line_is_empty(char *line)
{
	int	i;

	i = 0;
	while (is_whitespace(line[i]))
		i++;
	if (!line[i])
		return (1);
	return (0);
}

int	line_is_only_char(char *line, int c)
{
	int	i;

	i = 0;
	while (is_whitespace(line[i]))
		i++;
	while (line[i])
	{
		if (line[i] != c && line[i] != '\n' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	char_is_spawn_pos(int c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}
