# draw

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/38dce5eda1fe40f2a83e9658df550d1e)](https://www.codacy.com/manual/jebae/draw?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=jebae/draw&amp;utm_campaign=Badge_Grade)

C library **draw** is made to render line and polygon with specified projection. It uses *minilibx* as renderer which is school library.

<br><br>

## Requirements

This library is using [libft](https://github.com/jebae/libft) and [gmath](https://github.com/jebae/gmath).

```
# download libft
git clone https://github.com/jebae/libft.git

# download gmath
git clone https://github.com/jebae/gmath.git

# directory structure
root/
  libft/
  gmath/
  draw/
```

Instead of putting required libraries in same path with rt, you can modify [Makefile](./Makefile) macro written below.

```c
LIBFT_PATH = ../libft

GMATH_PATH = ../gmath
```

<br><br>

## Installation

```
make
```

<br><br>

## Features

### marker

```c
typedef struct		s_marker
{
	float		width;
	float		height;
	int		color;
	void		*p_mlx;
	void		*p_win;
	void		*p_img;
	t_palette	*palette;
	t_vec4		(*projection)(t_vec4 *vertex);
	float		(*calculate_z)(int, int, t_polygon_coefficient *);
	int		(*mark_pixel)(struct s_marker *, t_coord *, t_polygon_coefficient *);
	float		*z_buf;
}			t_marker;
```

`t_marker` save features and mark pixel with color.

`projection` function pointer can be assigned with `parallel_projection` or `perspective_projection` of [gmath](https://github.com/jebae/gmath).

`calculate_z` function pointer can be assigned with `cal_parallel_proj_z` or `cal_perspective_proj_z` according to each projection.


<br>

### line

```c
void plot_line(
	t_coord *p1,
	t_coord *p2,
	t_polygon_coefficient *co,
	t_marker *marker
);
```

`plot_line` draw line between point `p1` and `p2`. It uses *bresenham's line algorithm*.

<br>

### fill

```c
void polygon_scanline_fill(t_polygon *polygon, t_marker *marker);
```

`polygon_scanline_fill` fill color of polygon with *scanline fill algorithm*.