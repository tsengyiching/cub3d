/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 13:57:22 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/15 17:05:08 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_struct(t_config *cfg, t_mlx *mlx)
{
	cfg->height = -1;
	cfg->width = -1;
	cfg->ceiling = -1;
	cfg->floor = -1;
	cfg->map_rows = 0;
	mlx->map = NULL;
	mlx->start_posx = 0;
	mlx->start_posy = 0;
	mlx->movespeed = 0.08;
	mlx->rotspeed = 0.03;
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
		mlx->vector_dirx = -1;
		mlx->vector_diry = 0;
	}
	if (mlx->start_dir == 'S')
	{
		mlx->vector_dirx = 1;
		mlx->vector_diry = 0;
	}
	if (mlx->start_dir == 'W')
	{
		mlx->vector_dirx = 0;
		mlx->vector_diry = -1;
	}
	if (mlx->start_dir == 'E')
	{
		mlx->vector_dirx = 0;
		mlx->vector_diry = 1;
	}
}
