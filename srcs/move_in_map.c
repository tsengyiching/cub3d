/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_in_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:54:49 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/16 19:35:44 by yictseng         ###   ########lyon.fr   */
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
		if (mlx->map[(int)(mlx->posx + mlx->vecdirx * mlx->mvspeed)]
		[(int)mlx->posy] != '1')
			mlx->posx += mlx->vecdirx * (mlx->mvspeed);
		if (mlx->map[(int)mlx->posx]
		[(int)(mlx->posy + mlx->vecdiry * mlx->mvspeed)] != '1')
			mlx->posy += mlx->vecdiry * (mlx->mvspeed);
	}
	if (mlx->key.back == 1)
	{
		if (mlx->map[(int)(mlx->posx - mlx->vecdirx * mlx->mvspeed)]
		[(int)mlx->posy] != '1')
			mlx->posx -= mlx->vecdirx * (mlx->mvspeed);
		if (mlx->map[(int)mlx->posx]
		[(int)(mlx->posy - mlx->vecdiry * mlx->mvspeed)] != '1')
			mlx->posy -= mlx->vecdiry * (mlx->mvspeed);
	}
}

void	move_horizontal(t_mlx *mlx)
{
	if (mlx->key.right == 1)
	{
		if (mlx->map[(int)(mlx->posx + mlx->planex * mlx->mvspeed)]
		[(int)mlx->posy] != '1')
			mlx->posx += mlx->planex * mlx->mvspeed;
		if (mlx->map[(int)mlx->posx]
		[(int)(mlx->posy + mlx->planey * mlx->mvspeed)] != '1')
			mlx->posy += mlx->planey * mlx->mvspeed;
	}
	if (mlx->key.left == 1)
	{
		if (mlx->map[(int)(mlx->posx - mlx->planex * mlx->mvspeed)]
		[(int)mlx->posy] != '1')
			mlx->posx -= mlx->planex * mlx->mvspeed;
		if (mlx->map[(int)mlx->posx]
		[(int)(mlx->posy - mlx->planey * mlx->mvspeed)] != '1')
			mlx->posy -= mlx->planey * mlx->mvspeed;
	}
}

void	rotate_view(t_mlx *mlx)
{
	if (mlx->key.rightside)
	{
		mlx->old_dirx = mlx->vecdirx;
		mlx->vecdirx = mlx->vecdirx * cos(-(mlx->rotspeed))
							- mlx->vecdiry * sin(-(mlx->rotspeed));
		mlx->vecdiry = mlx->old_dirx * sin(-(mlx->rotspeed))
							+ mlx->vecdiry * cos(-(mlx->rotspeed));
		mlx->old_planex = mlx->planex;
		mlx->planex = mlx->planex * cos(-(mlx->rotspeed))
						- mlx->planey * sin(-(mlx->rotspeed));
		mlx->planey = mlx->old_planex * sin(-(mlx->rotspeed))
						+ mlx->planey * cos(-(mlx->rotspeed));
	}
	if (mlx->key.leftside == 1)
	{
		mlx->old_dirx = mlx->vecdirx;
		mlx->vecdirx = mlx->vecdirx * cos(mlx->rotspeed)
							- mlx->vecdiry * sin(mlx->rotspeed);
		mlx->vecdiry = mlx->old_dirx * sin(mlx->rotspeed)
							+ mlx->vecdiry * cos(mlx->rotspeed);
		mlx->old_planex = mlx->planex;
		mlx->planex = mlx->planex * cos(mlx->rotspeed)
						- mlx->planey * sin(mlx->rotspeed);
		mlx->planey = mlx->old_planex * sin(mlx->rotspeed)
						+ mlx->planey * cos(mlx->rotspeed);
	}
}
