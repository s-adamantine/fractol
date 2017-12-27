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

# include "mlx.h"
# include "libft.h"

# define KEY_ESC 53
# define W_WIDTH 500
# define W_HEIGHT 500
# define NUM_PIXELS W_WIDTH * W_HEIGHT

typedef struct	s_image
{
	int			bpp;
	int			sline;
	void		*init;
	char		*pixel_addr;
}				t_image;

typedef struct	s_session
{
	void		*mlx;
	void		*win;
	t_image		*image;
	int			endian;
}				t_session;

t_image			*new_image(t_session *env);
int				handle_keypress(int keycode, t_session *env);
void			print_square(t_session *env);
