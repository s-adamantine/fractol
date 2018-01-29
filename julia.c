/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 12:12:18 by sadamant          #+#    #+#             */
/*   Updated: 2018/01/04 12:12:24 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** z_new = z_oldˆ2 + c
** initial z_old is the sum of the coordinates.
*/
static int		iterate_julia(t_image *image, int *i, t_session *env, \
	double maxiter)
{
	int		iterations;
	double	z_new_r;
	double	z_new_i;
	double	z_old_r;
	double	z_old_i;

	iterations = 0;
	z_old_r = ((double)(*i % image->width) - image->width / 2 + \
		image->deplace_x) / (image->width / 2);
	z_old_i = ((double)(*i / image->height + image->deplace_y) - \
		image->height / 2) / (image->height / 2);
	while (iterations++ < maxiter)
	{
		z_new_r = (z_old_r * z_old_r) - (z_old_i * z_old_i) + \
			env->set->constant_r;
		z_new_i = (2 * z_old_r * z_old_i) + env->set->constant_i;
		z_old_r = z_new_r;
		z_old_i = z_new_i;
		if ((z_new_r * z_new_r) + (z_new_i * z_new_i) > 4)
			return (iterations + 1 - log(2) / (sqrt((z_new_r * z_new_r) + \
		 		(z_new_i * z_new_i))));
	}
	return (iterations);
}

/*
** c_r and c_i represent the position of the mouse cursor on the screen
** z_r and z_i initially represents the coordinates of the pixels
*/
void	draw_julia(t_image *image, t_session *env)
{
	int 	i;
	int		iterations;

	i = 0;
	while (i < (image->width * image->height))
	{
		iterations = iterate_julia(image, &i, env, image->view->maxiter);
		pixel_to_image(image, i % image->width, i / image->width, \
			grab_color(iterations));
		i++;
	}
	print_image(env);
}
