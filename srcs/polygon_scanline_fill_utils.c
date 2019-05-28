/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polygon_scanline_fill_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:09:32 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 15:09:33 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int			g_edge_compare(t_list *a, t_list *b)
{
	t_edge	*edge_a;
	t_edge	*edge_b;

	edge_a = (t_edge *)(a->content);
	edge_b = (t_edge *)(b->content);
	if (edge_a->y_min > edge_b->y_min)
		return (1);
	else if (edge_a->y_min < edge_b->y_min)
		return (-1);
	if (edge_a->x > edge_b->x)
		return (1);
	return (-1);
}

int			a_edge_compare(t_list *a, t_list *b)
{
	t_edge	*edge_a;
	t_edge	*edge_b;

	edge_a = (t_edge *)(a->content);
	edge_b = (t_edge *)(b->content);
	if (edge_a->x > edge_b->x)
		return (1);
	return (-1);
}

void		lst_del(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}
