/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:20:00 by sadamant          #+#    #+#             */
/*   Updated: 2018/01/24 18:20:02 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_view	*grab_initialview(char *name)
{
	t_view	*view;

	view = ft_memalloc(sizeof(t_view));
	if (ft_strcmp(name, "mandelbrot") == 0)
	{
		view->xoffset = -0.75;
		view->yoffset = -0.5;
		view->initialzoom = 3;
	}
	if (ft_strcmp(name, "burningship") == 0)
	{
		view->xoffset = -0.725;
		view->yoffset = -0.5;
		view->initialzoom = 3;
	}
	if (ft_strcmp(name, "tricorn") == 0)
	{
		view->xoffset = -0.6;
		view->yoffset = -0.5;
		view->initialzoom = 4;
	}
	return (view);
}
