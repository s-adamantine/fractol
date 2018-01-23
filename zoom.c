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

void			zoom(t_session *env, t_set *set, int button, int x, int y)
{
	if (x || y || set)
		printf("");
	if (button == SCROLL_UP || button == CLICK)
		env->image->zoom *= 0.99;
	else if (button == SCROLL_DOWN)
		env->image->zoom *= 1.01;
	draw_set(env);
}
