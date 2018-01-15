/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 02:24:47 by sadamant          #+#    #+#             */
/*   Updated: 2017/12/23 02:25:33 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "mlx.h"
# include "libft.h"

# define KEY_ESC 53
# define W_WIDTH 250
# define W_HEIGHT 250
# define MAX_ITER 1024

# define MOTION_NOTIFY 6
# define POINTER_MOTION_MASK (1L<<6)

typedef struct	s_image
{
	int			bpp;
	int			sline;
	int			width;
	int			height;
	void		*init;
	char		*pixel_addr;
}				t_image;

typedef struct	s_set
{
	char		*name;
	double		constant_real;
	double		constant_i;
}				t_set;

typedef struct	s_session
{
	void		*mlx;
	void		*win;
	t_image		*image;
	t_set		*set;
	int			endian;
}				t_session;

t_image			*new_image(t_session *env, char **argv);
void			pixel_to_image(t_image *image, int x, int y, int color);
int				handle_keypress(int keycode, t_session *env);
int				handle_mousemove(int x, int y, t_session *env);
int				handle_julia_const(int x, int y, void * param);
void			print_square(t_image *image);
void			lance_julia(t_image *image);
void			lance_mandelbrot(t_image *image);
