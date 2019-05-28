/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:09:23 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 15:09:24 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void		plot_line_low(t_coord *p1, t_coord *p2,\
		t_polygon_coefficient *co, t_marker *marker)
{
	int			dx;
	int			dy;
	int			yi;
	int			d;
	t_coord		p;

	p = *p1;
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	yi = 1;
	if (dy < 0 && (yi = -1))
		dy = -dy;
	d = 2 * dy - dx;
	while (p.x <= p2->x)
	{
		marker->mark_pixel(marker, &p, co);
		if (d > 0)
		{
			p.y += yi;
			d -= 2 * dx;
		}
		d += 2 * dy;
		p.x++;
	}
}

static void		plot_line_high(t_coord *p1, t_coord *p2,\
		t_polygon_coefficient *co, t_marker *marker)
{
	int			dx;
	int			dy;
	int			xi;
	int			d;
	t_coord		p;

	p = *p1;
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	xi = 1;
	if (dx < 0 && (xi = -1))
		dx = -dx;
	d = 2 * dx - dy;
	while (p.y <= p2->y)
	{
		marker->mark_pixel(marker, &p, co);
		if (d > 0)
		{
			p.x += xi;
			d -= 2 * dy;
		}
		d += 2 * dx;
		p.y++;
	}
}

void			plot_line(t_coord *p1, t_coord *p2,\
		t_polygon_coefficient *co, t_marker *marker)
{
	if (ABS(p2->x - p1->x) > ABS(p2->y - p1->y))
	{
		if (p2->x > p1->x)
			plot_line_low(p1, p2, co, marker);
		else
			plot_line_low(p2, p1, co, marker);
	}
	else
	{
		if (p2->y > p1->y)
			plot_line_high(p1, p2, co, marker);
		else
			plot_line_high(p2, p1, co, marker);
	}
}
