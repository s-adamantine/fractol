/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 02:24:33 by sadamant          #+#    #+#             */
/*   Updated: 2018/01/04 16:56:17 by sadamant         ###   ########.fr       */
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
** need to tidy up the first if statement.
*/
t_session		*setup_environment(int argc, char **argv)
{
	t_session	*env;

	if (argc < 2)
	{
		ft_putendl_fd \
		("usage: ./fractol [name of set] (window width) (window height)", 2);
		ft_putendl_fd\
		("window width and height are optional, defaults are set to 500px", 2);
		exit_error("available sets: julia, mandelbrot");
	}
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
	if (ft_strcmp(argv[1], "julia") == 0)
		julia_main();
	else
		printf("I don't know how to print you.");
	mlx_put_image_to_window(env->mlx, env->win, env->image->init, 0, 0);
	mlx_loop(env->mlx);
	return (0);
}
