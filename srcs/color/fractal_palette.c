#include "draw.h"

t_palette		fractal_palette()
{
	float			color_ctrl_point[6] = {
		0.0f, 0.16f, 0.42f, 0.6425f, 0.8575f, 1.0f
	};
	t_color			color_scheme[6] = {
			(t_color){0, 7, 100},
			(t_color){32, 107, 203},
			(t_color){237, 255, 255},
			(t_color){255, 170, 0},
			(t_color){0, 2, 0},
			(t_color){0, 7, 100}
	};
	t_palette		palette;

	palette.num_ctrl_point = 6;
	palette.color_ctrl_point = (float *)ft_memalloc(sizeof(float) *\
		palette.num_ctrl_point);
	palette.color_scheme = (t_color *)ft_memalloc(sizeof(t_color) *\
		palette.num_ctrl_point);
	ft_memcpy((void *)(palette.color_ctrl_point), (void *)color_ctrl_point,\
		sizeof(float) * palette.num_ctrl_point);
	ft_memcpy((void *)(palette.color_scheme), (void *)color_scheme,\
		sizeof(t_color) * palette.num_ctrl_point);
	return (palette);
}
