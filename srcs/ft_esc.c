/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_esc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:22:34 by pfrey             #+#    #+#             */
/*   Updated: 2017/06/07 16:46:28 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void			ft_close_fractol(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->ptr_img);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx);
	exit(0);
}

int				ft_esc(t_mlx *mlx)
{
	ft_close_fractol(mlx);
	return (0);
}
