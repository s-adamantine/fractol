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
** every time you zoom in or out, you increase or decrease this value by
** 0.05
** take the initial c_r and c_i mins and maxs and interpolate it w/ each
** movement.
** the x and y positions have to be in the complex scaled number form
** is either in grab_initial_c or in grab_zoomed_c depending on whether it's
** been zoomed once before.
*/

void			zoom(t_session *env, t_set *set, int button)
{
	printf("1. zoom!\n");
	if (button == SCROLL_UP || button == CLICK)
		env->image->zoom *= 0.99;
	else if (button == SCROLL_DOWN)
		env->image->zoom *= 1.01;
	printf("c_r_min: %f, c_r_max: %f, c_i_min: %f, c_i_max: %f\n", \
		env->set->constant_r_min, env->set->constant_r_max,\
		 env->set->constant_i_min, env->set->constant_i_max);
	printf("after interpolating, c_r_min: %f, c_r_max: %f, c_i_min: %f, c_i_max: %f\n", \
		env->set->constant_r_min, env->set->constant_r_max,\
		 env->set->constant_i_min, env->set->constant_i_max);
	draw_set(env);
}
