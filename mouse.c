/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:00:40 by sadamant          #+#    #+#             */
/*   Updated: 2018/01/15 16:00:41 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

//there's a real and an imaginary part of the constant.
int			handle_mousemove(int x, int y, t_session *env)
{
	if (ft_strcmp(env->set->name, "julia") == 0)
	{
		env->set->constant_r = (x - (env->image->width / 2)) / \
			(double)(env->image->width / 2);
		env->set->constant_i = (y - (env->image->height / 2)) / \
			(double)(env->image->height / 2);
		draw_julia(env->image, env);
	}
	return (0);
}

int			handle_mousepress(int button, int x, int y, t_session *env)
{
	zoom(env, env->set, button, x, y);
	draw_set(env);
	return (0);
}
