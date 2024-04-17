/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:15:22 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/17 14:45:50 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# define FOV 90
# define STEP 21
# define PI 3.141592653589793
# define SPEED 0.1
# define QUALITY 150
# define ROTPSEED 5

typedef struct s_raycaster
{
	double	sidedistx;
	double	sidedisty;
	double	dist;
	double	rayx;
	double	rayy;
	double	deltax;
	double	deltay;
	double	planex;
	double	planey;
	int		stepx;
	int		stepy;
	int		mapx;
	int		mapy;
	int		wall_size;
	int		wall_start;
	int		wall_end;
	int		is_d_map;
	int		color;
}	t_raycaster;

#endif
