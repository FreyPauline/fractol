/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:22:55 by pfrey             #+#    #+#             */
/*   Updated: 2017/06/07 16:46:22 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

static double		modify_moove(t_mlx *mlx)
{
	double	i;

	i = 0.2;
	if (mlx->zoom <= 100)
		i = 0.2;
	if (mlx->zoom > 100 && mlx->zoom <= 1000)
		i = 0.02;
	if (mlx->zoom > 1000 && mlx->zoom <= 10000)
		i = 0.002;
	if (mlx->zoom > 10000 && mlx->zoom <= 100000)
		i = 0.0002;
	if (mlx->zoom > 100000)
		i = 0.00002;
	return (i);
}

static void			moove(int keycode, t_mlx *mlx)
{
	double	i;

	i = modify_moove(mlx);
	if (keycode == KEY_RIGHT)
		mlx->x1 += i;
	if (keycode == KEY_LEFT)
		mlx->x1 -= i;
	if (keycode == KEY_UP)
		mlx->y1 += i;
	if (keycode == KEY_DOWN)
		mlx->y1 -= i;
}

int					ft_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		ft_close_fractol(mlx);
	if (keycode == KEY_RIGHT || keycode == KEY_LEFT ||
			keycode == KEY_UP || keycode == KEY_DOWN)
		moove(keycode, mlx);
	init_start_mlx(mlx);
	return (0);
}
