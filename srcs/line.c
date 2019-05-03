#include "draw.h"

static void		plot_line_low(t_coord *p1, t_coord *p2, int (*mark_pixel)(t_coord *))
{
	int			dx;
	int			dy;
	int			yi;
	int			D;
	t_coord		p;

	p = *p1;
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	yi = 1;
	if (dy < 0 && (yi = -1))
		dy = -dy;
	D = 2 * dy - dx;
	while (p.x <= p2->x)
	{
		mark_pixel(&p);
		if (D > 0)
		{
			p.y += yi;
			D -= 2 * dx;
		}
		D += 2 * dy;
		p.x++;
	}
}

static void		plot_line_high(t_coord *p1, t_coord *p2, int (*mark_pixel)(t_coord *))
{
	int			dx;
	int			dy;
	int			xi;
	int			D;
	t_coord		p;

	p = *p1;
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	xi = 1;
	if (dx < 0 && (xi = -1))
		dx = -dx;
	D = 2 * dx - dy;
	while (p.y <= p2->y)
	{
		mark_pixel(&p);
		if (D > 0)
		{
			p.x += xi;
			D -= 2 * dy;
		}
		D += 2 * dx;
		p.y++;
	}
}

void			plot_line(t_coord *p1, t_coord *p2, int (*mark_pixel)(t_coord *))
{
	if (ABS(p2->x - p1->x) > ABS(p2->y - p1->y))
	{
		if (p2->x > p1->x)
			plot_line_low(p1, p2, mark_pixel);
		else
			plot_line_low(p2, p1, mark_pixel);
	}
	else
	{
		if (p2->y > p1->y)
			plot_line_high(p1, p2, mark_pixel);
		else
			plot_line_high(p2, p1, mark_pixel);
	}
}
