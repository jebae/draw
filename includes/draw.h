#ifndef DRAW_H
# define DRAW_H
# include <math.h>
# include <stdio.h> // remove after
# include "libft.h"
# include "gmath.h"
# define ABS(N) ((N < 0) ? -(N) : (N))

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
}						t_mlx;

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

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

void					plot_line(t_mlx *mlx, t_coord *p1, t_coord *p2,\
	int (*mark_pixel)(t_mlx *, t_coord *, int));

void					polygon_scanline_fill(t_mlx *mlx,\
		t_polygon *polygon, int (*mark_pixel)(t_mlx *, t_coord *, int));

int						g_edge_compare(t_list *a, t_list *b);

int						a_edge_compare(t_list *a, t_list *b);

void					lst_del(void *content, size_t content_size);

t_coord					*multi_project(t_vec4 *vecs, size_t v_count);

t_coord					project(t_vec4 *vecs);

#endif
