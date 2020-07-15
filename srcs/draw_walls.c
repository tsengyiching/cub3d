/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:20:36 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/15 13:43:42 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
