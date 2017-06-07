/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_start_mlx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:22:22 by pfrey             #+#    #+#             */
/*   Updated: 2017/06/07 17:21:44 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void		init_start_mlx(t_mlx *mlx)
{
	if (mlx->nb == 1)
		ft_print_julia(mlx);
	if (mlx->nb == 2)
		ft_print_mandelbrot(mlx);
	if (mlx->nb == 3)
		ft_print_bship(mlx);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->ptr_img, 0, 0);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_hook(mlx->win, 6, BUTTONMOUSE, motion, mlx);
	mlx_hook(mlx->win, 2, KEYPRESSMASK, ft_key_press, mlx);
	mlx_hook(mlx->win, 17, REDCROSS, ft_esc, mlx);
	mlx_loop(mlx->mlx);
}
