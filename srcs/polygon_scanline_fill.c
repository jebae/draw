#include "draw.h"

void			iter(t_list *elem)
{
	t_edge	*edge;

	edge = (t_edge *)(elem->content);
	printf("%u %u %lf %lf\n\n",
		edge->y_min,
		edge->y_max,
		edge->x,
		edge->slope);
}

static void		init_g_edges(t_edge_list **alst, t_polygon *polygon)
{
	unsigned int	i;
	unsigned int	j;
	t_edge			edge;
	t_coord			*low;
	t_coord			*high;

	if (alst == NULL || polygon->v_count < 3)
		return ;
	i = 0;
	while (i < polygon->v_count)
	{
		j = (i + 1) % polygon->v_count;
		low = (polygon->vertices[i].y > polygon->vertices[j].y) ?
			&(polygon->vertices[j]) : &(polygon->vertices[i]);
		high = (&(polygon->vertices[j]) == low) ?
			&(polygon->vertices[i]) : &(polygon->vertices[j]);
		edge.slope = (float)(high->x - low->x) / (high->y - low->y);
		if (i++ && isinf(edge.slope))
			continue ;
		edge.y_min = low->y;
		edge.y_max = high->y;
		edge.x = low->x;
		ft_sorted_lstadd((t_list **)alst,\
				ft_lstnew(&edge, sizeof(edge)), &g_edge_compare);
	}
}

static void		update_a_edges(t_edge_list **a_edges,\
		int scanline)
{
	t_edge_list		*cur;
	t_edge_list		*pre;

	pre = NULL;
	cur = *a_edges;
	while (cur != NULL && cur->content->y_max == scanline)
	{
		*a_edges = cur->next;
		ft_lstdelone((t_list **)&cur, &lst_del);
		cur = *a_edges;
	}
	while (cur != NULL)
	{
		while (cur != NULL && cur->content->y_max != scanline)
		{
			cur->content->x += cur->content->slope;
			pre = cur;
			cur = cur->next;
		}
		if (cur == NULL)
			return ;
		pre->next = cur->next;
		ft_lstdelone((t_list **)&cur, &lst_del);
		cur = pre->next;
	}
}

static void		add_new_a_edges(t_edge_list **a_edges,\
		t_edge_list **g_edges, int scanline)
{
	while (*g_edges != NULL && (*g_edges)->content->y_min == scanline)
		ft_lstadd((t_list **)a_edges,\
				ft_sorted_lstpop((t_list **)g_edges));
	ft_lstsort((t_list **)a_edges, &a_edge_compare);
}

static void		fill_line(t_mlx *mlx, t_edge_list *a_edges,\
		int scanline, int (*mark_pixel)(t_mlx *, t_coord *, int))
{
	char			flag;
	t_coord			coord;
	t_edge_list		*cur;
	t_edge_list		*next;

	cur = a_edges;
	next = cur->next;
	coord.y = scanline;
	flag = 1;
	while (next != NULL)
	{
		if (flag)
		{
			coord.x = ceil(cur->content->x);
			mark_pixel(mlx, &coord, 0xff0000);
			while (++coord.x < next->content->x)
				mark_pixel(mlx, &coord, 0xff0000);
		}
		cur = cur->next;
		next = cur->next;
		flag ^= 1;
	}
}

void			polygon_scanline_fill(t_mlx *mlx, t_polygon *polygon,\
	int (*mark_pixel)(t_mlx *, t_coord *, int))
{
	int				scanline;
	t_edge_list		*g_edges;
	t_edge_list		*a_edges;

	g_edges = NULL;
	a_edges = NULL;
	init_g_edges(&g_edges, polygon);
	ft_lstiter((t_list *)g_edges, &iter);
	scanline = g_edges->content->y_min;
	while (1)
	{
		update_a_edges(&a_edges, scanline);
		add_new_a_edges(&a_edges, &g_edges, scanline);
		if (a_edges == NULL)
			return ;
		printf("\033[0;32mscanline : %d\n\033[0m", scanline);
		printf("\033[0;32medge\n\033[0m");
		ft_lstiter((t_list *)a_edges, &iter);
		fill_line(mlx, a_edges, scanline, mark_pixel);
		scanline++;
		printf("\n");
	}
}
