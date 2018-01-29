/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 02:29:46 by sadamant          #+#    #+#             */
/*   Updated: 2017/12/23 02:30:51 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		handle_keypress(int keycode, t_session *env)
{
	t_image	*image;

	image = env->image;
	if (keycode == ESC)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == LEFT)
		image->deplace_x -= image->width / 20;
	if (keycode == RIGHT)
		image->deplace_x += image->width / 20;
	if (keycode == UP)
		image->deplace_y -= image->height / 20;
	if (keycode == DOWN)
		image->deplace_y += image->height / 20;
	if (keycode == LBRACKET)
		image->view->maxiter *= 0.50;
	if (keycode == RBRACKET)
		image->view->maxiter *= 1.50;
	draw_set(env);
	return (1);
}
