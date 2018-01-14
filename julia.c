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

//there's a real and an imaginary part of the constant.
int		handle_mousemove(int x, int y, t_session *env)
{
	if (ft_strcmp(env->set->name, "julia") == 0)
	{
		env->set->constant_real = (x / (double)(env->image->width / 2));
		env->set->constant_i = (y / (double)(env->image->height / 2));
		printf("the real number: %f\n", env->set->constant_real);
		printf("the imaginary number: %f\n", env->set->constant_i);
		lance_julia(env);
	}
	return (0);
}

/*
** z_new = z_oldˆ2 + c
** initial z_old is the sum of the coordinates.
*/
static int		iterate_julia(t_image *image, int *i)
{
	int		iterations;
	double	z_new_r;
	double	z_new_i;
	double	z_old_r;
	double	z_old_i;
	double	c_r;
	double	c_i;

	// printf("the real constant: %f, and the imaginary constant: %f\n",
	// 	env->set->constant_real, env->set->constant_i);
	//i accounts for each pixel address
	c_r = -0.7;
	c_i = 0.27015;
	iterations = 0;
	z_old_r = ((double)(*i % image->width) - image->width / 2) / \
		(image->width / 2);
	z_old_i = ((double)(*i / image->height) - image->height / 2) / \
		(image->height / 2);
	while (iterations++ < MAX_ITER)
	{
		z_new_r = (z_old_r * z_old_r) - (z_old_i * z_old_i) + c_r;
			// env->set->constant_real;
		z_new_i = (2 * z_old_r * z_old_i) + c_i;
		z_old_r = z_new_r;
		z_old_i = z_new_i;
		// printf("final zs are: r:%f, i:%f\n", z_new_r, z_new_i);
		if ((z_new_r * z_new_r) + (z_new_i * z_new_i) > 4)
			return (iterations);
	}
	return (iterations);
}

/*
** c_r and c_i represent the position of the mouse cursor on the screen
** z_r and z_i initially represents the coordinates of the pixels
*/
void	lance_julia(t_session *env)
{
	int 	i;
	int		iterations;

	//i accounts for each pixel address
	i = 0;
	while (i <= (env->image->width * env->image->height))
	{
		iterations = iterate_julia(env->image, &i);
		if (iterations < MAX_ITER)
			pixel_to_image(env->image, i % env->image->width, i / env->image->width, \
				0x00FFFFFF);
		else
			pixel_to_image(env->image, i % env->image->width, i / env->image->width, \
				0x000000FF);
		i++;
	}
}
