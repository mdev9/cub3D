/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:41:57 by marde-vr          #+#    #+#             */
/*   Updated: 2024/03/25 18:40:32 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_game(t_game *game, char *error_message)
{
	if (game)
		//todo: free game
		free(game);
	if (error_message)
	{
		ft_printf(error_message);
		exit(1);
	}
	exit(0);
}
