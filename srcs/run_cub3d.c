/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cub3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:07:59 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/15 14:25:09 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		run_cub3d(t_config *cfg, t_mlx *mlx)
{
	init_vector_direction(mlx);
	init_plane_position(mlx);
	run_raycasting(mlx, cfg);
	return (1);
}
