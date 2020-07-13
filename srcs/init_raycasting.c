/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:35:28 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/13 15:58:27 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
