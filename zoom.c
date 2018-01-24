/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:27:12 by sadamant          #+#    #+#             */
/*   Updated: 2018/01/19 15:27:19 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** take the initial c_r and c_i mins and maxs and interpolate it w/ each
** movement.
** the x and y positions have to be in the complex scaled number form
** is either in grab_initial_c or in grab_zoomed_c depending on whether it's
** been zoomed once before.
*/

static void		grab_windowspan(t_image *image, int x, int y)
{
	double	change;

	change = (image->c_r_max - image->c_r_min) * image->zoom;
	image->c_r_min = image->c_r_min + (change * (x / image->width));
	image->c_r_max = image->c_r_max - (change * (1 - x / image->width));
	change = (image->c_i_max - image->c_i_min) * image->zoom;
	image->c_i_min = image->c_i_min + (change * (y / image->width));
	image->c_i_max = image->c_i_max - (change * (1 - y / image->width));
}

void			zoom(t_session *env, t_set *set, int button, int x, int y)
{
	if (set)
		printf("");
	if (button == SCROLL_UP || button == CLICK)
		env->image->zoom *= 0.90;
	else if (button == SCROLL_DOWN)
		env->image->zoom *= 1.10;
	grab_windowspan(env->image, x, y);
	draw_set(env);
}
