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

void	print_square(t_image *image)
{
	int	i;
	int color;

	i = 0;
	color = 0x00FF00FF;
	while (i < (image->width * image->height))
	{
		ft_memcpy(&(image->pixel_addr)[i++ * image->bpp / 8], &color,\
		 image->bpp / 8);
	}
}
