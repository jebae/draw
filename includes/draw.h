#ifndef DRAW_H
# define DRAW_H
# define ABS(N) ((N < 0) ? (-N) : (N))

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_polygon
{
	unsigned int		v_count;
	struct s_coord		*vertices;
}						t_polygon;

typedef struct			s_edge
{
	int					y_min;
	int					y_max;
	float				x;
	float				slope;
}						t_edge;

void			plot_line(t_coord *p1, t_coord *p2,\
	int (*mark_pixel)(t_coord *));

#endif
