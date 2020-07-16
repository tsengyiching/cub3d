/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:06:28 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/16 19:20:24 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_map_elem(t_config *cfg, t_mlx *mlx)
{
	int x;
	int	y;

	x = 0;
	while (mlx->map[x])
	{
		y = 0;
		while (mlx->map[x][y])
		{
			if (!is_valid_elem(mlx->map, x, y))
				return (0);
			if (mlx->map[x][y] == 'N' || mlx->map[x][y] == 'S'
			|| mlx->map[x][y] == 'W' || mlx->map[x][y] == 'E')
			{
				cfg->player++;
				mlx->start_dir = mlx->map[x][y];
				mlx->posx = x + 0.5;
				mlx->posy = y + 0.5;
			}
			y++;
		}
		x++;
	}
	cfg->map_rows = x - 1;
	return (1);
}

int		check_horizotal_left(int x, int y, t_mlx *mlx)
{
	while (y > 0 && mlx->map[x][y] != '1' && mlx->map[x][y] != ' ')
		y--;
	if (mlx->map[x][y] != '1')
		return (0);
	return (1);
}

int		check_horizotal_right(int x, int y, t_mlx *mlx)
{
	while (y > 0 && mlx->map[x][y] != '1' && mlx->map[x][y] != ' ')
		y++;
	if (mlx->map[x][y] != '1')
		return (0);
	return (1);
}

int		check_vertical_up(int x, int y, t_mlx *mlx)
{
	while (x > 0 && mlx->map[x][y] != '1' && mlx->map[x][y] != ' ')
		x--;
	if (mlx->map[x][y] != '1')
		return (0);
	return (1);
}

int		check_vertical_down(int x, int y, t_config *cfg, t_mlx *mlx)
{
	while (x < cfg->map_rows && mlx->map[x][y] != '1' && mlx->map[x][y] != ' '
		&& mlx->map[x][y] != '\0')
		x++;
	if (mlx->map[x][y] != '1')
		return (0);
	return (1);
}

int		check_wall(int x, int y, t_config *cfg, t_mlx *mlx)
{
	if (!check_horizotal_left(x, y, mlx))
		return (-18);
	if (!check_horizotal_right(x, y, mlx))
		return (-19);
	if (!check_vertical_up(x, y, mlx))
		return (-20);
	if (!check_vertical_down(x, y, cfg, mlx))
		return (-21);
	return (1);
}

int		is_valid_map(t_config *cfg, t_mlx *mlx)
{
	int		x;
	int		y;
	int		error_code;

	x = 0;
	error_code = 0;
	while (mlx->map[x])
	{
		y = 0;
		while (mlx->map[x][y])
		{
			if (mlx->map[x][y] == '0' || mlx->map[x][y] == '2'
				|| mlx->map[x][y] == mlx->start_dir)
			{
				if ((error_code = check_wall(x, y, cfg, mlx)) < 0)
					return (error_code);
			}
			y++;
		}
		x++;
	}
	return (1);
}

int		check_map(t_config *cfg, t_mlx *mlx)
{
	int		error_code;

	error_code = 0;
	if (!check_map_elem(cfg, mlx))
		return (-16);
	if (cfg->player != 1)
		return (-17);
	if ((error_code = is_valid_map(cfg, mlx)) < 0)
		return (error_code);
	mlx->width = cfg->width;
	mlx->height = cfg->height;
	return (1);
}
