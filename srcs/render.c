#include "draw.h"

static void		render_polygon(t_polygon *polygon, t_mat4 *mat,\
		t_marker *marker)
{
	size_t		i;
	t_polygon	copy;

	i = 0;
	copy = *polygon;
	copy.vertices = (t_vec4 *)ft_memalloc(sizeof(t_vec4) * polygon.v_count);
	while (i < polygon.v_count)
	{
		polygon.vertices[i] = mat_mul_vec(mat, &(polygon.vertices[i]));
		i++;
	}
	#ifdef DEBUG
		printf("copy vertice 1 : %.2f %.2f %.2f\n",\
			polygon.vertices[0].arr[0],
			polygon.vertices[0].arr[1],
			polygon.vertices[0].arr[2]);
	#endif
	plot_polygon_line(&polygon, marker);
	polygon_scanline_fill(&polygon, marker);
}

void			render(t_polygon *polygons, size_t polygon_count, t_camera *cam,\
		t_marker *marker)
{
	size_t		i;
	t_mat4		mat;

	mat = camera_mat(cam);
	i = 0;
	while (i < polygon_count)
	{
		#ifdef DEBUG
			printf(KGRN "polygon %zu enter\n" KNRM, i);
			printf("vertice 1 : %.2f %.2f %.2f\n",\
				polygons[i].vertices[0].arr[0],
				polygons[i].vertices[0].arr[1],
				polygons[i].vertices[0].arr[2]);
		#endif
		render_polygon(&(polygons[i]), &mat, marker);
		#ifdef DEBUG
			printf(KGRN "polygon %zu out\n" KNRM, i);
		#endif
		i++;
	}
}
