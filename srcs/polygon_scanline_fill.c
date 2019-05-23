#include "draw.h"

static void		init_g_edges(t_edge_list **alst, t_vec4 *vertices, size_t v_count)
{
	size_t			i;
	size_t			j;
	t_edge			edge;
	t_vec4			*low;
	t_vec4			*high;

	i = 0;
	while (i < v_count)
	{
		j = (i + 1) % v_count;
		if ((int)(vertices[i].arr[1]) != (int)(vertices[j].arr[1]))
		{
			low = (vertices[i].arr[1] > vertices[j].arr[1]) ?
				&(vertices[j]) : &(vertices[i]);
			high = (&(vertices[j]) == low) ? &(vertices[i]) : &(vertices[j]);
			edge.y_min = low->arr[1];
			edge.y_max = high->arr[1];
			edge.x = low->arr[0];
			edge.slope = (high->arr[0] - low->arr[0]) / (high->arr[1] - low->arr[1]);
			ft_sorted_lstadd((t_list **)alst,\
					ft_lstnew(&edge, sizeof(edge)), &g_edge_compare);
		}
		i++;
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

static void		fill_line(t_edge_list *a_edges, int scanline,\
		t_polygon_coefficient *co, t_marker *marker)
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
			marker->mark_pixel(marker, &coord, co);
			while (++coord.x < next->content->x)
				marker->mark_pixel(marker, &coord, co);
		}
		cur = cur->next;
		next = cur->next;
		flag ^= 1;
	}
}

void			polygon_scanline_fill(t_polygon *polygon, t_marker *marker)
{
	int						scanline;
	t_vec4					*projections;
	t_edge_list				*g_edges;
	t_edge_list				*a_edges;
	t_polygon_coefficient	co;

	marker->color = polygon->fill_color;
	g_edges = NULL;
	a_edges = NULL;
	co = polygon_coefficient(polygon);
	projections = projection_vertices(polygon->vertices,\
			polygon->v_count, marker->projection);
	init_g_edges(&g_edges, projections, polygon->v_count);
	ft_memdel((void **)&projections);
	scanline = (g_edges == NULL) ? 0 : g_edges->content->y_min;
	while (1)
	{
		update_a_edges(&a_edges, scanline);
		add_new_a_edges(&a_edges, &g_edges, scanline);
		if (a_edges == NULL)
			return ;
		fill_line(a_edges, scanline, &co, marker);
		scanline++;
	}
}
