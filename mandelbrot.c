/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 20:48:02 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/19 16:41:17 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static double	iterate_mandelbrot(double c_r, double c_i, double maxiter)
{
	double	iterations;
	double	z_old_r;
	double	z_old_i;
	double	z_new_r;
	double	z_new_i;

	iterations = 0;
	z_old_r = (c_r * c_r) - (c_i * c_i) + c_r;
	z_old_i = (2 * c_r * c_i) + c_i;
	while (iterations++ < maxiter)
	{
		z_new_r = (z_old_r * z_old_r) - (z_old_i * z_old_i) + c_r;
		z_new_i = (2 * z_old_r * z_old_i) + c_i;
		z_old_r = z_new_r;
		z_old_i = z_new_i;
		if ((z_new_r * z_new_r) + (z_new_i * z_new_i) > 4)
			return (iterations + 1 - log(2) / (sqrt((z_new_r * z_new_r) + \
				(z_new_i * z_new_i))));
	}
	return (iterations);
}

/*
** need to loop depending on the number of thread it is on
*/
void			*loop_window(void *e)
{
	int			i;
	int			I;
	double		iterations;
	double		c_r;
	double		c_i;
	t_session	*env;
	t_image		*image;

	env = (t_session *)e;
	image = env->image;
	i = ((image->width * image->height) / N_THREAD) * (image->nthread - 1);
	I = ((image->width * image->height) / N_THREAD) * (image->nthread);
	printf("n: %d, i: %d, I:%d\n", image->nthread, i, I);
	while (i < I)
	{
		c_r = ((i % image->width) - (double)(0.75 * image->width) + \
			image->deplace_x) / (double)(image->width / (3 * image->zoom));
		c_i = ((i / image->width) - (double)(0.5 * image->height) + \
			image->deplace_y) / (double)(image->height / (3 * image->zoom));
		iterations = iterate_mandelbrot(c_r, c_i, env->set->maxiter);
		pixel_to_image(image, i % image->width, i / image->width, \
			grab_color(iterations));
		i++;
	}
	return (NULL);
}

void			draw_mandelbrot(t_session *env)
{
	int			n;
	pthread_t	tid[N_THREAD];

	n = 0;
	while (n <= N_THREAD)
	{		
		env->image->nthread = n;
		pthread_create(&tid[n], NULL, loop_window, env);
		n++;
	}
	n = 0;
	while (n <= N_THREAD)
		pthread_join(tid[n++], NULL);
	print_image(env);
}
