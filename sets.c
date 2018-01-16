/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 11:01:55 by sadamant          #+#    #+#             */
/*   Updated: 2018/01/16 11:02:00 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_set(t_session *env)
{
	if (ft_strcmp(env->set->name, "julia") == 0)
		draw_julia(env->image, env);
	else if (ft_strcmp(env->set->name, "mandelbrot") == 0)
		draw_mandelbrot(env->image, env);
	else if (ft_strcmp(env->set->name, "burningship") == 0)
		draw_burningship(env->image, env);
	else if (ft_strcmp(env->set->name, "tricorn") == 0)
		draw_tricorn(env->image, env);
}
