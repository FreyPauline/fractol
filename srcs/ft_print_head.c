/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_head.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:22:39 by pfrey             #+#    #+#             */
/*   Updated: 2017/06/07 17:33:51 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

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
