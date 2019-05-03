#ifndef DRAW_H
# define DRAW_H
# define ABS(N) ((N < 0) ? (-N) : (N))

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

void			plot_line(t_coord *p1, t_coord *p2, int (*mark_pixel)(t_coord *));

#endif
