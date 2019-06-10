/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:09:39 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 15:09:40 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void		render_polygon(t_polygon *polygon, t_mat4 *mat,\
		t_marker *marker)
{
	size_t		i;
	t_polygon	copy;

	i = 0;
	copy = new_polygon(polygon->v_count, polygon->line_color,\
		polygon->fill_color);
	while (i < copy.v_count)
	{
		copy.vertices[i] = mat_mul_vec(mat, &(polygon->vertices[i]));
		i++;
	}
	plot_polygon_line(&copy, marker);
	polygon_scanline_fill(&copy, marker);
	ft_memdel((void **)&(copy.vertices));
}

void			render(t_polygon *polygons, size_t polygon_count,\
	t_camera *cam, t_marker *marker)
{
	size_t		i;
	t_mat4		mat;

	init_z_buffer((float *)(marker->z_buf));
	mat = camera_mat(cam);
	i = 0;
	while (i < polygon_count)
		render_polygon(&(polygons[i++]), &mat, marker);
}
