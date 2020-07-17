/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:51:32 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/17 12:41:27 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calcul_ray_pos_and_dir(int x, t_mlx *mlx)
{
	mlx->camerax = 2 * x / mlx->width - 1;
	mlx->raydirx = mlx->vecdirx + mlx->planex * mlx->camerax;
	mlx->raydiry = mlx->vecdiry + mlx->planey * mlx->camerax;
}

void	calcul_ray_length(t_mlx *mlx)
{
	mlx->delta_distx = fabs(1 / mlx->raydirx);
	mlx->delta_disty = fabs(1 / mlx->raydiry);
}

void	calcul_step_and_init_sidedist(t_mlx *mlx)
{
	if (mlx->raydirx < 0)
	{
		mlx->stepx = -1;
		mlx->side_distx = (mlx->posx - mlx->mapx) * mlx->delta_distx;
	}
	else
	{
		mlx->stepx = 1;
		mlx->side_distx = (mlx->mapx + 1.0 - mlx->posx)
							* mlx->delta_distx;
	}
	if (mlx->raydiry < 0)
	{
		mlx->stepy = -1;
		mlx->side_disty = (mlx->posy - mlx->mapy) * mlx->delta_disty;
	}
	else
	{
		mlx->stepy = 1;
		mlx->side_disty = (mlx->mapy + 1.0 - mlx->posy)
							* mlx->delta_disty;
	}
}

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

void	run_raycasting(t_cub *cub)
{
	int		x;

	x = 0;
	while (x < cub->cfg.width)
	{
		calcul_ray_pos_and_dir(x, &cub->mlx);
		cub->mlx.mapx = (int)cub->mlx.posx;
		cub->mlx.mapy = (int)cub->mlx.posy;
		calcul_ray_length(&cub->mlx);
		cub->mlx.hit = 0;
		calcul_step_and_init_sidedist(&cub->mlx);
		find_walls(&cub->cfg, &cub->mlx);
		calcul_perp_wall_dist(&cub->mlx);
		calcul_pixel_to_fill_in_stripe(&cub->mlx);
		cub->mlx.color = (cub->mlx.side == 1 ? 255 : 65280);
		draw_walls(x, &cub->cfg, &cub->mlx);
		x++;
	}
}
