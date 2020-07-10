/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:51:32 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/10 19:24:55 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	draw_walls(int x, t_config *cfg, t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < cfg->height)
	{
		if (i > mlx->draw_start && i < mlx->draw_end)
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, i, mlx->color);
		i++;
	}
}

void	do_raycasting(t_mlx *mlx, t_config *cfg)
{
	int		x;

	x = 0;
	mlx->w = cfg->width;
	mlx->h = cfg->height;
	while (x < cfg->width)
	{
		mlx->camerax = 2 * x / mlx->w - 1;
		mlx->ray_dirx = mlx->vector_dirx + mlx->planex * mlx->camerax;
		mlx->ray_diry = mlx->vector_diry + mlx->planey * mlx->camerax;
		mlx->mapx = (int)mlx->starting_posx;
		mlx->mapy = (int)mlx->starting_posy;
		mlx->delta_distx = fabs(1 / mlx->ray_dirx);
		mlx->delta_disty = fabs(1 / mlx->ray_diry);
		mlx->hit = 0;
		if (mlx->ray_dirx < 0)
		{
			mlx->stepx = -1;
			mlx->side_distx = (mlx->starting_posx - mlx->mapx) * mlx->delta_distx;
		}
		else
		{
			mlx->stepx = 1;
			mlx->side_distx = (mlx->mapx + 1.0 - mlx->starting_posx) * mlx->delta_distx;
		}
		if (mlx->ray_diry < 0)
		{
			mlx->stepy = -1;
			mlx->side_disty = (mlx->starting_posy - mlx->mapy) * mlx->delta_disty;
		}
		else
		{
			mlx->stepy = 1;
			mlx->side_disty = (mlx->mapy + 1.0 - mlx->starting_posy) * mlx->delta_disty;
		}
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
		if (mlx->side == 0)
			mlx->perp_wall_dist = (mlx->mapx - mlx->starting_posx + (1 - mlx->stepx) / 2) / mlx->ray_dirx;
		else
			mlx->perp_wall_dist = (mlx->mapy - mlx->starting_posy + (1 - mlx->stepy) / 2) / mlx->ray_diry;
		mlx->line_height = (int)(mlx->h / mlx->perp_wall_dist);
		mlx->draw_start = -(mlx->line_height) / 2 + mlx->h / 2;
		if (mlx->draw_start < 0)
			mlx->draw_start = 0;
		mlx->draw_end = mlx->line_height / 2 + mlx->h / 2;
		if (mlx->draw_end >= mlx->h)
			mlx->draw_end = mlx->h - 1;
		if (mlx->side == 1)
			mlx->color = 255;
		else
			mlx->color = 65280;
		draw_walls(x, cfg, mlx);
		x++;
	}
}
