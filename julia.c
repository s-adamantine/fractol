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

//
// -1 is 0
// 0 is W_WIDTH / 2
// 1 is W_WIDTH
static double	scale_x(double x)
{
	return ((x - W_WIDTH / 2) / (W_WIDTH / 2));
}

static double	scale_y(double y)
{
	return ((y - W_HEIGHT / 2) / (W_HEIGHT / 2));
}

// void			calculate_julia(t_image *image)
// {
// 	int 	i;
// 	int		iterations;
// 	int		color;
//
// 	i = 0;
//
// 	while (image->pixel_addr[i])
// 	{
// 		iterations = 0;
// 		while (iterations++ < MAX_ITER)
// 		{
// 			// z_new = (z_old * z_old) + get_julia_constant();
// 		}
// 		ft_memcpy(&(image->pixel_addr)[i], &color, image->bpp / 8);
// 		printf("%d\n", image->bpp);
// 		i += image->bpp / 8;
// 	}
// }

void	julia_main(void)
{
	printf("distance from (0.25, 1.5): %f\n", distance_from(0.25, 1.5));
	printf("width: %d, scale_x: %f\n", W_WIDTH, scale_x(1));
}

// void	get_julia_constant()
// {
//
// }
