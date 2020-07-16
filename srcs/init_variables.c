/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 13:57:22 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/16 21:10:53 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_struct(t_config *cfg, t_mlx *mlx)
{
	cfg->height = -1;
	cfg->width = -1;
	mlx->ceiling = -1;
	mlx->floor = -1;
	cfg->map_rows = 0;
	mlx->map = NULL;
	mlx->posx = 0;
	mlx->posy = 0;
}

void	init_plane_position(t_mlx *mlx)
{
	if (mlx->start_dir == 'N')
	{
		mlx->planex = 0;
		mlx->planey = 0.66;
	}
	if (mlx->start_dir == 'S')
	{
		mlx->planex = 0;
		mlx->planey = -0.66;
	}
	if (mlx->start_dir == 'W')
	{
		mlx->planex = -0.66;
		mlx->planey = 0;
	}
	if (mlx->start_dir == 'E')
	{
		mlx->planex = 0.66;
		mlx->planey = 0;
	}
}

void	init_vector_direction(t_mlx *mlx)
{
	if (mlx->start_dir == 'N')
	{
		mlx->vecdirx = -1;
		mlx->vecdiry = 0;
	}
	if (mlx->start_dir == 'S')
	{
		mlx->vecdirx = 1;
		mlx->vecdiry = 0;
	}
	if (mlx->start_dir == 'W')
	{
		mlx->vecdirx = 0;
		mlx->vecdiry = -1;
	}
	if (mlx->start_dir == 'E')
	{
		mlx->vecdirx = 0;
		mlx->vecdiry = 1;
	}
}

void	init_raycasting(t_mlx *mlx)
{
	mlx->mvspeed = 0.08;
	mlx->rotspeed = 0.03;
	mlx->bpp = 0;
	mlx->size_line = 0;
	mlx->w = mlx->width;
	mlx->h = mlx->height;
	init_vector_direction(mlx);
	init_plane_position(mlx);
}