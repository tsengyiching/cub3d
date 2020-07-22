/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 17:03:00 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/22 22:54:18 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	sort_sprite_dist(t_cfg *cfg, t_mlx *mlx)
{
	int			i;
	int			j;
	t_sprite	tmp;
	
	i = 0;
	while (i < cfg->sprite_nb - 1)
	{
		j = i + 1;
		while (j < cfg->sprite_nb)
		{
			if (mlx->spr[i].dist < mlx->spr[j].dist)
			{
				tmp = mlx->spr[i];
				mlx->spr[i] = mlx->spr[j];
				mlx->spr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	init_sprite_dist(t_cfg *cfg, t_mlx *mlx)
{
	int			i;

	i = 0;
	while (i < cfg->sprite_nb)
	{
		mlx->spr[i].dist = ((mlx->posx - mlx->spr[i].x) *
							(mlx->posx - mlx->spr[i].x) + 
							(mlx->posy - mlx->spr[i].y) *
							(mlx->posy - mlx->spr[i].y));
		i++;
	}
	sort_sprite_dist(cfg, mlx);
}

void	find_sprite(t_cfg *cfg, t_mlx *mlx)
{	
	int x;
	int	y;
	int	i;

	x = 0;
	i = 0;
	while (cfg->map[x])
	{
		y = 0;
		while (cfg->map[x][y])
		{
			if (cfg->map[x][y] == '2')
			{
				mlx->spr[i].x = x + 0.5;
				mlx->spr[i].y = y + 0.5;
				i++;
			}
			y++;
		}
		x++;
	}
}

void	calcul_sprite(t_mlx *mlx, int i)
{
	mlx->spritex = mlx->spr[i].x - mlx->posx;
	mlx->spritey = mlx->spr[i].y - mlx->posy;
	mlx->inv_det = 1.0 / (mlx->planex * mlx->vecdiry - mlx->vecdirx * mlx->planey);
	mlx->transformx = mlx->inv_det * (mlx->vecdiry * mlx->spritex - mlx->vecdirx * mlx->spritey);
	mlx->transformy = mlx->inv_det * (-mlx->planey * mlx->spritex + mlx->planex * mlx->spritey);
	mlx->spr_screenx = (int)((mlx->width / 2) * (1 + mlx->transformx / mlx->transformy));
	mlx->spr_height = abs((int)(mlx->height / mlx->transformy));
	mlx->draw_starty = -mlx->spr_height / 2 + mlx->height / 2;
	if (mlx->draw_starty < 0)
		mlx->draw_starty = 0;
	mlx->draw_endy = mlx->spr_height / 2 + mlx->height / 2;
	if (mlx->draw_endy >= mlx->height)
		mlx->draw_endy = mlx->height - 1;
	mlx->spr_width = abs((int)(mlx->height / mlx->transformy));
	mlx->draw_startx = -mlx->spr_width / 2 + mlx->spr_screenx;
	if (mlx->draw_startx < 0)
		mlx->draw_startx = 0;
	mlx->draw_endx = mlx->spr_width / 2 + mlx->spr_screenx;
	if (mlx->draw_endx >= mlx->width)
		mlx->draw_endx = mlx->width - 1;
}

void	draw_sprite(t_mlx *mlx, t_cfg *cfg)
{
	int	hor;
	int	ver;
	
	hor = mlx->draw_startx;
	while (hor < mlx->draw_endx)
	{
		mlx->textx = (int)(256 * (hor - (-mlx->spr_width / 2 +
			mlx->spr_screenx)) * mlx->img[SP].width / mlx->spr_width) / 256;
		if (mlx->transformy > 0 && hor > 0 && hor < mlx->width
			&& mlx->transformy < mlx->buf[hor])
		{
			ver = mlx->draw_starty;
			while (ver < mlx->draw_endy)
			{
				mlx->texty = ((ver - mlx->height / 2 + mlx->spr_height / 2) *
					mlx->img[SP].height - 1) / mlx->spr_height;
				mlx->color = mlx->img[SP].img_data[mlx->img[SP].width *
					mlx->texty + mlx->textx];
				if ((mlx->color & 0xffffff) != 0)
					mlx->pixel[hor + ver * cfg->width] = mlx->color;
				ver++; 
			}
		}
		hor++;
	}
}
