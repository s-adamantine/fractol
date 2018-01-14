/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 20:48:02 by sadamant          #+#    #+#             */
/*   Updated: 2017/12/27 20:48:07 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	iterate_mandelbrot(double c_r, double c_i)
{
	double 	iterations;
	double	z_old_r;
	double	z_old_i;
	double	z_new_r;
	double	z_new_i;

	iterations = 0;
	z_old_r = (c_r * c_r) - (c_i * c_i) + c_r;
	z_old_i = (2 * c_r * c_i) + c_i;
	while (iterations++ < MAX_ITER)
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
** c_r and c_i are scaled to the screen until it encompasses all the interesting
** bits. represents the coordinates of each pixel on the screen.
*/
void			lance_mandelbrot(t_image *image)
{
	int		i;
	double	iterations;
	double	c_r;
	double	c_i;

	i = 0;
	while (i <= (image->width * image->height))
	{
		//c_r and c_i aren't quite right yet
		c_r = ((i % image->width) - (double) (0.75 * image->width)) \
			/ (double)(image->width / 3);
		c_i = ((i / image->width) - (double) image->height / 2) / \
			(double)(image->height / 3);
//		printf("c_r is: %f, and c_i is: %f\n", c_r, c_i);
		iterations = iterate_mandelbrot(c_r, c_i);
		// color = grab_color();
		// pixel_to_image(env, i % W_WIDTH, i / W_WIDTH, color);
		if (iterations < MAX_ITER)
			pixel_to_image(image, i % image->width, i / image->width, 0x000000FF);
		else
			pixel_to_image(image, i % image->width, i / image->width, 0xFFFFFFFF);
		i++;
	}
}
