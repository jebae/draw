/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:19:23 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:19:23 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		delete_color_scheme(t_palette *palette)
{
	ft_memdel((void **)&(palette->color_ctrl_point));
	ft_memdel((void **)&(palette->color_scheme));
}
