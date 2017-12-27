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
	clear_image(env->image);
	mlx_put_image_to_window(env->mlx, env->win, env->image->init, 0, 0);
}

void	pixel_to_image(t_session *env, int x, int y, int color)
{
	if (x < 0 || x >= env->image->width || y < 0 || y >= env->image->height)
		return ;
	ft_memcpy(&(env->image->pixel_addr)[(x++ * env->image->bpp / 8) + \
		(y * env->image->sline)], &color, env->image->bpp / 8);
}

t_image	*new_image(t_session *env, char **argv)
{
	t_image	*image;

	image = ft_memalloc(sizeof(t_image));
	if (argv[2] && argv[3])
	{
		image->width = ft_atoi(argv[2]);
		image->height = ft_atoi(argv[3]);
	}
	else
	{
		image->width = W_WIDTH;
		image->height = W_HEIGHT;
	}
	image->init = mlx_new_image(env->mlx, image->width, image->height);
	image->pixel_addr = mlx_get_data_addr(image->init, &(image->bpp), \
		&(image->sline), &(env->endian));
	return (image);
}
