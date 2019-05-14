#include "draw.h"

t_coord		*mul_perspective_proj(t_vec4 *vecs, size_t v_count)
{
	size_t		i;
	t_coord		*coords;

	coords = (t_coord *)malloc(sizeof(t_coord) * v_count);
	i = 0;
	while (i < v_count)
	{
		coords[i] = perspective_proj(&(vecs[i]));
		i++;
	}
	return (coords);
}

t_coord		perspective_proj(t_vec4 *vecs)
{
	t_coord		coord;

	coord.x = vecs->arr[0] / vecs->arr[2];
	coord.y = vecs->arr[1] / vecs->arr[2];
	return (coord);
}
