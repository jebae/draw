/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_vertices.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:09:37 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 15:09:37 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_vec4		*projection_vertices(t_vec4 *vertices, size_t v_count,\
		t_vec4 (*projection)(t_vec4 *))
{
	size_t		i;
	t_vec4		*projections;

	projections = (t_vec4 *)ft_memalloc(sizeof(t_vec4) * v_count);
	i = 0;
	while (i < v_count)
	{
		projections[i] = projection(&(vertices[i]));
		i++;
	}
	return (projections);
}
