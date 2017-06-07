/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:21:50 by pfrey             #+#    #+#             */
/*   Updated: 2017/06/07 17:21:23 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

int		mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	if (x > 0 && y > 0)
	{
		mlx->x_real = (x / mlx->zoom) + mlx->x1;
		mlx->y_real = (y / mlx->zoom) + mlx->y1;
		if (button == BUTTON_ZOOMIN)
		{
			mlx->zoom *= 1.1;
			mlx->x1 = mlx->x_real - (x / mlx->zoom);
			mlx->y1 = mlx->y_real - (y / mlx->zoom);
		}
		if (button == BUTTON_ZOOMOUT)
		{
			mlx->zoom /= 1.1;
			mlx->x1 = mlx->x_real - (x / mlx->zoom);
			mlx->y1 = mlx->y_real - (y / mlx->zoom);
		}
		if (button == BUTTON_LEFTCLICK)
			mlx->motion = (mlx->motion == 0) ? 1 : 0;
	}
	init_start_mlx(mlx);
	return (0);
}

int		motion(int x, int y, t_mlx *mlx)
{
	if (mlx->nb == 1 || mlx->nb == 5 || mlx->nb == 7)
	{
		if (mlx->motion % 2 && mlx->zoom <= 200)
		{
			if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
			{
				if (x < WIDTH / 2 && y < HEIGHT / 2)
					mlx->c_r += 0.05;
				if (x > WIDTH / 2 && y < HEIGHT / 2)
					mlx->c_r -= 0.05;
				if (x < WIDTH / 2 && y > HEIGHT / 2)
					mlx->c_i += 0.05;
				if (x > WIDTH / 2 && y > HEIGHT / 2)
					mlx->c_i -= 0.05;
			}
		}
		init_start_mlx(mlx);
	}
	return (0);
}
