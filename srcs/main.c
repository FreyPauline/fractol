/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:21:56 by pfrey             #+#    #+#             */
/*   Updated: 2017/06/07 17:09:03 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void	get_fract(char *str, t_mlx *mlx)
{
	if (ft_strcmp(str, "-J") == 0)
		mlx->nb = 1;
	else if (ft_strcmp(str, "-M") == 0)
		mlx->nb = 2;
	else if (ft_strcmp(str, "-B") == 0)
		mlx->nb = 3;
	else
		ft_print_head();
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		exit(0);
	if (argc != 2)
		ft_print_head();
	else
	{
		get_fract(argv[1], mlx);
		init_fract(mlx);
	}
	return (0);
}
