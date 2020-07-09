/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:35:28 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/09 22:24:22 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

init_camera_position(t_mlx *mlx)
{
	if (mlx->player_dir == 'N')
	{
		mlx->camera_x = 0;
		mlx->camera_y = 0.66;
	}
	if (mlx->player_dir == 'S')
	{
		mlx->player_dirx = 0;
		mlx->player_diry = -0.66;
	}
	if (mlx->player_dir == 'W')
	{
		mlx->player_dirx = -0.66;
		mlx->player_diry = 0;
	}
	if (mlx->player_dir == 'E')
	{
		mlx->player_dirx = 0.66;
		mlx->player_diry = 0;
	}
}

init_player_direction(t_mlx *mlx)
{
	if (mlx->player_dir == 'N')
	{
		mlx->player_dirx = -1;
		mlx->player_diry = 0;
	}
	if (mlx->player_dir == 'S')
	{
		mlx->player_dirx = 1;
		mlx->player_diry = 0;
	}
	if (mlx->player_dir == 'W')
	{
		mlx->player_dirx = 0;
		mlx->player_diry = -1;
	}
	if (mlx->player_dir == 'E')
	{
		mlx->player_dirx = 0;
		mlx->player_diry = 1;
	}
}
