/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:10:36 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/02 15:10:43 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	grab_color(double iterations)
{
	int	red;
	int	green;
	int	blue;

	red = sin(0.016 * iterations + 4) * 230 + 25;
	green = sin(0.013 * iterations + 2) * 230 + 25;
	blue = sin(0.01 * iterations + 1) * 230 + 25;
	return (red + green + blue);
}
