/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:20:06 by pfrey             #+#    #+#             */
/*   Updated: 2017/06/07 17:09:16 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include "../libft/libft.h"
# include "../lib-mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <math.h>
# define KEYPRESSMASK (3)
# define BUTTONMOUSE (1<<8)
# define REDCROSS (1L<<17)
# define HEIGHT	800
# define WIDTH 800

typedef struct		s_mlx
{
	char			*gda;
	void			*ptr_img;
	void			*win;
	void			*mlx;
	int				size_line;
	int				endian;
	int				bpp;
	int				put_img;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp;
	double			x_real;
	double			y_real;
	long double		zoom;
	int				iter;
	int				x;
	int				y;
	int				i;
	int				nb;
	int				init;
	int				motion;
	int				color;
}					t_mlx;

/*
** Fract
*/
void				ft_print_julia(t_mlx *mlx);
void				ft_print_mandelbrot(t_mlx *mlx);
void				ft_print_bship(t_mlx *mlx);
/*
**	Mlx
*/
void				ft_init_win(int nb);
void				init_fract(t_mlx *mlx);
void				init_start_mlx(t_mlx *mlx);
void				init_var_julia(t_mlx *mlx);
void				init_var_mandelbrot(t_mlx *mlx);
void				init_img(t_mlx *mlx);
void				put_pixel_to_img(t_mlx *mlx);

/*
** Event
*/
int					ft_key_press(int keycode, t_mlx *mlx);
int					ft_key_release(int keycode, t_mlx *mlx);
int					ft_esc(t_mlx *mlx);
int					mouse_hook(int button, int x, int y, t_mlx *mlx);
int					motion(int x, int y, t_mlx *mlx);

/*
** Other
*/
void				ft_close_fractol(t_mlx *mlx);
void				ft_print_head(void);

typedef enum	e_mlx_key
{
	KEY_A = 0,
	KEY_B = 11,
	KEY_C = 8,
	KEY_D = 2,
	KEY_E = 14,
	KEY_F = 3,
	KEY_G = 5,
	KEY_H = 4,
	KEY_I = 34,
	KEY_J = 38,
	KEY_K = 40,
	KEY_L = 37,
	KEY_M = 46,
	KEY_N = 45,
	KEY_O = 31,
	KEY_P = 35,
	KEY_Q = 12,
	KEY_R = 15,
	KEY_S = 1,
	KEY_T = 17,
	KEY_U = 32,
	KEY_V = 9,
	KEY_W = 13,
	KEY_X = 7,
	KEY_Y = 16,
	KEY_Z = 6,
	KEY_0 = 29,
	KEY_1 = 18,
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_4 = 21,
	KEY_5 = 23,
	KEY_6 = 22,
	KEY_7 = 26,
	KEY_8 = 28,
	KEY_9 = 25,
	KEY_NUM_0 = 82,
	KEY_NUM_1 = 83,
	KEY_NUM_2 = 84,
	KEY_NUM_3 = 85,
	KEY_NUM_4 = 86,
	KEY_NUM_5 = 87,
	KEY_NUM_6 = 88,
	KEY_NUM_7 = 89,
	KEY_NUM_8 = 91,
	KEY_NUM_9 = 92,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_ESC = 53,
	KEY_PLUS = 69,
	KEY_MOINS = 78,
}				t_mlx_key;

typedef enum	e_mlx_button
{
	BUTTON_LEFTCLICK = 1,
	BUTTON_ZOOMIN = 4,
	BUTTON_ZOOMOUT = 5
}				t_mlx_button;

#endif
