/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:20:36 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/17 13:45:18 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	find_walls(t_cfg *cfg, t_mlx *mlx)
{
	while (mlx->hit == 0)
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
			mlx->hit = 1;
	}
}

void	calcul_perp_wall_dist(t_mlx *mlx)
{
	if (mlx->side == 0)
	{
		mlx->perp_wall_dist = (mlx->mapx - mlx->posx +
								(1 - mlx->stepx) / 2) / mlx->raydirx;
	}
	else
	{
		mlx->perp_wall_dist = (mlx->mapy - mlx->posy +
								(1 - mlx->stepy) / 2) / mlx->raydiry;
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

void	draw_walls(int hor, t_cfg *cfg, t_mlx *mlx)
{
	int ver;

	ver = 0;
	while (ver < mlx->height)
	{
		if (ver < mlx->draw_start)
			mlx->pixel[hor + ver * cfg->width] = cfg->ceiling;
		if (ver >= mlx->draw_start && ver <= mlx->draw_end)
			mlx->pixel[hor + ver * cfg->width] = mlx->color;
		if (ver > mlx->draw_end)
			mlx->pixel[hor + ver * cfg->width] = cfg->floor;
		ver++;
	}
}
