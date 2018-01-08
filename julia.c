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

static double	distance_from(double x, double y)
{
	return(sqrt((x * x) + (y * y)));
}

static double	scale_x(double x)
{
	return ((x - W_WIDTH / 2) / (W_WIDTH / 2));
}

static double	scale_y(double y)
{
	return ((y - W_HEIGHT / 2) / (W_HEIGHT / 2));
}

int		handle_mousemove(int x, int y, t_session *env)
{
	if (y)
		ft_putstr("what do I do w/ y");
	if (ft_strcmp(env->set->name, "julia") == 0)
		env->set->constant = (x / (W_WIDTH / 2)); //but only if it's julia though
	return (0);
}

// /*
// ** z_new = z_oldˆ2 + c
// ** initial z_old is the sum of the coordinates.
// */
static void		calculate_julia_equation(t_session *env)
{
	int 	i;
	int		iterations;
	int		color;
	double	z_new;
	double	z_old;

	printf("i'm lancing the julia equation\n");
	i = 0;
	// this is a while loop for each pixel address.
	while (env->image->pixel_addr[i * (env->image->bpp / 8)])
	{
		printf("i'm inside the while loop.\n");
		iterations = 0;
		//need to figure out whether the first row of pixels is a + 1 or not
		z_old = scale_x(i % W_WIDTH) + scale_y(i / W_WIDTH);
		while (iterations++ < MAX_ITER)
		{
			z_new = (z_old * z_old) + env->set->constant;
			z_old = z_new;
			printf("zold is: %f\n", z_old);
		}
		// this really needs to be checked
		ft_memcpy(&(env->image->pixel_addr)[i], &color, env->image->bpp / 8);
	}
}

void	lance_julia(t_session *env)
{
	printf("distance from (0.25, 1.5): %f\n", distance_from(0.25, 1.5));
	printf("width: %d, scale_x: %f\n", W_WIDTH, scale_x(1));
	printf("width: %d, scale_y: %f\n", W_WIDTH, scale_y(1));
	calculate_julia_equation(env);
}
