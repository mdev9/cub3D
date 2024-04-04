/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:15:22 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/04 19:24:46 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef raycaster_H
#define raycaster_H

# define FOV 90
# define STEP 1920 / 90

typedef struct s_raycaster
{
	double	dist;
	double	ray;
	int		wall_sizey;
	int		wall_starty;
	int		wall_endy;
	
}	t_raycaster;


#endif
