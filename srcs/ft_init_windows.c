/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_windows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:22:10 by pfrey             #+#    #+#             */
/*   Updated: 2017/06/07 17:21:57 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void	init_img(t_mlx *mlx)
{
	if (mlx->nb == 1)
		init_var_julia(mlx);
	if (mlx->nb == 2 || mlx->nb == 3)
		init_var_mandelbrot(mlx);
	mlx->ptr_img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->gda = mlx_get_data_addr(mlx->ptr_img, &mlx->bpp, &mlx->size_line,
				&mlx->endian);
	init_start_mlx(mlx);
}

void	init_fract(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Fractol");
	init_img(mlx);
}
