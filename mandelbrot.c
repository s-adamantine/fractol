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

static double	grab_color(double iterations)
{
	int color;

	//magic values from left to right: frequency, phase, center, delta
	//delta is the maximum variation gap, center is the middle of the color
	//channel range, and the frequence and phase are arbitary values
	// color = sin(0.016 * iterations + 3) * 5056 + 5500;
	color = sin(0.036 * iterations + 5) * 5056 + 5500;
	return (color);
}

/*
** c_r and c_i are scaled to the screen until it encompasses all the interesting
** bits. represents the coordinates of each pixel on the screen.
*/
void			lance_mandelbrot(t_image *image, t_session *env)
{
	int		i;
	double	iterations;
	double	c_r;
	double	c_i;

	i = 0;
	while (i <= (image->width * image->height))
	{
		//c_r and c_i aren't quite right yet
		c_r = ((i % image->width) - (double) (0.75 * image->width) + \
			image->deplace_x) / (double)(image->width / (3 * image->zoom));
		c_i = ((i / image->width) - (double) (0.5 * image->height) + \
			image->deplace_y) / (double)(image->height / (3 * image->zoom));
//		printf("c_r is: %f, and c_i is: %f\n", c_r, c_i);
		iterations = iterate_mandelbrot(c_r, c_i);
		pixel_to_image(image, i % image->width, i / image->width, \
			grab_color(iterations));
		i++;
	}
	print_image(env);
}
