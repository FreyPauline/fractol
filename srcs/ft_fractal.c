/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:22:04 by pfrey             #+#    #+#             */
/*   Updated: 2017/06/07 18:19:27 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void		ft_print_julia(t_mlx *mlx)
{
	while (mlx->x < WIDTH)
	{
		mlx->y = 0;
		while (mlx->y < HEIGHT)
		{
			mlx->z_r = mlx->x / mlx->zoom + mlx->x1;
			mlx->z_i = mlx->y / mlx->zoom + mlx->y1;
			mlx->i = 0;
			while (mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < 4
					&& mlx->i < mlx->iter)
			{
				mlx->tmp = mlx->z_r;
				mlx->z_r = (mlx->z_r * mlx->z_r - mlx->z_i *
					mlx->z_i + mlx->c_r);
				mlx->z_i = (2 * mlx->z_i * mlx->tmp + mlx->c_i);
				mlx->i++;
			}
			put_pixel_to_img(mlx);
			mlx->y++;
		}
		mlx->x++;
	}
	mlx->x = 0;
}

void			ft_print_mandelbrot(t_mlx *mlx)
{
	while (mlx->x < WIDTH)
	{
		mlx->y = 0;
		while (mlx->y < HEIGHT)
		{
			mlx->c_r = mlx->x / mlx->zoom + mlx->x1;
			mlx->c_i = mlx->y / mlx->zoom + mlx->y1;
			mlx->z_r = 0;
			mlx->z_i = 0;
			mlx->i = 0;
			while ((mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < 4) &&
					(mlx->i < mlx->iter))
			{
				mlx->tmp = mlx->z_r;
				mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i + mlx->c_r;
				mlx->z_i = 2 * mlx->z_i * mlx->tmp + mlx->c_i;
				mlx->i++;
			}
			put_pixel_to_img(mlx);
			mlx->y++;
		}
		mlx->x++;
	}
	mlx->x = 0;
}

void			ft_print_bship(t_mlx *mlx)
{
	while (mlx->x < WIDTH)
	{
		mlx->y = 0;
		while (mlx->y < HEIGHT)
		{
			mlx->c_r = mlx->x / mlx->zoom + mlx->x1;
			mlx->c_i = mlx->y / mlx->zoom + mlx->y1;
			mlx->z_r = 0;
			mlx->z_i = 0;
			mlx->i = 0;
			while (mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < 4 &&
					mlx->i < mlx->iter)
			{
				mlx->tmp = mlx->z_r;
				mlx->z_r = fabs(mlx->z_r * mlx->z_r - mlx->z_i *
						mlx->z_i + mlx->c_r);
				mlx->z_i = fabs(2 * mlx->z_i * mlx->tmp + mlx->c_i);
				mlx->i++;
			}
			put_pixel_to_img(mlx);
			mlx->y++;
		}
		mlx->x++;
	}
	mlx->x = 0;
}

void	init_var_julia(t_mlx *mlx)
{
	mlx->x = 0;
	mlx->y = 0;
	mlx->x1 = -1.95;
	mlx->y1 = -1.95;
	mlx->c_r = 0.285;
	mlx->c_i = 0.01;
	mlx->iter = 200;
	mlx->motion = 0;
	mlx->color = 0xD213B5;
	mlx->zoom = 200;
}

void	init_var_mandelbrot(t_mlx *mlx)
{
	mlx->x = 0;
	mlx->y = 0;
	mlx->x1 = -2.02;
	mlx->x2 = 0.6;
	mlx->y1 = -2.02;
	mlx->y2 = 1.2;
	mlx->iter = 100;
	mlx->motion = 0;
	mlx->color = 0xE8F613;
	mlx->zoom = 200;
}

void	init_var_bship(t_mlx *mlx)
{
	mlx->x = 0;
	mlx->y = 0;
	mlx->x1 = -2.02;
	mlx->x2 = 0.6;
	mlx->y1 = -2.02;
	mlx->y2 = 1.2;
	mlx->iter = 100;
	mlx->motion = 0;
	mlx->color = 0xE6192F;
	mlx->zoom = 200;
}
