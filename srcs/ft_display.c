/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:22:28 by pfrey             #+#    #+#             */
/*   Updated: 2017/06/07 17:20:40 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void		put_pixel_img(unsigned long color, t_mlx *m, int l, int h)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	if (l < 0 || h < 0 || l >= WIDTH || h >= HEIGHT)
		return ;
	r = ((color & 0xFF0000) >> 16);
	g = ((color & 0x00FF00) >> 8);
	b = (color & 0x0000FF);
	if (h * m->size_line + l * m->bpp < 0)
		return ;
	m->gda[h * m->size_line + l * m->bpp / 8] = b;
	m->gda[h * m->size_line + l * m->bpp / 8 + 1] = g;
	m->gda[h * m->size_line + l * m->bpp / 8 + 2] = r;
}

void		pixel_to_image(t_mlx *mlx, int x, int y, int color)
{
	int		octet;

	octet = mlx->bpp / 8;
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
		ft_memcpy(&mlx->gda[octet * (x + mlx->size_line / \
					octet * y)], &color, octet);
}

void		put_pixel_to_img(t_mlx *mlx)
{
	if (mlx->i == mlx->iter)
		pixel_to_image(mlx, mlx->x, mlx->y, 0);
	else
		pixel_to_image(mlx, mlx->x, mlx->y, mlx->color * mlx->i / mlx->iter);
}
