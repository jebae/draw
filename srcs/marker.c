/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:09:20 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 15:09:21 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

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
