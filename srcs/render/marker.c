/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:09:20 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:27:19 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int			mark_pixel(t_marker *marker, t_coord *coord,\
	t_polygon_coefficient *co)
{
	if (co != NULL)
		co = NULL;
	mlx_pixel_put(marker->p_mlx, marker->p_win,\
		coord->x, coord->y, marker->color);
	return (0);
}

void		parallel_proj_marker(t_marker *marker)
{
	marker->projection = &parallel_projection;
	marker->calculate_z = &cal_parallel_proj_z;
	marker->mark_pixel = &z_buffer_mark_pixel;
}

void		perspective_proj_marker(t_marker *marker)
{
	marker->projection = &perspective_projection;
	marker->calculate_z = &cal_perspective_proj_z;
	marker->mark_pixel = &z_buffer_mark_pixel;
}
