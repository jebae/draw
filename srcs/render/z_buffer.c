/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_buffer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:09:42 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 15:47:03 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int			z_buffer_mark_pixel(t_marker *marker, t_coord *origin,\
		t_polygon_coefficient *co)
{
	int			x_to_move;
	int			y_to_move;
	t_coord		p;
	float		z;

	x_to_move = marker->width / 2.0f;
	y_to_move = marker->height / 2.0f;
	p.x = origin->x + x_to_move;
	p.y = origin->y + y_to_move;
	if (p.x < 0 || p.x > marker->width - 1 ||\
			p.y < 0 || p.y > marker->height - 1)
		return (0);
	z = marker->calculate_z(origin->x, origin->y, co);
	if (marker->z_buf[p.y * (int)(marker->width) + p.x] > z)
	{
		mlx_pixel_put(marker->p_mlx, marker->p_win, p.x, p.y, marker->color);
		marker->z_buf[p.y * (int)(marker->width) + p.x] = z;
	}
	return (0);
}

void		new_z_buffer(t_marker *marker)
{
	marker->z_buf = ft_memalloc(sizeof(float) * marker->width * marker->height);
}

void		init_z_buffer(t_marker *marker)
{
	size_t		i;
	size_t		size;

	size = marker->width * marker->height;
	i = 0;
	while (i < size)
	{
		marker->z_buf[i] = INFINITY;
		i++;
	}
}
