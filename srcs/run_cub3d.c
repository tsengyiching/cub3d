/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cub3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:07:59 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/16 21:14:45 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		run_cub3d(t_mlx *mlx)
{
	if (mlx->key.forward == 1 || mlx->key.back == 1)
		move_vertical(mlx);
	if (mlx->key.left == 1 || mlx->key.right == 1)
		move_horizontal(mlx);
	if (mlx->key.leftside == 1 || mlx->key.rightside == 1)
		rotate_view(mlx);
	if (mlx->key.esc == 1)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(0);
	}
	run_raycasting(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->new_img, 0, 0);
	return (1);
}
