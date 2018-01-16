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
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_LEFT)
		env->image->deplace_x -= env->image->width / 20;
	if (keycode == KEY_RIGHT)
		env->image->deplace_x += env->image->width / 20;
	if (keycode == KEY_UP)
		env->image->deplace_y -= env->image->height / 20;
	if (keycode == KEY_DOWN)
		env->image->deplace_y += env->image->height / 20;
	draw_set(env);
	return (1);
}
