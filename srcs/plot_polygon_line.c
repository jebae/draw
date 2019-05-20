#include "draw.h"

void	plot_polygon_line(t_polygon *polygon, t_marker *marker)
{
	size_t		i;
	size_t		j;
	t_vec4		proj;
	t_coord		p1;
	t_coord		p2;

	i = 0;
	while (i < polygon->v_count)
	{
		j = (i + 1) % polygon->v_count;
		proj = marker->projection(&(polygon->vertices[i]));
		p1 = (t_coord){(int)(proj.arr[0]), (int)(proj.arr[1])};
		proj = marker->projection(&(polygon->vertices[j]));
		p2 = (t_coord){(int)(proj.arr[0]), (int)(proj.arr[1])};
		plot_line(&p1, &p2, marker);
		i++;
	}
}
