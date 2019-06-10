/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_buffer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:09:42 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 15:09:43 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int			z_buffer_mark_pixel(t_marker *marker, t_coord *origin,\
		t_polygon_coefficient *co)
{
	static int		x_to_move = WIDTH / 2;
	static int		y_to_move = HEIGHT / 2;
	t_coord			p;
	float			z;

	p.x = origin->x + x_to_move;
	p.y = origin->y + y_to_move;
	if (p.x < 0 || p.x > WIDTH - 1 ||\
			p.y < 0 || p.y > HEIGHT - 1)
		return (0);
	z = marker->calculate_z(origin->x, origin->y, co);
	if (marker->z_buf[p.y][p.x] > z)
	{
		mlx_pixel_put(marker->p_mlx, marker->p_win, p.x, p.y, marker->color);
		marker->z_buf[p.y][p.x] = z;
	}
	return (0);
}

void		init_z_buffer(float *z_buf)
{
	size_t		i;
	size_t		size;

	size = WIDTH * HEIGHT;
	i = 0;
	while (i < size)
	{
		z_buf[i] = INFINITY;
		i++;
	}
}
