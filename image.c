/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:58:48 by sadamant          #+#    #+#             */
/*   Updated: 2017/12/23 02:40:02 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clear_image(t_image *image)
{
	ft_bzero(image->pixel_addr, image->sline * W_HEIGHT);
}

void	print_image(t_session *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->image->init, 0, 0);
	clear_image(env->image);
}

void	pixel_to_image(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= image->width || y < 0 || y >= image->height)
		return ;
	ft_memcpy(&(image->pixel_addr)[(x++ * image->bpp / 8) + \
		(y * image->sline)], &color, image->bpp / 8);
}

t_image	*new_image(t_session *env)
{
	t_image	*image;

	image = ft_memalloc(sizeof(t_image));
	image->width = W_WIDTH;
	image->height = W_HEIGHT;
	image->init = mlx_new_image(env->mlx, image->width, image->height);
	image->pixel_addr = mlx_get_data_addr(image->init, &(image->bpp), \
		&(image->sline), &(env->endian));
	image->zoom = 1.0;
	image->deplace_x = 0;
	image->deplace_y = 0.0;
	return (image);
}
