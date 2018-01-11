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

/*
** c is x + yi.
** c varies from -2 to 2.
** a = a2 - b2 + a
** b = 2ab + b
*/

int		iterate_mandelbrot(double c_r, double c_i)
{
	int 	iterations;
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
			return (iterations);
	}
	return (iterations);
}

void	lance_mandelbrot(t_session *env)
{
	int		i;
	int		iterations;
	double	c_r;
	double	c_i;

	i = 0;
	//in the beginning, both zs are 0.
	//and c is a function of the pixel's location
	//need to change up the x and the y
	while (i <= (W_WIDTH * W_HEIGHT))
	{
		//c_r and c_i aren't quite right yet
		c_r = ((i % W_WIDTH) - (double) W_WIDTH / 2) / (double)(W_WIDTH / 4);
		c_i = ((i / W_WIDTH) - (double) W_HEIGHT / 2) / (double)(W_HEIGHT / 4);
//		printf("c_r is: %f, and c_i is: %f\n", c_r, c_i);
		iterations = iterate_mandelbrot(c_r, c_i);
		if (iterations < MAX_ITER)
			pixel_to_image(env, i % W_WIDTH, i / W_WIDTH, 0x000000FF);
		else
			pixel_to_image(env, i % W_WIDTH, i / W_WIDTH, 0xFFFFFFFF);
		i++;
	}
}
