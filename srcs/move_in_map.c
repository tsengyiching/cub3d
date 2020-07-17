/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_in_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:54:49 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/17 12:34:04 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		press_key(int keyboard, t_key *key)
{
	if (keyboard == KEY_W)
		key->forward = 1;
	if (keyboard == KEY_S)
		key->back = 1;
	if (keyboard == KEY_A)
		key->left = 1;
	if (keyboard == KEY_D)
		key->right = 1;
	if (keyboard == KEY_ARROW_LEFT)
		key->leftside = 1;
	if (keyboard == KEY_ARROW_RIGHT)
		key->rightside = 1;
	if (keyboard == KEY_ESC)
		key->esc = 1;
	return (0);
}

int		release_key(int keyboard, t_key *key)
{
	if (keyboard == KEY_W)
		key->forward = 0;
	if (keyboard == KEY_S)
		key->back = 0;
	if (keyboard == KEY_A)
		key->left = 0;
	if (keyboard == KEY_D)
		key->right = 0;
	if (keyboard == KEY_ARROW_LEFT)
		key->leftside = 0;
	if (keyboard == KEY_ARROW_RIGHT)
		key->rightside = 0;
	if (keyboard == KEY_ESC)
		key->esc = 0;
	return (0);
}

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

void	rotate_view(t_mlx *mlx, t_key *key)
{
	if (key->rightside)
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
	if (key->leftside == 1)
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
