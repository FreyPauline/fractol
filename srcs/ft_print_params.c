/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:22:39 by pfrey             #+#    #+#             */
/*   Updated: 2017/06/07 17:24:37 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void	fps(t_mlx *mlx)
{
	static double	last_time;
	static int		img;
	static int		save;
	double			current_time;
	char			*fps;

	current_time = time(NULL);
	if (mlx->init == 0)
	{
		last_time = current_time;
		save = 0;
		img = 0;
		mlx->init = 1;
	}
	img++;
	if (last_time != current_time)
	{
		last_time = current_time;
		save = img;
		img = 0;
	}
	fps = ft_itoa(save);
	mlx_string_put(mlx->mlx, mlx->win, 945, 270, 0x0000FF, fps);
	ft_strdel(&fps);
}

void	ft_print_head(void)
{
	ft_putstr("||===============================||\n");
	ft_putstr("||                               ||\n");
	ft_putstr("||     Maps      |   Parameter   ||\n");
	ft_putstr("|| ----------------------------- ||\n");
	ft_putstr("||     Julia     |      -J       ||\n");
	ft_putstr("||   Mendelbrot  |      -M       ||\n");
	ft_putstr("||     Bship     |      -B       ||\n");
	ft_putstr("||                               ||\n");
	ft_putstr("|| Ex: './fractol -J' for Julia  ||\n");
	ft_putstr("||===============================||\n");
	exit(0);
}
