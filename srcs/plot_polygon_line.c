#include "draw.h"

void	plot_polygon_line(t_polygon *polygon, t_marker *marker)
{
	size_t					i;
	size_t					j;
	t_vec4					proj;
	t_coord					points[2];
	t_polygon_coefficient	co;

	marker->color = polygon->line_color;
	co = polygon_coefficient(polygon);
	i = 0;
	while (i < polygon->v_count)
	{
		j = (i + 1) % polygon->v_count;
		proj = marker->projection(&(polygon->vertices[i]));
		points[0] = (t_coord){(int)(proj.arr[0]), (int)(proj.arr[1])};
		proj = marker->projection(&(polygon->vertices[j]));
		points[1] = (t_coord){(int)(proj.arr[0]), (int)(proj.arr[1])};
		plot_line(&(points[0]), &(points[1]), &co, marker);
		i++;
	}
}
