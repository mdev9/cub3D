/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:15:22 by axdubois          #+#    #+#             */
/*   Updated: 2024/04/02 13:32:40 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef raycaster_H
#define raycaster_H

# define FOV 90

typedef struct s_raycaster
{
	double	deltax;
	double	deltay;
	double	distx;
	double	disty;
	int		angle;
}	t_raycaster;


#endif
