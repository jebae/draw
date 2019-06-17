/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_palette.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:26:13 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:26:57 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static t_palette		fractal_palette(t_color color_scheme[6])
{
	static double		color_ctrl_point[6] = {
		0.0, 0.16, 0.42, 0.6425, 0.8575, 1.0
	};
	t_palette			palette;

	palette.num_ctrl_point = 6;
	palette.color_ctrl_point = (double *)ft_memalloc(sizeof(double) *\
		palette.num_ctrl_point);
	palette.color_scheme = (t_color *)ft_memalloc(sizeof(t_color) *\
		palette.num_ctrl_point);
	ft_memcpy((void *)(palette.color_ctrl_point), (void *)color_ctrl_point,\
		sizeof(double) * palette.num_ctrl_point);
	ft_memcpy((void *)(palette.color_scheme), (void *)color_scheme,\
		sizeof(t_color) * palette.num_ctrl_point);
	return (palette);
}

t_palette				fractal_palette_blue(void)
{
	static t_color			color_scheme[6] = {
		(t_color){0, 7, 100},
		(t_color){32, 107, 203},
		(t_color){237, 255, 255},
		(t_color){255, 170, 0},
		(t_color){0, 2, 0},
		(t_color){0, 7, 100}
	};

	return (fractal_palette(color_scheme));
}

t_palette				fractal_palette_green(void)
{
	static t_color			color_scheme[6] = {
		(t_color){7, 100, 0},
		(t_color){107, 203, 32},
		(t_color){255, 255, 237},
		(t_color){170, 0, 255},
		(t_color){2, 0, 0},
		(t_color){7, 100, 0}
	};

	return (fractal_palette(color_scheme));
}

t_palette				fractal_palette_red(void)
{
	static t_color			color_scheme[6] = {
		(t_color){100, 0, 7},
		(t_color){203, 32, 107},
		(t_color){255, 237, 255},
		(t_color){0, 255, 170},
		(t_color){0, 0, 2},
		(t_color){100, 0, 7}
	};

	return (fractal_palette(color_scheme));
}
