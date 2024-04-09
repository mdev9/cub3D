/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:15:22 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/09 13:39:46 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# define FOV 90
# define STEP 21
# define PI 3.141592653589793
# define SPEED 0.1
# define ANTIALIASING 150

typedef struct s_raycaster
{
	double	dist;
	double	ray;
	double	deltax;
	double	deltay;
	int		wall_size;
	int		wall_start;
	int		wall_end;
	int		is_d_map;
}	t_raycaster;

#endif
