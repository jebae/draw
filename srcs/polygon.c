#include "draw.h"

static void		fill_line(t_edge *a_edge_tab, size_t len)
{

}

/*
	mark_pixel in this case have to consider HSR
*/
void			fill_polygon(t_polygon *polygon, int (*mark_pixel)(t_coord *))
{
	// init edge_tab and first g_edge_tab (require sort)

	/* loop
		1. scanline = min y value of g_edge_tab first edge
		2. make a_edge_tab by scanline
		3. fill_line(a_edge_tab, length of a_edge_tab)
		4. scanline++
		5. remove edge from a_edge_table which max y is scanline
		6. x = x + 1/m
		7. add edge from g_edge_tab which min y is scanline
		8. a_edge_tab sort
	*/
}
