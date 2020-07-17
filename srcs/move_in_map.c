/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_in_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:54:49 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/17 15:10:06 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_vertical(t_cfg *cfg, t_mlx *mlx, t_key *key)
{
	if (key->forward == 1)
	{
		if (cfg->map[(int)(mlx->posx + mlx->vecdirx * mlx->mvspeed)]
		[(int)mlx->posy] != '1')
			mlx->posx += mlx->vecdirx * (mlx->mvspeed);
		if (cfg->map[(int)mlx->posx]
		[(int)(mlx->posy + mlx->vecdiry * mlx->mvspeed)] != '1')
			mlx->posy += mlx->vecdiry * (mlx->mvspeed);
	}
	if (key->back == 1)
	{
		if (cfg->map[(int)(mlx->posx - mlx->vecdirx * mlx->mvspeed)]
		[(int)mlx->posy] != '1')
			mlx->posx -= mlx->vecdirx * (mlx->mvspeed);
		if (cfg->map[(int)mlx->posx]
		[(int)(mlx->posy - mlx->vecdiry * mlx->mvspeed)] != '1')
			mlx->posy -= mlx->vecdiry * (mlx->mvspeed);
	}
}

void	move_horizontal(t_cfg *cfg, t_mlx *mlx, t_key *key)
{
	if (key->right == 1)
	{
		if (cfg->map[(int)(mlx->posx + mlx->planex * mlx->mvspeed)]
		[(int)mlx->posy] != '1')
			mlx->posx += mlx->planex * mlx->mvspeed;
		if (cfg->map[(int)mlx->posx]
		[(int)(mlx->posy + mlx->planey * mlx->mvspeed)] != '1')
			mlx->posy += mlx->planey * mlx->mvspeed;
	}
	if (key->left == 1)
	{
		if (cfg->map[(int)(mlx->posx - mlx->planex * mlx->mvspeed)]
		[(int)mlx->posy] != '1')
			mlx->posx -= mlx->planex * mlx->mvspeed;
		if (cfg->map[(int)mlx->posx]
		[(int)(mlx->posy - mlx->planey * mlx->mvspeed)] != '1')
			mlx->posy -= mlx->planey * mlx->mvspeed;
	}
}

void	rotate_rightside(t_mlx *mlx)
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

void	rotate_leftside(t_mlx *mlx)
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

void	rotate_view(t_mlx *mlx, t_key *key)
{
	if (key->rightside == 1)
		rotate_rightside(mlx);
	if (key->leftside == 1)
		rotate_leftside(mlx);
}
