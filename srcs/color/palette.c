#include "draw.h"

void		delete_color_scheme(t_palette *palette)
{
	ft_memdel((void **)&(palette->color_ctrl_point));
	ft_memdel((void **)&(palette->color_scheme));
}
