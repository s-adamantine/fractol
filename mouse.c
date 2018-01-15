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
int		handle_mousemove(int x, int y, t_session *env)
{
	if (ft_strcmp(env->set->name, "julia") == 0)
	{
		env->set->constant_real = (x / (double)(env->image->width / 2));
		env->set->constant_i = (y / (double)(env->image->height / 2));
		printf("the real number: %f\n", env->set->constant_real);
		printf("the imaginary number: %f\n", env->set->constant_i);
		lance_julia(env->image);
	}
	return (0);
}
