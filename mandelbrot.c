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

static double	iterate_mandelbrot(double c_r, double c_i, double maxiter)
{
	double 	iterations;
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
** find the leftmost, the rightmost, the topmost, and rightmost c values that
** would encompass all the intresting bits in mandelbrot.
*/
void		grab_initial_c(t_image *image, t_view *view)
{
	image->c_r_min = (image->width * view->xoffset) / (image->width / \
		(image->zoom * view->initialzoom));
	image->c_i_min = (image->width * view->yoffset) / (image->height / \
		(image->zoom * view->initialzoom));
	image->c_r_max = (image->width - 1 + (image->width * view->xoffset)) / \
		(image->width / (image->zoom * view->initialzoom));
	image->c_i_max = (image->height - 1 + (image->width * view->yoffset)) / \
		(image->height / (image->zoom * view->initialzoom));
}

/*
** c_r and c_i are scaled to the screen until it encompasses all the interesting
** bits. represents the coordinates of each pixel on the screen.
*/
void			draw_mandelbrot(t_image *image, t_session *env)
{
	int		i;
	double	iterations;
	double	c_r;
	double	c_i;

	i = -1;
	if (image->zoom == 1)
		grab_initial_c(image, image->view);
	image->interval_x = (image->c_r_max - image->c_r_min) / (image->width - 1);
	image->interval_y = (image->c_i_max - image->c_i_min) / (image->height);
	c_i = image->c_i_min;
	while (++i < (image->width * image->height))
	{
		if (i % image->width == 0)
			c_r = image->c_r_min;
		else
			c_r += image->interval_x;
		if (i % image->height == 0)
			c_i += image->interval_y;
		iterations = iterate_mandelbrot(c_r, c_i, image->view->maxiter);
		pixel_to_image(image, i % image->width, i / image->width, \
			grab_color(iterations));
	}
	print_image(env);
}
