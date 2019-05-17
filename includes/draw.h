#ifndef DRAW_H
# define DRAW_H
# include <math.h>
# include <stdio.h> // remove after
# include "libft.h"
# include "gmath.h"
# define WIDTH 1000
# define HEIGHT 800
# define PADDING 30
# define ABS(N) ((N < 0) ? -(N) : (N))

typedef struct			s_mlx
{
	void				*p_mlx;
	void				*p_win;
}						t_mlx;

typedef struct  		s_marker
{
    t_mlx       		mlx;
	t_coord				(*projection)(t_vec4 *vertex);
    int         		(*mark_pixel)(t_mlx *, t_coord *, int);
}               		t_marker;

typedef struct			s_polygon
{
	size_t				v_count;
	struct s_vec4		*vertices;
}						t_polygon;

typedef struct			s_edge
{
	int					y_min;
	int					y_max;
	float				x;
	float				slope;
}						t_edge;

typedef struct			s_edge_list
{
	struct s_edge		*content;
	size_t				content_size;
	struct s_edge_list	*next;
}						t_edge_list;

void					plot_line(t_coord *p1, t_coord *p2, t_marker *marker);

void					plot_polygon_line(t_polygon *polygon, t_marker *marker);

void					polygon_scanline_fill(t_mlx *mlx,\
		t_polygon *polygon, int (*mark_pixel)(t_mlx *, t_coord *, int));

int						g_edge_compare(t_list *a, t_list *b);

int						a_edge_compare(t_list *a, t_list *b);

void					lst_del(void *content, size_t content_size);

t_coord					*mul_perspective_proj(t_vec4 *vecs, size_t v_count);

t_coord					perspective_proj(t_vec4 *vecs);

void					display(t_polygon *polygons, int polygon_size, t_mat4 *camera_mat,\
		t_marker *marker);

#endif
