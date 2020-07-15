/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:51:32 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/15 16:50:23 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calcul_ray_pos_and_dir(int x, t_mlx *mlx)
{
	mlx->camerax = 2 * x / mlx->width - 1;
	mlx->ray_dirx = mlx->vector_dirx + mlx->planex * mlx->camerax;
	mlx->ray_diry = mlx->vector_diry + mlx->planey * mlx->camerax;
}

void	calcul_ray_length(t_mlx *mlx)
{
	mlx->delta_distx = fabs(1 / mlx->ray_dirx);
	mlx->delta_disty = fabs(1 / mlx->ray_diry);
}

void	calcul_step_and_init_sidedist(t_mlx *mlx)
{
	if (mlx->ray_dirx < 0)
	{
		mlx->stepx = -1;
		mlx->side_distx = (mlx->start_posx - mlx->mapx) * mlx->delta_distx;
	}
	else
	{
		mlx->stepx = 1;
		mlx->side_distx = (mlx->mapx + 1.0 - mlx->start_posx)
							* mlx->delta_distx;
	}
	if (mlx->ray_diry < 0)
	{
		mlx->stepy = -1;
		mlx->side_disty = (mlx->start_posy - mlx->mapy) * mlx->delta_disty;
	}
	else
	{
		mlx->stepy = 1;
		mlx->side_disty = (mlx->mapy + 1.0 - mlx->start_posy)
							* mlx->delta_disty;
	}
}

void	run_raycasting(t_mlx *mlx)
{
	int		x;

	x = 0;
	while (x < (int)mlx->width)
	{
		mlx->hit = 0;
		mlx->mapx = (int)mlx->start_posx;
		mlx->mapy = (int)mlx->start_posy;
		calcul_ray_pos_and_dir(x, mlx);
		calcul_ray_length(mlx);
		calcul_step_and_init_sidedist(mlx);
		find_walls(&mlx->hit, mlx);
		calcul_perp_wall_dist(mlx);
		calcul_pixel_to_fill_in_stripe(mlx);
		mlx->color = (mlx->side == 1 ? 255 : 65280);
		draw_walls(x, mlx);
		x++;
	}
}
