#include "draw.h"

static int		calc_rgb(t_palette *palette, float mu, size_t i, size_t j)
{
	int			color;
	float		alpha;
	t_color		*p1;
	t_color		*p2;

	color = 0;
	p1 = &(palette->color_scheme[i]);
	p2 = &(palette->color_scheme[j]);
	alpha = (mu - palette->color_ctrl_point[i]) /\
		(palette->color_ctrl_point[j] - palette->color_ctrl_point[i]);
	color += (int)(p1->r + (p2->r - p1->r) * alpha);
	color <<= 8;
	color += (int)(p1->g + (p2->g - p1->g) * alpha);
	color <<= 8;
	color += (int)(p1->b + (p2->b - p1->b) * alpha);
	return (color);
}

int				pick_color(t_palette *palette, float mu)
{
	size_t		i;

	i = 0;
	while (i < palette->num_ctrl_point)
	{
		if (mu >= palette->color_ctrl_point[i] &&\
			mu < palette->color_ctrl_point[i + 1])
			return (calc_rgb(palette, mu, i, i + 1));
		i++;
	}
	return (0);
}
