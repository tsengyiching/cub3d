/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 13:57:22 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/22 20:49:23 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_struct(t_cfg *cfg)
{
	cfg->height = -1;
	cfg->width = -1;
	cfg->ceiling = -1;
	cfg->floor = -1;
	cfg->map_rows = 0;
	cfg->sprite_nb = 0;
	cfg->map = NULL;
	cfg->player = 0;
	cfg->start_posx = 0;
	cfg->start_posy = 0;
}

void	init_plane_position(t_cfg *cfg, t_mlx *mlx)
{
	if (cfg->start_dir == 'N')
	{
		mlx->planex = 0;
		mlx->planey = 0.66;
	}
	if (cfg->start_dir == 'S')
	{
		mlx->planex = 0;
		mlx->planey = -0.66;
	}
	if (cfg->start_dir == 'W')
	{
		mlx->planex = -0.66;
		mlx->planey = 0;
	}
	if (cfg->start_dir == 'E')
	{
		mlx->planex = 0.66;
		mlx->planey = 0;
	}
}

void	init_vector_direction(t_cfg *cfg, t_mlx *mlx)
{
	if (cfg->start_dir == 'N')
	{
		mlx->vecdirx = -1;
		mlx->vecdiry = 0;
	}
	if (cfg->start_dir == 'S')
	{
		mlx->vecdirx = 1;
		mlx->vecdiry = 0;
	}
	if (cfg->start_dir == 'W')
	{
		mlx->vecdirx = 0;
		mlx->vecdiry = -1;
	}
	if (cfg->start_dir == 'E')
	{
		mlx->vecdirx = 0;
		mlx->vecdiry = 1;
	}
}

void	init_raycasting(t_cfg *cfg, t_mlx *mlx)
{
	mlx->mvspeed = 0.05;
	mlx->rotspeed = 0.03;
	mlx->bpp = 0;
	mlx->size_line = 0;
	mlx->width = cfg->width;
	mlx->height = cfg->height;
	mlx->posx = cfg->start_posx + 0.5;
	mlx->posy = cfg->start_posy + 0.5;
	init_vector_direction(cfg, mlx);
	init_plane_position(cfg, mlx);
}
