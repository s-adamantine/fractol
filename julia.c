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

static double	scale_x(double x)
{
	return ((x - W_WIDTH / 2) / (W_WIDTH / 2));
}

static double	scale_y(double y)
{
	return ((y - W_HEIGHT / 2) / (W_HEIGHT / 2));
}

static double	distance_from(double x, double y)
{
	return(sqrt((x * x) + (y * y)));
}

//there's a real and an imaginary part of the constant.
int		handle_mousemove(int x, int y, t_session *env)
{
	if (ft_strcmp(env->set->name, "julia") == 0)
	{
		env->set->constant_real = (x / (double)(W_WIDTH / 2));
		env->set->constant_i = (y / (double)(W_HEIGHT / 2));
		printf("the real number: %f\n", env->set->constant_real);
		printf("the imaginary number: %f\n", env->set->constant_i);
	}
	return (0);
}

/*
** z_new = z_oldˆ2 + c
** initial z_old is the sum of the coordinates.
*/
static void		calculate_julia_equation(t_session *env)
{
	int 	i;
	int		iterations;
	int		color;
	double	z_new_r;
	double	z_new_i;
	double	z_old_r;
	double	z_old_i;

	//i accounts for each pixel address
	i = 0;
	while (i <= (W_WIDTH * W_HEIGHT))
	{
		iterations = 0;
		z_old_r = scale_x(i % W_WIDTH);
		z_old_i = scale_y(i / W_WIDTH);
		while (iterations++ < MAX_ITER)
		{
			z_new_r = (z_old_r * z_old_r) - (z_old_i * z_old_i) + \
				env->set->constant_real;
			z_new_i = 2 * z_old_r * z_old_i + env->set->constant_i;
			z_old_r = z_new_r;
			z_old_i = z_new_i;
		}
	//	printf("%f\n", distance_from(z_new_r, z_new_i));
		if (distance_from(z_new_r, z_new_i) > 2)
			color = 0x00FFFFFF;
		else
			color = 0x000000FF;
		ft_memcpy(&(env->image->pixel_addr)[i * env->image->bpp / 8], &color, \
			env->image->bpp / 8);
		i++;
	}
}

void	lance_julia(t_session *env)
{
//	printf("distance from (0.25, 1.5): %f\n", distance_from(0.25, 1.5));
//	printf("width: %d, scale_x: %f\n", W_WIDTH, scale_x(1));
//	printf("width: %d, scale_y: %f\n", W_WIDTH, scale_y(1));
	calculate_julia_equation(env);
}
