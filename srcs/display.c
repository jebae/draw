#include "draw.h"

static void		display_polygon(t_polygon polygon, t_mat4 *camera_mat,\
		t_marker *marker)
{
	size_t		i;

	i = 0;
	while (i < polygon.v_count)
	{
		polygon.vertices[i] = mat_mul_vec(camera_mat, &(polygon.vertices[i]));
		i++;
	}
	plot_polygon_line(&polygon, marker);
}

void			display(t_polygon *polygons, int polygon_size, t_mat4 *camera_mat,\
		t_marker *marker)
{
	int		i;

	i = 0;
	while (i < polygon_size)
	{
		display_polygon(polygons[i], camera_mat, marker);
		i++;
	}
}
