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

# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define CLICK 1

# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define W_WIDTH 750
# define W_HEIGHT 750
# define MAX_ITER 256

# define MOTION_NOTIFY 6
# define POINTER_MOTION_MASK (1L<<6)

typedef struct	s_image
{
	int			bpp;
	int			sline;
	int			width;
	int			height;
	double		interval_x;
	double		interval_y;
	double		deplace_x;
	double		deplace_y;
	double		xoffset;
	double		yoffset;
	double		c_r_min;
	double		c_i_min;
	double		c_r_max;
	double		c_i_max;
	double		zoom;
	void		*init;
	char		*pixel_addr;
}				t_image;

typedef struct	s_set
{
	char		*name;
	double		constant_r;
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

t_image			*new_image(t_session *env);
void			pixel_to_image(t_image *image, int x, int y, int color);
int				handle_keypress(int keycode, t_session *env);
int				handle_mousemove(int x, int y, t_session *env);
int				handle_mousepress(int button, int x, int y, t_session *env);
int				handle_julia_const(int x, int y, void * param);
void			print_square(t_image *image);
void			print_image(t_session *env);
void			draw_julia(t_image *image, t_session *env);
void			draw_mandelbrot(t_image *image, t_session *env);
void			draw_burningship(t_image *image, t_session *env);
void			draw_tricorn(t_image *image, t_session *env);
void			draw_set(t_session *env);
void			zoom(t_session *env, t_set *set, int button, int x, int y);
double			grab_color(double iterations);
