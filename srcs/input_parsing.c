/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:51:39 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/24 15:53:33 by marde-vr         ###   ########.fr       */
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

void	check_input_validity(int ac, char **av)
{
	check_arg_count(ac);
	check_file_extension(av[1]);
}
