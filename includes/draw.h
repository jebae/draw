/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:09:14 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 15:47:15 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <math.h>
# include <mlx.h>
# include "libft.h"
# include "gmath.h"
# define MLX_BPP		32
# define MLX_ENDIAN		0

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

# ifndef RT_H
typedef struct			s_color
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_color;
# endif

typedef struct			s_palette
{
	size_t				num_ctrl_point;
	double				*color_ctrl_point;
	t_color				*color_scheme;
}						t_palette;

typedef struct			s_marker
{
	float				width;
	float				height;
	int					color;
	void				*p_mlx;
	void				*p_win;
	void				*p_img;
	t_palette			*palette;
	t_vec4				(*projection)(t_vec4 *vertex);
	float				(*calculate_z)(int, int, t_polygon_coefficient *);
	int					(*mark_pixel)(struct s_marker *, t_coord *,\
			t_polygon_coefficient *);
	float				*z_buf;
}						t_marker;

/*
** line
*/
void					plot_line(t_coord *p1, t_coord *p2,\
	t_polygon_coefficient *co, t_marker *marker);

/*
** polygon
*/
void					plot_polygon_line(t_polygon *polygon, t_marker *marker);
void					polygon_scanline_fill(t_polygon *polygon,\
	t_marker *marker);
int						g_edge_compare(t_list *a, t_list *b);
int						a_edge_compare(t_list *a, t_list *b);
t_vec4					*projection_vertices(t_vec4 *vertices, size_t v_count,\
	t_vec4 (*projection)(t_vec4 *));

/*
** marker
*/
int						mark_pixel(t_marker *marker, t_coord *coord,\
	t_polygon_coefficient *co);
void					parallel_proj_marker(t_marker *marker);
void					perspective_proj_marker(t_marker *marker);

/*
** utils
*/
void					lst_del(void *content, size_t content_size);

/*
** display
*/
void					render(t_polygon *polygons, size_t polygon_count,\
	t_camera *cam, t_marker *marker);

/*
** z buffer
*/
void					new_z_buffer(t_marker *marker);
int						z_buffer_mark_pixel(t_marker *marker, t_coord *origin,\
	t_polygon_coefficient *co);
void					init_z_buffer(t_marker *marker);

/*
** palette
*/
int						pick_color(t_palette *palette, double mu);
void					delete_color_scheme(t_palette *palette);
t_palette				fractal_palette_red(void);
t_palette				fractal_palette_green(void);
t_palette				fractal_palette_blue(void);

#endif
