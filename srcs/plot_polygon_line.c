#include "draw.h"

void	plot_polygon_line(t_polygon *polygon, t_marker *marker)
{
	size_t		i;
	size_t		j;
	t_coord		p1;
	t_coord		p2;

	i = 0;
	while (i < polygon->v_count)
	{
		j = (i + 1) % polygon->v_count;
		p1 = marker->projection(&(polygon->vertices[i]));
		p2 = marker->projection(&(polygon->vertices[j]));
		plot_line(&p1, &p2, marker);
		i++;
	}
}
