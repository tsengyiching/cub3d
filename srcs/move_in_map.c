/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_in_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:54:49 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/15 17:55:26 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		press_key(int key, t_mlx *mlx)
{
	if (key == KEY_W)
		mlx->key.forward = 1;
	if (key == KEY_S)
		mlx->key.back = 1;
	if (key == KEY_A)
		mlx->key.left = 1;
	if (key == KEY_D)
		mlx->key.right = 1;
	if (key == KEY_ARROW_LEFT)
		mlx->key.leftside = 1;
	if (key == KEY_ARROW_RIGHT)
		mlx->key.rightside = 1;
	if (key == KEY_ESC)
		mlx->key.esc = 1;
	return (0);
}

int		release_key(int key, t_mlx *mlx)
{
	if (key == KEY_W)
		mlx->key.forward = 0;
	if (key == KEY_S)
		mlx->key.back = 0;
	if (key == KEY_A)
		mlx->key.left = 0;
	if (key == KEY_D)
		mlx->key.right = 0;
	if (key == KEY_ARROW_LEFT)
		mlx->key.leftside = 0;
	if (key == KEY_ARROW_RIGHT)
		mlx->key.rightside = 0;
	if (key == KEY_ESC)
		mlx->key.esc = 0;
	return (0);
}

void	move_vertical(t_mlx *mlx)
{
	if (mlx->key.forward == 1)
	{
		if (mlx->map[(int)(mlx->start_posx + mlx->vector_dirx * mlx->movespeed)]
			[(int)mlx->start_posy] != '1')
			mlx->start_posx += mlx->vector_dirx * mlx->movespeed;
		if (mlx->map[(int)mlx->start_posx]
			[(int)(mlx->start_posy + mlx->vector_diry * mlx->movespeed)] != '1')
			mlx->start_posy += mlx->vector_diry * mlx->movespeed;
	}
	if (mlx->key.back == 1)
	{
		if (mlx->map[(int)(mlx->start_posx - mlx->vector_dirx * mlx->movespeed)]
			[(int)mlx->start_posy] != '1')
			mlx->start_posx -= mlx->vector_dirx * mlx->movespeed;
		if (mlx->map[(int)mlx->start_posx]
			[(int)(mlx->start_posy - mlx->vector_diry * mlx->movespeed)] != '1')
			mlx->start_posy -= mlx->vector_diry * mlx->movespeed;
	}
}

void	move_horizontal(t_mlx *mlx)
{
	if (mlx->key.left == 1)
	{
		if (mlx->map[(int)(mlx->start_posx + mlx->planex * mlx->movespeed)]
			[(int)mlx->start_posy] != '1')
			mlx->start_posx += mlx->planex * mlx->movespeed;
		if (mlx->map[(int)mlx->start_posx]
			[(int)(mlx->start_posy + mlx->planey * mlx->movespeed)] != '1')
			mlx->start_posy += mlx->planey * mlx->movespeed;
	}
	if (mlx->key.right == 1)
	{
		if (mlx->map[(int)(mlx->start_posx - mlx->planex * mlx->movespeed)]
			[(int)mlx->start_posy] != '1')
			mlx->start_posx -= mlx->planex * mlx->movespeed;
		if (mlx->map[(int)mlx->start_posx]
			[(int)(mlx->start_posy - mlx->planey * mlx->movespeed)] != '1')
			mlx->start_posy -= mlx->planey * mlx->movespeed;
	}
}

void	rotate_view(t_mlx *mlx)
{
	if (mlx->key.leftside == 1)
	{
		mlx->old_dirx = mlx->vector_dirx;
		mlx->vector_dirx = mlx->vector_dirx * cos(mlx->rotspeed)
							- mlx->vector_diry * sin(mlx->rotspeed);
		mlx->vector_diry = mlx->old_dirx * sin(mlx->rotspeed)
							+ mlx->vector_diry * cos(mlx->rotspeed);
		mlx->old_planex = mlx->planex;
		mlx->planex = mlx->planex * cos(mlx->rotspeed)
						- mlx->planey * sin(mlx->rotspeed);
		mlx->planey = mlx->old_planex * sin(mlx->rotspeed)
						- mlx->planey * cos(mlx->rotspeed);
	}
	if (mlx->key.rightside)
	{
		mlx->old_dirx = mlx->vector_dirx;
		mlx->vector_dirx = mlx->vector_dirx * cos(-(mlx->rotspeed))
							- mlx->vector_diry * sin(-(mlx->rotspeed));
		mlx->vector_diry = mlx->old_dirx * sin(-(mlx->rotspeed))
							+ mlx->vector_diry * cos(-(mlx->rotspeed));
		mlx->old_planex = mlx->planex;
		mlx->planex = mlx->planex * cos(-(mlx->rotspeed))
						- mlx->planey * sin(-(mlx->rotspeed));
		mlx->planey = mlx->old_planex * sin(-(mlx->rotspeed))
						- mlx->planey * cos(-(mlx->rotspeed));
	}
}