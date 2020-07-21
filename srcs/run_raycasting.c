/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:51:32 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/21 22:24:41 by yictseng         ###   ########lyon.fr   */
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
		mlx->side_distx = (mlx->mapx + 1.0 - mlx->posx) * mlx->delta_distx;
	}
	if (mlx->raydiry < 0)
	{
		mlx->stepy = -1;
		mlx->side_disty = (mlx->posy - mlx->mapy) * mlx->delta_disty;
	}
	else
	{
		mlx->stepy = 1;
		mlx->side_disty = (mlx->mapy + 1.0 - mlx->posy) * mlx->delta_disty;
	}
}

void	run_raycasting(t_cub *cub)
{
	int		x;

	x = 0;
	while (x < cub->cfg.width)
	{
		cub->mlx.hit = 0;
		cub->mlx.mapx = (int)cub->mlx.posx;
		cub->mlx.mapy = (int)cub->mlx.posy;
		calcul_ray_pos_and_dir(x, &cub->mlx);
		calcul_ray_length(&cub->mlx);
		calcul_step_and_init_sidedist(&cub->mlx);
		find_walls(&cub->cfg, &cub->mlx);
		calcul_perp_wall_dist(&cub->mlx);
		calcul_pixel_to_fill_in_stripe(&cub->mlx);
		calcul_wall_texture(&cub->mlx);
		draw_walls(x, &cub->cfg, &cub->mlx);
		cub->mlx.buf[x] = cub->mlx.perp_wall_dist;
		x++;
	}
	if (cub->cfg.sprite_nb > 0)
	{
		x = 0;
		find_sprite(&cub->cfg, &cub->mlx);
		while (x < cub->cfg.sprite_nb)
		{
			calcul_sprite_dist(&cub->mlx, x);
		}
	}
}
