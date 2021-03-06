/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:00:40 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/01 15:39:56 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	zoom_factor(int button, double zoom)
{
	if (button == SCROLL_UP)
		zoom *= 0.9;
	else if (button == SCROLL_DOWN)
		zoom *= 1.1;
	return (zoom);
}

int				handle_mousemove(int x, int y, t_session *env)
{
	if (ft_strcmp(env->set->name, "julia") == 0)
	{
		env->set->constant_real = (x - (env->image->width / (2 * \
			env->image->zoom))) / (double)(env->image->width / (2 * \
			env->image->zoom));
		env->set->constant_i = (y - (env->image->height / (2 * \
			env->image->zoom))) / (double)(env->image->height / \
				(2 * env->image->zoom));
		draw_julia(env->image, env);
	}
	return (0);
}

int				handle_mousepress(int button, int x, int y, t_session *env)
{
	if (x || y)
		ft_putstr("");
	env->image->zoom = zoom_factor(button, env->image->zoom);
	draw_set(env);
	return (0);
}
