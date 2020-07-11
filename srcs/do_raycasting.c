/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:51:32 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/11 17:55:19 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	draw_walls(int hor, t_config *cfg, t_mlx *mlx)
{
	int ver;

	ver = 0;
	while (ver < cfg->height)
	{
		if (ver > mlx->draw_start && ver < mlx->draw_end)
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, hor, ver, mlx->color);
		ver++;
	}
}

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

void	find_walls(int *hit, t_mlx *mlx, t_config *cfg)
{
	while (*hit == 0)
	{
		if (mlx->side_distx < mlx->side_disty)
		{
			mlx->side_distx += mlx->delta_distx;
			mlx->mapx += mlx->stepx;
			mlx->side = 0;
		}
		else
		{
			mlx->side_disty += mlx->delta_disty;
			mlx->mapy += mlx->stepy;
			mlx->side = 1;
		}
		if (cfg->map[mlx->mapx][mlx->mapy] == '1')
			*hit = 1;
	}
}

void	calcul_perp_wall_dist(t_mlx *mlx)
{
	if (mlx->side == 0)
	{
		mlx->perp_wall_dist = (mlx->mapx - mlx->start_posx +
								(1 - mlx->stepx) / 2) / mlx->ray_dirx;
	}
	else
	{
		mlx->perp_wall_dist = (mlx->mapy - mlx->start_posy +
								(1 - mlx->stepy) / 2) / mlx->ray_diry;
	}
}

void	calcul_pixel_to_fill_in_stripe(t_mlx *mlx)
{
	mlx->line_height = (int)(mlx->height / mlx->perp_wall_dist);
	mlx->draw_start = -(mlx->line_height) / 2 + mlx->height / 2;
	if (mlx->draw_start < 0)
		mlx->draw_start = 0;
	mlx->draw_end = mlx->line_height / 2 + mlx->height / 2;
	if (mlx->draw_end >= mlx->height)
		mlx->draw_end = mlx->height - 1;
}

void	do_raycasting(t_mlx *mlx, t_config *cfg)
{
	int		x;

	x = 0;
	mlx->width = cfg->width;
	mlx->height = cfg->height;
	while (x < cfg->width)
	{
		mlx->hit = 0;
		mlx->mapx = (int)mlx->start_posx;
		mlx->mapy = (int)mlx->start_posy;
		calcul_ray_pos_and_dir(x, mlx);
		calcul_ray_length(mlx);
		calcul_step_and_init_sidedist(mlx);
		find_walls(&mlx->hit, mlx, cfg);
		calcul_perp_wall_dist(mlx);
		calcul_pixel_to_fill_in_stripe(mlx);
		mlx->color = (mlx->side == 1 ? 255 : 65280);
		draw_walls(x, cfg, mlx);
		x++;
	}
}
