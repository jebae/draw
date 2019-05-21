#include "draw.h"

void		parallel_proj_marker(t_marker *marker, void *p_mlx, void *p_win)
{
	marker->p_mlx = p_mlx;
	marker->p_win = p_win;
	marker->projection = &parallel_projection;
	marker->calculate_z = &cal_parallel_proj_z;
	marker->mark_pixel = &z_buffer_mark_pixel;
	init_z_buffer((float *)(marker->z_buf));
}

void		perspective_proj_marker(t_marker *marker, void *p_mlx, void *p_win)
{
	marker->p_mlx = p_mlx;
	marker->p_win = p_win;
	marker->projection = &perspective_projection;
	marker->calculate_z = &cal_perspective_proj_z;
	marker->mark_pixel = &z_buffer_mark_pixel;
	init_z_buffer((float *)(marker->z_buf));
}
