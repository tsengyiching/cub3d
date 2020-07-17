/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cub3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:07:59 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/17 15:04:54 by yictseng         ###   ########lyon.fr   */
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

int		run_cub3d(t_cub *cub)
{
	if (cub->key.forward == 1 || cub->key.back == 1)
		move_vertical(&cub->cfg, &cub->mlx, &cub->key);
	if (cub->key.left == 1 || cub->key.right == 1)
		move_horizontal(&cub->cfg, &cub->mlx, &cub->key);
	if (cub->key.leftside == 1 || cub->key.rightside == 1)
		rotate_view(&cub->mlx, &cub->key);
	if (cub->key.esc == 1)
	{
		mlx_clear_window(cub->mlx.mlx_ptr, cub->mlx.win_ptr);
		mlx_destroy_window(cub->mlx.mlx_ptr, cub->mlx.win_ptr);
		exit(0);
	}
	run_raycasting(cub);
	mlx_put_image_to_window(cub->mlx.mlx_ptr, cub->mlx.win_ptr,
							cub->mlx.new_img, 0, 0);
	return (1);
}
