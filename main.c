/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 02:24:33 by sadamant          #+#    #+#             */
/*   Updated: 2017/12/23 02:24:35 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			exit_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

int				valid_parameters(char **argv)
{
	return (ft_strcmp("julia", argv[1]) == 0 || ft_strcmp("mandelbrot", \
		argv[1]) == 0) ? 1 : 0;
}

/*
** set default w_width and w_height to 500 if not specified.
*/
t_session		*setup_environment(int argc, char **argv)
{
	t_session	*env;

	if (argc < 2)
		exit_error("available parameters: julia, mandelbrot");
	if (!valid_parameters(argv))
		exit_error("invalid parameter");
	env = ft_memalloc(sizeof(t_session));
	env->mlx = mlx_init();
	env->image = new_image(env, argv);
	env->win = mlx_new_window(env->mlx, env->image->width, env->image->height, \
		"fractol");
	mlx_key_hook(env->win, handle_keypress, env);
	return (env);
}

int				main(int argc, char **argv)
{
	t_session	*env;

	env = setup_environment(argc, argv);
	print_square(env->image);
	mlx_put_image_to_window(env->mlx, env->win, env->image->init, 0, 0);
	mlx_loop(env->mlx);
	return (0);
}
