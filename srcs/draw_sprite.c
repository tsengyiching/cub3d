/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 17:03:00 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/21 23:21:27 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	sort_sprite(t_cfg *cfg, t_mlx *mlx)
{
	int			i;
	int			j;
	t_sprite	tmp;
	
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

void	find_sprite(t_cfg *cfg, t_mlx *mlx)
{
	int			i;

	i = 0;
	if (!(mlx->spr = malloc(sizeof(t_sprite *) * cfg->sprite_nb)))
	{
		write(1, "Error: Memory allocation failure\n", 33);
		exit(0);
	}
	while (i < cfg->sprite_nb)
	{
		mlx->spr[i].dist = ((mlx->posx - mlx->spr[i].x) *
							(mlx->posx - mlx->spr[i].x) + 
							(mlx->posy - mlx->spr[i].y) *
							(mlx->posy - mlx->spr[i].y));
		i++;
	}
	sort_sprite(cfg, mlx);
}

void	calcul_sprite_dist(t_mlx *mlx, int i)
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

// void	draw_sprite()
// {
	
// }
