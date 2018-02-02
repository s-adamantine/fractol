/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 02:24:33 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/02 11:39:39 by sadamant         ###   ########.fr       */
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
		argv[1]) == 0 || ft_strcmp("burningship", argv[1]) == 0 || \
			ft_strcmp("tricorn", argv[1]) == 0) ? 1 : 0;
}

t_session		*setup_environment(int argc, char **argv)
{
	t_session	*env;

	if (argc != 2)
	{
		ft_putendl_fd("usage: ./fractol [name of set]", 2);
		exit_error("available sets: julia, mandelbrot, burningship, tricorn");
	}
	if (!valid_parameters(argv))
		exit_error("invalid parameter");
	env = ft_memalloc(sizeof(t_session));
	env->mlx = mlx_init();
	env->image = new_image(env);
	env->win = mlx_new_window(env->mlx, env->image->width, env->image->height, \
		"fractol");
	env->set = ft_memalloc(sizeof(t_set));
	env->set->name = argv[1];
	env->set->maxiter= MAX_ITER;
	mlx_key_hook(env->win, handle_keypress, env);
	mlx_mouse_hook(env->win, handle_mousepress, env);
	mlx_hook(env->win, MOTION_NOTIFY, POINTER_MOTION_MASK, handle_mousemove, \
		env);
	return (env);
}

int				main(int argc, char **argv)
{
	t_session	*env;

	env = setup_environment(argc, argv);
	draw_set(env);
	mlx_loop(env->mlx);
	return (0);
}
